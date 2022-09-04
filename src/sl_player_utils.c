/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:14 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 14:52:36 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_player	*sl_player_init(void)
{
	t_sl_player	*player;

	player = (t_sl_player *)malloc(sizeof(t_sl_player));
	player->idle_left = sl_anim_init();
	player->idle_right = sl_anim_init();
	player->walk_left = sl_anim_init();
	player->walk_right = sl_anim_init();
	player->x = 0;
	player->y = 0;
	player->dir = 0;
	player->move_count = 0;
	player->move_list = NULL;
	return (player);
}

void	sl_player_set_coords(t_sl_player *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

t_sl_img	*sl_player_get_anim(t_sl_player *p)
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

void	sl_player_free(t_sl_player *player)
{
	sl_anim_free(player->idle_left);
	sl_anim_free(player->idle_right);
	sl_anim_free(player->walk_left);
	sl_anim_free(player->walk_right);
	ft_lstclear(&player->move_list, &sl_free_content);
	free(player);
}
