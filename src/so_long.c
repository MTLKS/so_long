/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 01:02:59 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	sl_key_hook(int keycode, t_sl_context *ctx)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("ESC pressed.\n");
		sl_close(ctx);
	}
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

	if (++i % LOOPS_PER_TICK == 0)
	{
		buffer = sl_new_img(c->mlx, SCREEN_W, SCREEN_H);
		sl_move_player(c);
		if (c->enemy->x)
			sl_move_enemy(c);
		sl_coll_check(c);
		sl_map_copy_image(buffer, c);
		sl_coll_copy_all(buffer, c);
		sl_exit_copy_all(buffer, c);
		sl_enemy_copy_image(buffer, c);
		sl_player_copy_image(buffer, c);
		sl_ui_display_moves(buffer, c);
		sl_ui_print_count(buffer, c);
		mlx_put_image_to_window(c->mlx, c->win, buffer->img, 0, 0);
		mlx_destroy_image(c->mlx, buffer->img);
		free(buffer);
		sl_enemy_check(c);
		sl_exit_check(c);
	}
	return (0);
}

int	sl_close(t_sl_context *ctx)
{
	sl_context_free(ctx);
	ft_printf("Exiting so_long...\n");
	exit(0);
}

void	sl_pf_print(void *content)
{
	ft_printf("%d, ", *(int *)content);
}

int	main(int argc, char **argv)
{
	t_sl_context	*ctx;

	if (argc != 2)
	{
		ft_printf("Wrong number of arguments.\n./so_long <map.ber>\n");
		return (0);
	}
	ft_printf("Starting so_long...\n");
	ctx = sl_context_init();
	ft_printf("Loading map...\t\t");
	sl_parse_map(ctx, argv[1]);
	ft_printf("OK\nLoading images...\t");
	sl_load_imgs(ctx);
	sl_loop_map(ctx, &sl_parse_map_image);
	ft_printf("OK\nLoading animations...\t");
	sl_load_anims(ctx);
	ft_printf("OK\nStarting game...\n");
	ctx->win = mlx_new_window(ctx->mlx, SCREEN_W, SCREEN_H, "so_long");
	mlx_loop_hook(ctx->mlx, sl_render, ctx);
	mlx_key_hook(ctx->win, sl_key_hook, ctx);
	mlx_hook(ctx->win, ON_DESTROY, 0L, sl_close, ctx);
	mlx_loop(ctx->mlx);
}
