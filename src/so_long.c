/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:29 by maliew            #+#    #+#             */
/*   Updated: 2022/08/20 19:53:10 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_sl_player *player)
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

int	render(t_sl_context *context)
{
	static int	i = 0;
	t_sl_img	*buffer;

	// (void)context;
	(void)buffer;
	if (i > 1000)
	{
		i = 0;
		buffer = malloc(sizeof(t_sl_img));
		buffer->img = mlx_new_image(context->mlx, 640, 320);
		buffer->width = 640;
		buffer->height = 320;
		sl_copy_image(buffer, context->map->img, 288-context->player->x, 128-context->player->y);
		if (context->player->dir)
			sl_copy_image(buffer, context->player->s_right->frames, 288, 128);
		else
			sl_copy_image(buffer, context->player->s_left->frames, 288, 128);
		mlx_put_image_to_window(context->mlx, context->win, buffer->img, 0, 0);
		mlx_destroy_image(context->mlx, buffer->img);
		free(buffer);
		sl_print_context(context);
	}
	i++;
	return (0);
}

int	sl_close(t_sl_context *context)
{
	mlx_destroy_window(context->mlx, context->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sl_context	*context;
	t_sl_img		*ground;

	if (argc != 2)
		return (0);
	ft_printf("Hello World!\n");
	context = (t_sl_context *)malloc(sizeof(t_sl_context));
	ground = malloc(sizeof(t_sl_img));
	context->mlx = mlx_init();
	context->win = mlx_new_window(context->mlx, 640, 320, "Hello world!");
	context->player = (t_sl_player *)malloc(sizeof(t_sl_player));
	context->player->x = 64;
	context->player->y = 64;
	context->player->dir = 1;
	context->player->s_right = malloc(sizeof(t_sl_anim));
	context->player->s_right->frames = malloc(sizeof(t_sl_img));
	context->player->s_right->frames->img = mlx_xpm_file_to_image(context->mlx,
			"./assets/sprites/cat_s_right.xpm", &context->player->s_right->frames->width, &context->player->s_right->frames->height);
	context->player->s_left = malloc(sizeof(t_sl_anim));
	context->player->s_left->frames = malloc(sizeof(t_sl_img));
	context->player->s_left->frames->img = mlx_xpm_file_to_image(context->mlx,
			"./assets/sprites/cat_s_left.xpm", &context->player->s_left->frames->width, &context->player->s_left->frames->height);
	context->scene = malloc(sizeof(t_sl_img));
	context->scene->img = mlx_new_image(context->mlx, 640, 320);
	context->scene->width = 640;
	context->scene->height = 320;
	ground->img = mlx_xpm_file_to_image(context->mlx,
			"./assets/sprites/ground.xpm", &ground->width, &ground->height);
	sl_parse_map(context, argv[1]);
	mlx_loop_hook(context->mlx, render, context);
	mlx_key_hook(context->win, key_hook, context->player);
	mlx_hook(context->win, ON_DESTROY, 0L, sl_close, context);
	mlx_loop(context->mlx);
}
