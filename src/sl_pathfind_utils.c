/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathfind_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:08:34 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 17:56:56 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*sl_astar_get_neighbours(int x, int y)
{
	int	*res;

	res = (int *)malloc(8 * sizeof(int));
	res[0] = x;
	res[1] = y - 1;
	res[2] = x;
	res[3] = y + 1;
	res[4] = x - 1;
	res[5] = y;
	res[6] = x + 1;
	res[7] = y;
	return (res);
}

t_sl_astar_node	*sl_astar_get_node(t_list *queue, int x, int y)
{
	while (queue)
	{
		if (((t_sl_astar_node *)(queue->content))->x == x
				&& ((t_sl_astar_node *)(queue->content))->y == y)
			return (queue->content);
		queue = queue->next;
	}
	return (NULL);
}

void	sl_astar_swap(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

int	sl_astar_compare(t_sl_astar_node *curr, t_sl_astar_node *next)
{
	return (curr->g_cost + curr->h_cost > next->g_cost + next->h_cost);
}

void	sl_astar_sort_queue(t_list *queue)
{
	int		swapped;
	t_list	*ptr1;
	t_list	*lptr;

	if (queue == NULL)
		return ;
	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = queue;
		while (ptr1->next != lptr)
		{
			if (sl_astar_compare(ptr1->content, ptr1->next->content))
			{
				sl_astar_swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}
