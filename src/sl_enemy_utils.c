/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:10 by maliew            #+#    #+#             */
/*   Updated: 2022/09/08 01:53:37 by maliew           ###   ########.fr       */
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

void	sl_enemy_free(t_sl_enemy *enemy)
{
	sl_anim_free(enemy->idle_left);
	sl_anim_free(enemy->idle_right);
	sl_anim_free(enemy->walk_left);
	sl_anim_free(enemy->walk_right);
	ft_lstclear(&enemy->coords, &sl_free_content);
	free(enemy);
}
