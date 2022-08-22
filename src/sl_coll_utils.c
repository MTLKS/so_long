/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_coll_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:26:44 by maliew            #+#    #+#             */
/*   Updated: 2022/08/21 19:45:16 by maliew           ###   ########.fr       */
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

t_sl_img	*sl_coll_get_anim(t_sl_coll *coll)
{
	static int	i = 0;
	static int	frame = 0;

	if (++i >= 3)
	{
		i = 0;
		frame++;
	}
	return (sl_anim_get_frame(coll->anim, frame % coll->anim->frame_count));
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
	t_list	*buffer;

	buffer = c->colls->coords;
	while (buffer)
	{
		sl_copy_image(img, sl_coll_get_anim(c->colls), 288-(c->player->x)+((int *)buffer->content)[0], 128-(c->player->y)+((int *)buffer->content)[1]);
		buffer = buffer->next;
	}
}
