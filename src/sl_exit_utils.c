/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:07 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 14:59:13 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_exit	*sl_exit_init(void)
{
	t_sl_exit	*exit;

	exit = (t_sl_exit *)malloc(sizeof(t_sl_exit));
	exit->open = sl_anim_init();
	exit->closed = sl_anim_init();
	exit->coords = NULL;
	return (exit);
}

void	sl_exit_add_coords(t_sl_exit *exit, int x, int y)
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	arr[0] = x;
	arr[1] = y;
	ft_lstadd_back(&exit->coords, ft_lstnew(arr));
}

void	sl_exit_copy_all(t_sl_img *img, t_sl_context *c)
{
	static int	i = 0;
	static int	frame = 0;
	t_list		*buffer;
	int			*coords;
	t_sl_img	*frame_img;

	frame = ++i / ANIM_SPEED;
	buffer = c->exits->coords;
	if (ft_lstsize(c->colls->coords))
		frame_img = sl_anim_get_frame(c->exits->closed,
				frame % c->exits->closed->frame_count);
	else
		frame_img = sl_anim_get_frame(c->exits->open,
				frame % c->exits->open->frame_count);
	while (buffer)
	{
		coords = (int *)buffer->content;
		sl_copy_image(img, frame_img,
			(SCREEN_W - SPRITE_SIZE) / 2 -(c->player->x) + coords[0],
			(SCREEN_H - SPRITE_SIZE) / 2 -(c->player->y) + coords[1]);
		buffer = buffer->next;
	}
}

void	sl_exit_check(t_sl_context *c)
{
	t_list	*buffer;
	int		*coords;

	buffer = c->exits->coords;
	while (buffer)
	{
		coords = (int *)buffer->content;
		if (c->player->x == coords[0] && c->player->y == coords[1]
			&& ft_lstsize(c->colls->coords) == 0)
			sl_close(c);
		buffer = buffer->next;
	}
}

void	sl_exit_free(t_sl_exit *exit)
{
	sl_anim_free(exit->open);
	sl_anim_free(exit->closed);
	ft_lstclear(&exit->coords, &sl_free_content);
	free(exit);
}
