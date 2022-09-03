/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:42:53 by maliew            #+#    #+#             */
/*   Updated: 2022/09/03 16:24:45 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_anim	*sl_anim_init(void)
{
	t_sl_anim	*anim;

	anim = (t_sl_anim *)malloc(sizeof(t_sl_anim));
	anim->frames = NULL;
	anim->frame_count = 0;
	return (anim);
}

void	sl_anim_add_frame(t_sl_anim *anim, t_sl_img *img)
{
	ft_lstadd_back(&anim->frames, ft_lstnew(img));
	(anim->frame_count)++;
}

t_sl_img	*sl_anim_get_frame(t_sl_anim *anim, int index)
{
	t_list	*buffer;
	int		i;

	buffer = anim->frames;
	i = -1;
	while (++i < index && buffer)
		buffer = buffer->next;
	return ((t_sl_img *)buffer->content);
}
