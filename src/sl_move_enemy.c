/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:17:21 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 22:11:00 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_move_enemy_step(t_sl_context *c)
{
	int	move;

	if (c->enemy->move_list)
	{
		move = *(int *)c->enemy->move_list->content;
		if (move == MOVE_UP)
			c->enemy->y -= SPRITE_SIZE / STEP_SIZE;
		else if (move == MOVE_LEFT)
			c->enemy->x -= SPRITE_SIZE / STEP_SIZE;
		else if (move == MOVE_DOWN)
			c->enemy->y += SPRITE_SIZE / STEP_SIZE;
		else if (move == MOVE_RIGHT)
			c->enemy->x += SPRITE_SIZE / STEP_SIZE;
		if (move == MOVE_LEFT && c->enemy->dir == FACE_RIGHT)
			c->enemy->dir = FACE_LEFT;
		else if (move == MOVE_RIGHT && c->enemy->dir == FACE_LEFT)
			c->enemy->dir = FACE_RIGHT;
	}
}

void	sl_move_enemy(t_sl_context *c)
{
	t_sl_pathfind	*pf;

	if (c->move_count % 2 == 1 && c->enemy_moved == 0)
	{
		if (c->enemy->move_count == 0)
		{
			pf = sl_pf_new(c->enemy->x / SPRITE_SIZE, c->enemy->y / SPRITE_SIZE,
					c->player->x / SPRITE_SIZE, c->player->y / SPRITE_SIZE);
			sl_pathfind(c, pf);
			c->enemy->move_count = STEP_SIZE;
			c->enemy->move_list = pf->moves;
			free(pf);
			pf = NULL;
		}
		sl_move_enemy_step(c);
		c->enemy->move_count--;
		if (c->enemy->move_count == 0)
		{
			ft_lstclear(&c->enemy->move_list, &sl_free_content);
			c->enemy->move_list = NULL;
			c->enemy_moved = 1;
		}
	}
	else if (c->move_count % 2 == 0)
		c->enemy_moved = 0;
}
