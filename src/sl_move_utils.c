/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:13:52 by maliew            #+#    #+#             */
/*   Updated: 2022/09/02 00:27:44 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sl_move_new(int new_move)
{
	void	*move;

	move = malloc(sizeof(int));
	*(int *)move = new_move;
	return (move);
}

static void	sl_move_delete(void *content)
{
	free(content);
}

static void	sl_move_player_step(t_sl_context *c)
{
	int	move;

	move = *(int *)c->player->move_list->content;
	if (move == MOVE_UP && !sl_is_wall(c, c->player->x,
			c->player->y - SPRITE_SIZE / STEP_SIZE))
		c->player->y -= SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_LEFT && !sl_is_wall(c,
			c->player->x - SPRITE_SIZE / STEP_SIZE, c->player->y))
		c->player->x -= SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_DOWN
		&& !sl_is_wall(c, c->player->x, c->player->y + SPRITE_SIZE))
		c->player->y += SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_RIGHT
		&& !sl_is_wall(c, c->player->x + SPRITE_SIZE, c->player->y))
		c->player->x += SPRITE_SIZE / STEP_SIZE;
	if (move == MOVE_LEFT && c->player->dir == FACE_RIGHT)
		c->player->dir = FACE_LEFT;
	else if (move == MOVE_RIGHT && c->player->dir == FACE_LEFT)
		c->player->dir = FACE_RIGHT;
}

void	sl_move_player(t_sl_context *c)
{
	t_list	*temp;

	if (c->player->move_list)
	{
		if (c->player->move_count == 0)
			c->player->move_count = STEP_SIZE;
		sl_move_player_step(c);
		c->player->move_count--;
		if (c->player->move_count == 0)
		{
			temp = c->player->move_list;
			c->player->move_list = c->player->move_list->next;
			ft_lstdelone(temp, &sl_move_delete);
		}
	}
}
