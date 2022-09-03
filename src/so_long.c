/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/09/03 17:38:05 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	sl_key_hook(int keycode, t_sl_context *ctx)
{
	if (keycode == KEY_ESC)
		sl_close();
	else if (keycode == KEY_W)
		ft_lstadd_back(&(ctx->player->move_list),
			ft_lstnew(sl_move_new(MOVE_UP)));
	else if (keycode == KEY_A)
		ft_lstadd_back(&(ctx->player->move_list),
			ft_lstnew(sl_move_new(MOVE_LEFT)));
	else if (keycode == KEY_S)
		ft_lstadd_back(&(ctx->player->move_list),
			ft_lstnew(sl_move_new(MOVE_DOWN)));
	else if (keycode == KEY_D)
		ft_lstadd_back(&(ctx->player->move_list),
			ft_lstnew(sl_move_new(MOVE_RIGHT)));
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
		sl_move_player(c);
		sl_coll_check(c);
		sl_copy_image(buffer, c->map->img,
			(SCREEN_W - SPRITE_SIZE) / 2 - c->player->x,
			(SCREEN_H - SPRITE_SIZE) / 2 - c->player->y);
		sl_coll_copy_all(buffer, c);
		sl_exit_copy_all(buffer, c);
		sl_copy_image(buffer, sl_player_get_anim(c->player),
			(SCREEN_W - SPRITE_SIZE) / 2, (SCREEN_H - SPRITE_SIZE) / 2);
		sl_ui_display_moves(c, buffer);
		mlx_put_image_to_window(c->mlx, c->win, buffer->img, 0, 0);
		mlx_destroy_image(c->mlx, buffer->img);
		free(buffer);
		sl_print_context(c);
		sl_exit_check(c);
	}
	i++;
	return (0);
}

int	sl_close(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sl_context	*ctx;

	if (argc != 2)
		return (0);
	ft_printf("Hello World!\n");
	ctx = sl_context_init();
	sl_load_imgs(ctx);
	sl_load_anims(ctx);
	sl_parse_map(ctx, argv[1]);
	mlx_loop_hook(ctx->mlx, sl_render, ctx);
	mlx_key_hook(ctx->win, sl_key_hook, ctx);
	mlx_hook(ctx->win, ON_DESTROY, 0L, sl_close, NULL);
	mlx_loop(ctx->mlx);
}
