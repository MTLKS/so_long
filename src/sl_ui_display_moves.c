/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ui_display_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:07:02 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 12:23:46 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_img	*sl_ui_get_move_img(t_sl_context *c, t_list *move_list)
{
	int			move;
	t_sl_img	*img;

	img = NULL;
	move = *(int *)move_list->content;
	if (move == MOVE_UP)
		img = sl_get_imgs(c->imgs, "move_up");
	else if (move == MOVE_DOWN)
		img = sl_get_imgs(c->imgs, "move_down");
	else if (move == MOVE_LEFT)
		img = sl_get_imgs(c->imgs, "move_left");
	else if (move == MOVE_RIGHT)
		img = sl_get_imgs(c->imgs, "move_right");
	return (img);
}

void	sl_ui_display_moves(t_sl_img *buffer_img, t_sl_context *c)
{
	t_list	*buffer_move;
	int		x;
	int		y;

	buffer_move = c->player->move_list;
	x = 0;
	y = SCREEN_H - SPRITE_SIZE;
	while (x < SCREEN_W && buffer_move)
	{
		sl_copy_image(buffer_img, sl_ui_get_move_img(c, buffer_move), x, y);
		buffer_move = buffer_move->next;
		x += SPRITE_SIZE;
	}
}
