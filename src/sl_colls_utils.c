/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_colls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:26:44 by maliew            #+#    #+#             */
/*   Updated: 2022/08/20 19:39:04 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_coll	*sl_init_coll(void)
{
	t_sl_coll	*coll;

	coll = (t_sl_coll *)malloc(sizeof(t_sl_coll));
	coll->anim = sl_init_anim(0);
	coll->coords = NULL;
	return (coll);
}

void	sl_add_coll_coords(t_sl_coll *colls, int x, int y)
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	arr[0] = x;
	arr[1] = y;
	ft_lstadd_back(&colls->coords, ft_lstnew(arr));
}
