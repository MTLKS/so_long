/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/31 17:22:58 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	sl_key_hook(int keycode, t_sl_player *player)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		ft_lstadd_back(&(player->move_list), ft_lstnew(sl_move_new(MOVE_UP)));
	else if (keycode == KEY_A)
		ft_lstadd_back(&(player->move_list), ft_lstnew(sl_move_new(MOVE_LEFT)));
	else if (keycode == KEY_S)
		ft_lstadd_back(&(player->move_list), ft_lstnew(sl_move_new(MOVE_DOWN)));
	else if (keycode == KEY_D)
		ft_lstadd_back(&(player->move_list),
			ft_lstnew(sl_move_new(MOVE_RIGHT)));
	if (keycode == KEY_A && player->dir == 1)
		player->dir = 0;
	else if (keycode == KEY_D && player->dir == 0)
		player->dir = 1;
	return (0);
}

int	sl_render(t_sl_context *c)
{
	static int	i = 0;
	t_sl_img	*buffer;

	if (i > LOOPS_PER_TICK)
	{
		i = 0;
		buffer = sl_new_img(c->mlx, SCREEN_W, SCREEN_H);
		sl_copy_image(buffer, c->map->img,
			(SCREEN_W - SPRITE_SIZE) / 2 - c->player->x,
			(SCREEN_H - SPRITE_SIZE) / 2 - c->player->y);
		sl_coll_copy_all(buffer, c);
		sl_ui_display_moves(c, buffer);
		sl_move_player(c->player);
		sl_copy_image(buffer, sl_player_get_anim(c->player),
			(SCREEN_W - SPRITE_SIZE) / 2, (SCREEN_H - SPRITE_SIZE) / 2);
		mlx_put_image_to_window(c->mlx, c->win, buffer->img, 0, 0);
		mlx_destroy_image(c->mlx, buffer->img);
		free(buffer);
		sl_print_context(c);
	}
	i++;
	return (0);
}

int	sl_close(t_sl_context *context)
{
	mlx_destroy_window(context->mlx, context->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sl_context	*ctx;

	if (argc != 2)
		return (0);
	ft_printf("Hello World!\n");
	ctx = sl_context_init();
	// ctx = (t_sl_context *)malloc(sizeof(t_sl_context));
	// ctx->mlx = mlx_init();
	// ctx->win = mlx_new_window(ctx->mlx, SCREEN_W, SCREEN_H, "so_long");
	sl_load_imgs(ctx);
	// ctx->player = sl_player_init();
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_2);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_2);
	// ctx->scene = sl_new_img(ctx->mlx, SCREEN_W, SCREEN_H);
	// ctx->colls = sl_coll_init();
	sl_anim_add_frame(ctx->colls->anim, ctx->imgs->coll_1);
	sl_anim_add_frame(ctx->colls->anim, ctx->imgs->coll_2);
	sl_parse_map(ctx, argv[1]);
	mlx_loop_hook(ctx->mlx, sl_render, ctx);
	mlx_key_hook(ctx->win, sl_key_hook, ctx->player);
	mlx_hook(ctx->win, ON_DESTROY, 0L, sl_close, ctx);
	mlx_loop(ctx->mlx);
}
