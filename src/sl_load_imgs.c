/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:15:48 by maliew            #+#    #+#             */
/*   Updated: 2022/09/02 01:06:13 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_imgs1(t_sl_imgs *imgs, void *mlx)
{
	imgs->ground = sl_xpm_to_img(mlx, "./assets/sprites/ground.xpm");
	imgs->wall = sl_xpm_to_img(mlx, "./assets/sprites/wall.xpm");
	imgs->coll_1 = sl_xpm_to_img(mlx, "./assets/sprites/popcorn.xpm");
	imgs->coll_2 = sl_xpm_to_img(mlx, "./assets/sprites/popcorn2.xpm");
	imgs->exit_closed_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/exit_closed1.xpm");
	imgs->exit_closed_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/exit_closed2.xpm");
	imgs->exit_closed_3 = sl_xpm_to_img(mlx,
			"./assets/sprites/exit_closed3.xpm");
	imgs->exit_closed_4 = sl_xpm_to_img(mlx,
			"./assets/sprites/exit_closed4.xpm");
	imgs->exit_open_1 = sl_xpm_to_img(mlx, "./assets/sprites/exit_open1.xpm");
}

static void	sl_load_imgs2(t_sl_imgs *imgs, void *mlx)
{
	imgs->move_up = sl_xpm_to_img(mlx, "./assets/sprites/up.xpm");
	imgs->move_down = sl_xpm_to_img(mlx, "./assets/sprites/down.xpm");
	imgs->move_left = sl_xpm_to_img(mlx, "./assets/sprites/left.xpm");
	imgs->move_right = sl_xpm_to_img(mlx, "./assets/sprites/right.xpm");
}

static void	sl_load_imgs3(t_sl_imgs *imgs, void *mlx)
{
	imgs->plyr_idle_left_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_left.xpm");
	imgs->plyr_idle_left_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_left2.xpm");
	imgs->plyr_idle_right_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_right.xpm");
	imgs->plyr_idle_right_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_right2.xpm");
	imgs->plyr_walk_left_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_w_left1.xpm");
	imgs->plyr_walk_left_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_w_left2.xpm");
	imgs->plyr_walk_right_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_w_right1.xpm");
	imgs->plyr_walk_right_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_w_right2.xpm");
}

void	sl_load_imgs(t_sl_context *ctx)
{
	ctx->imgs = (t_sl_imgs *)malloc(sizeof(t_sl_imgs));
	sl_load_imgs1(ctx->imgs, ctx->mlx);
	sl_load_imgs2(ctx->imgs, ctx->mlx);
	sl_load_imgs3(ctx->imgs, ctx->mlx);
}
