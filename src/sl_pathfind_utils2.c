/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathfind_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:53:08 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 22:06:24 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_astar_h_cost(int x, int y, int ex, int ey)
{
	return (sl_abs(x - ex) + sl_abs(y - ey));
}

t_sl_pathfind	*sl_pf_new(int sx, int sy, int ex, int ey)
{
	t_sl_pathfind	*pf;

	pf = (t_sl_pathfind *)malloc(sizeof(t_sl_pathfind));
	pf->sx = sx;
	pf->sy = sy;
	pf->ex = ex;
	pf->ey = ey;
	pf->moves = NULL;
	return (pf);
}
