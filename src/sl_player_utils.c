/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:14 by maliew            #+#    #+#             */
/*   Updated: 2022/08/21 19:42:07 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_player	*sl_player_init(void)
{
	t_sl_player	*player;

	player = (t_sl_player *)malloc(sizeof(t_sl_player));
	player->s_left = sl_anim_init();
	player->s_right = sl_anim_init();
	player->w_left = sl_anim_init();
	player->w_right = sl_anim_init();
	player->sleep = sl_anim_init();
	player->x = 0;
	player->y = 0;
	player->dir = 0;
	return (player);
}

t_sl_img	*sl_player_get_anim(t_sl_player *p)
{
	static int	i;
	static int	frame;

	if (i >= 3)
	{
		i = 0;
		frame++;
	}
	i++;
	if (p->dir)
		return (sl_anim_get_frame(p->s_right, frame % p->s_right->frame_count));
	else
		return (sl_anim_get_frame(p->s_left, frame % p->s_left->frame_count));
}
