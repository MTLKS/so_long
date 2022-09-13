/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:10 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 01:12:53 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_enemy_set_coords(t_sl_context *ctx, int x, int y)
{
	if (ctx->enemy->x != 0 || ctx->enemy->y != 0)
	{
		ft_printf("Error: Double key 'N' at [%d,%d] and [%d,%d].\n",
			ctx->enemy->y / SPRITE_SIZE + 1, ctx->enemy->x / SPRITE_SIZE + 1,
			y / SPRITE_SIZE + 1, x / SPRITE_SIZE + 1);
		sl_close(ctx);
	}
	ctx->enemy->x = x;
	ctx->enemy->y = y;
}

t_sl_img	*sl_enemy_get_anim(t_sl_player *p)
{
	static int	i = 0;
	static int	frame = 0;

	frame = ++i / ANIM_SPEED;
	if (p->dir && !p->move_list)
		return (sl_anim_get_frame(p->idle_right,
				frame % p->idle_right->frame_count));
	else if (!p->dir && !p->move_list)
		return (sl_anim_get_frame(p->idle_left,
				frame % p->idle_left->frame_count));
	else if (p->dir)
		return (sl_anim_get_frame(p->walk_right,
				frame % p->walk_right->frame_count));
	else
		return (sl_anim_get_frame(p->walk_left,
				frame % p->walk_left->frame_count));
}

void	sl_enemy_copy_image(t_sl_img *img, t_sl_context *c)
{
	t_sl_img	*frame_img;

	if (!c->enemy->x)
		return ;
	frame_img = sl_enemy_get_anim(c->enemy);
	sl_copy_image(img, frame_img,
		(SCREEN_W - SPRITE_SIZE) / 2 -(c->player->x) + c->enemy->x,
		(SCREEN_H - SPRITE_SIZE) / 2 -(c->player->y) + c->enemy->y);
}

void	sl_enemy_check(t_sl_context *c)
{
	if (c->player->x == c->enemy->x && c->player->y == c->enemy->y)
	{
		ft_printf("You Lose!\n");
		sl_close(c);
	}	
}
