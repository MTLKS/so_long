/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:50 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 15:15:04 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_imgs_free1(t_sl_imgs *imgs, void *mlx)
{
	if (imgs->plyr_idle_left_1)
		sl_img_free(imgs->plyr_idle_left_1, mlx);
	if (imgs->plyr_idle_left_2)
		sl_img_free(imgs->plyr_idle_left_2, mlx);
	if (imgs->plyr_idle_right_1)
		sl_img_free(imgs->plyr_idle_right_1, mlx);
	if (imgs->plyr_idle_right_2)
		sl_img_free(imgs->plyr_idle_right_2, mlx);
	if (imgs->plyr_walk_left_1)
		sl_img_free(imgs->plyr_walk_left_1, mlx);
	if (imgs->plyr_walk_left_2)
		sl_img_free(imgs->plyr_walk_left_2, mlx);
	if (imgs->plyr_walk_right_1)
		sl_img_free(imgs->plyr_walk_right_1, mlx);
	if (imgs->plyr_walk_right_2)
		sl_img_free(imgs->plyr_walk_right_2, mlx);
}

void	sl_imgs_free(t_sl_imgs *imgs, void *mlx)
{
	sl_imgs_free1(imgs, mlx);
}
