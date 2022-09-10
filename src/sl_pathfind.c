/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:31:09 by maliew            #+#    #+#             */
/*   Updated: 2022/09/10 19:35:25 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_astar_node	*sl_astar_new(int x, int y, int g_cost, int total_cost)
{
	t_sl_astar_node	*node;

	node = (t_sl_astar_node *)malloc(sizeof(t_sl_astar_node));
	node->x = x;
	node->y = y;
	node->g_cost = g_cost;
	node->total_cost = total_cost;
	node->last_move = -1;
	return (node);
}

t_sl_astar_node	*sl_astar_pop(t_list **queue)
{
	t_list			*temp;
	t_sl_astar_node	*node;

	node = (*queue)->content;
	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
	return (node);
}

int	sl_pf_loop(t_sl_context *ctx, t_sl_pathfind *pf,
	t_list **open, t_list **closed)
{
	t_sl_astar_node	*curr_node;

	curr_node = sl_astar_pop(open);
}

t_list	*sl_pathfind(t_sl_context *ctx, t_sl_pathfind *pf)
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
}
