/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:07 by maliew            #+#    #+#             */
/*   Updated: 2022/09/09 02:55:48 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_exit	*sl_exit_init(void)
{
	t_sl_exit	*exit;

	exit = (t_sl_exit *)malloc(sizeof(t_sl_exit));
	exit->open = sl_anim_init();
	exit->closed = sl_anim_init();
	exit->x = 0;
	exit->y = 0;
	return (exit);
}

void	sl_exit_set_coords(t_sl_context *ctx, int x, int y)
{
	if (ctx->exit->x != 0 || ctx->exit->y != 0)
	{
		ft_printf("Error: Double key 'E' at [%d,%d] and [%d,%d].\n",
			ctx->exit->y / SPRITE_SIZE + 1, ctx->exit->x / SPRITE_SIZE + 1,
			y / SPRITE_SIZE + 1, x / SPRITE_SIZE + 1);
		sl_close(ctx);
	}
	ctx->exit->x = x;
	ctx->exit->y = y;
}

void	sl_exit_copy_all(t_sl_img *img, t_sl_context *c)
{
	static int	i = 0;
	static int	frame = 0;
	t_sl_img	*frame_img;

	frame = ++i / ANIM_SPEED;
	if (ft_lstsize(c->colls->coords))
		frame_img = sl_anim_get_frame(c->exit->closed,
				frame % c->exit->closed->frame_count);
	else
		frame_img = sl_anim_get_frame(c->exit->open,
				frame % c->exit->open->frame_count);
	sl_copy_image(img, frame_img,
		(SCREEN_W - SPRITE_SIZE) / 2 -(c->player->x) + c->exit->x,
		(SCREEN_H - SPRITE_SIZE) / 2 -(c->player->y) + c->exit->y);
}

void	sl_exit_check(t_sl_context *c)
{
	if (c->player->x == c->exit->x && c->player->y == c->exit->y
		&& ft_lstsize(c->colls->coords) == 0)
	{
		ft_printf("You Win!\n");
		sl_close(c);
	}	
}

void	sl_exit_free(t_sl_exit *exit)
{
	sl_anim_free(exit->open);
	sl_anim_free(exit->closed);
	free(exit);
}
