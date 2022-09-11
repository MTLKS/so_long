/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:31:09 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 17:56:16 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_astar_node	*sl_astar_new(int x, int y, int g_cost, int h_cost)
{
	t_sl_astar_node	*node;

	node = (t_sl_astar_node *)malloc(sizeof(t_sl_astar_node));
	node->x = x;
	node->y = y;
	node->g_cost = g_cost;
	node->h_cost = h_cost;
	node->last_move = -1;
	node->prev_node = NULL;
	return (node);
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
	t_sl_astar_node	*curr_node;
	t_sl_astar_node	*new_node;
	int				*n;
	int				i;

	curr_node = sl_astar_pop(open);
	if (!curr_node)
		return (-1);
	if (curr_node->x == pf->ex && curr_node->y == pf->ey)
	{
		ft_lstadd_back(closed, ft_lstnew(curr_node));
		return (1);
	}
	n = sl_astar_get_neighbours(curr_node->x, curr_node->y);
	i = 0;
	while (i < 8)
	{
		if (!sl_is_wall(ctx, n[i] * SPRITE_SIZE, n[i + 1] * SPRITE_SIZE)
			&& !sl_astar_get_node(*closed, n[i], n[i + 1]))
		{
			new_node = sl_astar_get_node(*open, n[i], n[i + 1]);
			if (new_node && new_node->g_cost > curr_node->g_cost + 1)
			{
				new_node->g_cost = curr_node->g_cost + 1;
				new_node->h_cost = sl_astar_h_cost(n[i], n[i + 1],
						pf->ex, pf->ey);
				new_node->last_move = i / 2;
				new_node->prev_node = curr_node;
			}
			else
			{
				new_node = sl_astar_new(n[i], n[i + 1], curr_node->g_cost + 1,
						sl_astar_h_cost(n[i], n[i + 1], pf->ex, pf->ey));
				new_node->last_move = i / 2;
				new_node->prev_node = curr_node;
				ft_lstadd_back(open, ft_lstnew(new_node));
			}
			sl_astar_sort_queue(*open);
		}
		i = i + 2;
	}
	free(n);
	ft_lstadd_back(closed, ft_lstnew(curr_node));
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
