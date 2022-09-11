/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:15:48 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 19:08:33 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_imgs1(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "ground", "./assets/sprites/ground.xpm");
	sl_add_imgs(ctx, "wall", "./assets/sprites/wall.xpm");
	sl_add_imgs(ctx, "coll_1", "./assets/sprites/popcorn.xpm");
	sl_add_imgs(ctx, "coll_2", "./assets/sprites/popcorn2.xpm");
	sl_add_imgs(ctx, "coll_3", "./assets/sprites/popcorn3.xpm");
	sl_add_imgs(ctx, "exit_closed_1", "./assets/sprites/exit_closed1.xpm");
	sl_add_imgs(ctx, "exit_closed_2", "./assets/sprites/exit_closed2.xpm");
	sl_add_imgs(ctx, "exit_closed_3", "./assets/sprites/exit_closed3.xpm");
	sl_add_imgs(ctx, "exit_closed_4", "./assets/sprites/exit_closed4.xpm");
	sl_add_imgs(ctx, "exit_open_1", "./assets/sprites/exit_open1.xpm");
	sl_add_imgs(ctx, "exit_open_2", "./assets/sprites/exit_open2.xpm");
	sl_add_imgs(ctx, "exit_open_3", "./assets/sprites/exit_open3.xpm");
	sl_add_imgs(ctx, "exit_open_4", "./assets/sprites/exit_open4.xpm");
}

static void	sl_load_imgs2(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "move_up", "./assets/sprites/move_up.xpm");
	sl_add_imgs(ctx, "move_down", "./assets/sprites/move_down.xpm");
	sl_add_imgs(ctx, "move_left", "./assets/sprites/move_left.xpm");
	sl_add_imgs(ctx, "move_right", "./assets/sprites/move_right.xpm");
}

static void	sl_load_imgs3(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "plyr_idle_left_1", "./assets/sprites/cat_s_left.xpm");
	sl_add_imgs(ctx, "plyr_idle_left_2", "./assets/sprites/cat_s_left2.xpm");
	sl_add_imgs(ctx, "plyr_idle_right_1", "./assets/sprites/cat_s_right.xpm");
	sl_add_imgs(ctx, "plyr_idle_right_2", "./assets/sprites/cat_s_right2.xpm");
	sl_add_imgs(ctx, "plyr_walk_left_1", "./assets/sprites/cat_w_left1.xpm");
	sl_add_imgs(ctx, "plyr_walk_left_2", "./assets/sprites/cat_w_left2.xpm");
	sl_add_imgs(ctx, "plyr_walk_right_1", "./assets/sprites/cat_w_right1.xpm");
	sl_add_imgs(ctx, "plyr_walk_right_2", "./assets/sprites/cat_w_right2.xpm");
	sl_add_imgs(ctx, "enem_idle_left_1", "./assets/sprites/ene_s_left.xpm");
	sl_add_imgs(ctx, "enem_idle_left_2", "./assets/sprites/ene_s_left2.xpm");
	sl_add_imgs(ctx, "enem_idle_right_1", "./assets/sprites/ene_s_right.xpm");
	sl_add_imgs(ctx, "enem_idle_right_2", "./assets/sprites/ene_s_right2.xpm");
	sl_add_imgs(ctx, "enem_walk_left_1", "./assets/sprites/ene_w_left1.xpm");
	sl_add_imgs(ctx, "enem_walk_left_2", "./assets/sprites/ene_w_left2.xpm");
	sl_add_imgs(ctx, "enem_walk_right_1", "./assets/sprites/ene_w_right1.xpm");
	sl_add_imgs(ctx, "enem_walk_right_2", "./assets/sprites/ene_w_right2.xpm");
}

void	sl_load_imgs(t_sl_context *ctx)
{
	ctx->imgs = NULL;
	sl_load_imgs1(ctx);
	sl_load_imgs2(ctx);
	sl_load_imgs3(ctx);
}
