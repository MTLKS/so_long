/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/21 19:41:52 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook(int keycode, t_sl_player *player)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		player->y -= PLAYER_STEP;
	else if (keycode == KEY_A)
		player->x -= PLAYER_STEP;
	else if (keycode == KEY_S)
		player->y += PLAYER_STEP;
	else if (keycode == KEY_D)
		player->x += PLAYER_STEP;
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
		sl_copy_image(buffer, c->map->img, 288-c->player->x, 128-c->player->y);
		// if (c->player->dir)
		// 	sl_copy_image(buffer, sl_anim_get_frame(c->player->s_right, 0), 288, 128);
		// else
		// 	sl_copy_image(buffer, sl_anim_get_frame(c->player->s_left, 0), 288, 128);
		sl_copy_image(buffer, sl_player_get_anim(c->player), 288, 128);
		// sl_copy_image(buffer, sl_coll_get_anim(c->colls), 288-(c->player->x)+sl_coll_get_coords(c->colls, 0)[0], 128-(c->player->y)+sl_coll_get_coords(c->colls, 0)[1]);
		sl_coll_copy_all(buffer, c);
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
	t_sl_context	*c;

	// pause();
	if (argc != 2)
		return (0);
	ft_printf("Hello World!\n");
	c = (t_sl_context *)malloc(sizeof(t_sl_context));
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, SCREEN_W, SCREEN_H, "so_long");
	c->player = sl_player_init();
	c->player->x = 256;
	c->player->y = 192;
	c->player->dir = 1;
	sl_anim_add_frame(c->player->s_right, sl_xpm_to_img(c->mlx, "./assets/sprites/cat_s_right.xpm"));
	sl_anim_add_frame(c->player->s_right, sl_xpm_to_img(c->mlx, "./assets/sprites/cat_s_right2.xpm"));
	sl_anim_add_frame(c->player->s_left, sl_xpm_to_img(c->mlx, "./assets/sprites/cat_s_left.xpm"));
	sl_anim_add_frame(c->player->s_left, sl_xpm_to_img(c->mlx, "./assets/sprites/cat_s_left2.xpm"));
	c->scene = sl_new_img(c->mlx, 640, 320);
	c->colls = sl_coll_init();
	sl_anim_add_frame(c->colls->anim, sl_xpm_to_img(c->mlx, "./assets/sprites/popcorn.xpm"));
	sl_anim_add_frame(c->colls->anim, sl_xpm_to_img(c->mlx, "./assets/sprites/popcorn2.xpm"));
	sl_parse_map(c, argv[1]);
	mlx_loop_hook(c->mlx, sl_render, c);
	mlx_key_hook(c->win, sl_key_hook, c->player);
	mlx_hook(c->win, ON_DESTROY, 0L, sl_close, c);
	mlx_loop(c->mlx);
}
