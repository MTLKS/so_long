/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:10 by maliew            #+#    #+#             */
/*   Updated: 2022/08/27 01:31:28 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_enemy	*sl_enemy_init(void)
{
	t_sl_enemy	*enemy;

	enemy = (t_sl_enemy *)malloc(sizeof(t_sl_enemy));
	enemy->idle_left = sl_anim_init();
	enemy->idle_right = sl_anim_init();
	enemy->walk_left = sl_anim_init();
	enemy->walk_right = sl_anim_init();
	enemy->coords = NULL;
	return (enemy);
}

void	sl_enemy_add_coords(t_sl_enemy *enemy, int x, int y, int dir)
{
	int	*arr;

	arr = (int *)malloc(3 * sizeof(int));
	arr[0] = x;
	arr[1] = y;
	arr[2] = dir;
	ft_lstadd_back(&enemy->coords, ft_lstnew(arr));
}
