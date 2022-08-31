/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:13:52 by maliew            #+#    #+#             */
/*   Updated: 2022/08/31 16:02:59 by maliew           ###   ########.fr       */
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

static void	sl_move_player_step(t_sl_player *player)
{
	int	move;

	move = *(int *)player->move_list->content;
	if (move == MOVE_UP)
		player->y -= SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_LEFT)
		player->x -= SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_DOWN)
		player->y += SPRITE_SIZE / STEP_SIZE;
	else if (move == MOVE_RIGHT)
		player->x += SPRITE_SIZE / STEP_SIZE;
	if (move == MOVE_LEFT && player->dir == FACE_RIGHT)
		player->dir = FACE_LEFT;
	else if (move == MOVE_RIGHT && player->dir == FACE_LEFT)
		player->dir = FACE_RIGHT;
}

void	sl_move_player(t_sl_player *player)
{
	t_list	*temp;

	if (player->move_list)
	{
		if (player->move_count == 0)
			player->move_count = STEP_SIZE;
		sl_move_player_step(player);
		player->move_count--;
		if (player->move_count == 0)
		{
			temp = player->move_list;
			player->move_list = player->move_list->next;
			ft_lstdelone(temp, &sl_move_delete);
		}
	}
}
