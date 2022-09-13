/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:31:09 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 05:21:34 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_pf_iter_neighbour(t_sl_pathfind *pf, t_list **open,
	t_sl_astar_node *curr, int i)
{
	t_sl_astar_node	*new;

	new = sl_astar_get_node(*open, curr->n[i], curr->n[i + 1]);
	if (new && new->g_cost > curr->g_cost + 1)
	{
		new->g_cost = curr->g_cost + 1;
		new->h_cost = sl_astar_h_cost(curr->n[i], curr->n[i + 1],
				pf->ex, pf->ey);
		new->last_move = i / 2;
		new->prev_node = curr;
	}
	else
	{
		new = sl_astar_new(curr->n[i], curr->n[i + 1],
				curr->g_cost + 1,
				sl_astar_h_cost(curr->n[i], curr->n[i + 1],
					pf->ex, pf->ey));
		new->last_move = i / 2;
		new->prev_node = curr;
		ft_lstadd_back(open, ft_lstnew(new));
	}
	sl_astar_sort_queue(*open);
}

t_sl_astar_node	*sl_astar_pop(t_list **queue)
{
	t_list			*temp;
	t_sl_astar_node	*node;

	if (!*queue)
		return (NULL);
	node = (*queue)->content;
	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
	return (node);
}

t_list	*sl_pf_get_moves(t_sl_pathfind *pf, t_list *closed)
{
	t_sl_astar_node	*node;
	t_list			*moves;

	moves = NULL;
	node = sl_astar_get_node(closed, pf->ex, pf->ey);
	while (node && !(node->x == pf->sx && node->y == pf->sy))
	{
		ft_lstadd_front(&moves, ft_lstnew(sl_move_new(node->last_move)));
		node = node->prev_node;
	}
	return (moves);
}

int	sl_pf_loop(t_sl_context *ctx, t_sl_pathfind *pf,
	t_list **open, t_list **closed)
{
	t_sl_astar_node	*curr;
	int				i;

	curr = sl_astar_pop(open);
	if (!curr)
		return (-1);
	if (curr->x == pf->ex && curr->y == pf->ey)
	{
		ft_lstadd_back(closed, ft_lstnew(curr));
		return (1);
	}
	curr->n = sl_astar_get_neighbours(curr->x, curr->y);
	i = 0;
	while (i < 8)
	{
		if (!sl_is_wall(ctx, curr->n[i] * SPRITE_SIZE,
				curr->n[i + 1] * SPRITE_SIZE)
			&& !sl_astar_get_node(*closed, curr->n[i],
				curr->n[i + 1]))
			sl_pf_iter_neighbour(pf, open, curr, i);
		i = i + 2;
	}
	free(curr->n);
	ft_lstadd_back(closed, ft_lstnew(curr));
	return (0);
}

void	sl_pathfind(t_sl_context *ctx, t_sl_pathfind *pf)
{
	t_list	*open;
	t_list	*closed;
	int		ret;

	open = ft_lstnew(sl_astar_new(pf->sx, pf->sy, 0,
				sl_astar_h_cost(pf->sx, pf->sy, pf->ex, pf->ey)));
	closed = NULL;
	ret = 0;
	while (!ret)
		ret = sl_pf_loop(ctx, pf, &open, &closed);
	if (ret == 1)
		pf->moves = sl_pf_get_moves(pf, closed);
	ft_lstclear(&open, &sl_free_content);
	ft_lstclear(&closed, &sl_free_content);
}
