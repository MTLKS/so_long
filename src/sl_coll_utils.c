/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_coll_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:26:44 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 14:43:22 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_coll	*sl_coll_init(void)
{
	t_sl_coll	*coll;

	coll = (t_sl_coll *)malloc(sizeof(t_sl_coll));
	coll->anim = sl_anim_init();
	coll->coords = NULL;
	return (coll);
}

void	sl_coll_add_coords(t_sl_coll *coll, int x, int y)
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	arr[0] = x;
	arr[1] = y;
	ft_lstadd_back(&coll->coords, ft_lstnew(arr));
}

int	*sl_coll_get_coords(t_sl_coll *coll, int index)
{
	t_list	*buffer;
	int		i;

	buffer = coll->coords;
	i = -1;
	while (++i < index && buffer)
		buffer = buffer->next;
	return ((int *)buffer->content);
}

void	sl_coll_copy_all(t_sl_img *img, t_sl_context *c)
{
	static int	i = 0;
	static int	frame = 0;
	t_list		*buffer;
	int			*coords;

	frame = ++i / ANIM_SPEED;
	buffer = c->colls->coords;
	while (buffer)
	{
		coords = (int *)buffer->content;
		sl_copy_image(img,
			sl_anim_get_frame(c->colls->anim,
				frame % c->colls->anim->frame_count),
			(SCREEN_W - SPRITE_SIZE) / 2 -(c->player->x) + coords[0],
			(SCREEN_H - SPRITE_SIZE) / 2 -(c->player->y) + coords[1]);
		buffer = buffer->next;
	}
}

void	sl_coll_check(t_sl_context *c)
{
	t_list	*prev;
	t_list	*buffer;
	t_list	*temp;
	int		*coords;

	prev = NULL;
	buffer = c->colls->coords;
	while (buffer)
	{
		coords = (int *)buffer->content;
		if (c->player->x == coords[0] && c->player->y == coords[1])
		{
			if (prev == NULL)
				c->colls->coords = buffer->next;
			else
				prev->next = buffer->next;
			temp = buffer;
			free(temp->content);
			free(temp);
			return ;
		}
		prev = buffer;
		buffer = buffer->next;
	}
}
