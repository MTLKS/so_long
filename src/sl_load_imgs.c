/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:15:48 by maliew            #+#    #+#             */
/*   Updated: 2022/08/31 17:24:58 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_background_imgs(t_sl_imgs *imgs, void *mlx)
{
	imgs->ground = sl_xpm_to_img(mlx, "./assets/sprites/ground.xpm");
	imgs->wall = sl_xpm_to_img(mlx, "./assets/sprites/wall.xpm");
}

static void	sl_load_coll_imgs(t_sl_imgs *imgs, void *mlx)
{
	imgs->coll_1 = sl_xpm_to_img(mlx, "./assets/sprites/popcorn.xpm");
	imgs->coll_2 = sl_xpm_to_img(mlx, "./assets/sprites/popcorn2.xpm");
}

static void	sl_load_player_imgs(t_sl_imgs *imgs, void *mlx)
{
	imgs->plyr_idle_left_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_left.xpm");
	imgs->plyr_idle_left_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_left2.xpm");
	imgs->plyr_idle_right_1 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_right.xpm");
	imgs->plyr_idle_right_2 = sl_xpm_to_img(mlx,
			"./assets/sprites/cat_s_right2.xpm");
}

static void	sl_load_ui_imgs(t_sl_imgs *imgs, void *mlx)
{
	imgs->move_up = sl_xpm_to_img(mlx, "./assets/sprites/up.xpm");
	imgs->move_down = sl_xpm_to_img(mlx, "./assets/sprites/down.xpm");
	imgs->move_left = sl_xpm_to_img(mlx, "./assets/sprites/left.xpm");
	imgs->move_right = sl_xpm_to_img(mlx, "./assets/sprites/right.xpm");
}

void	sl_load_imgs(t_sl_context *ctx)
{
	ctx->imgs = (t_sl_imgs *)malloc(sizeof(t_sl_imgs));
	sl_load_player_imgs(ctx->imgs, ctx->mlx);
	sl_load_coll_imgs(ctx->imgs, ctx->mlx);
	sl_load_background_imgs(ctx->imgs, ctx->mlx);
	sl_load_ui_imgs(ctx->imgs, ctx->mlx);
}
