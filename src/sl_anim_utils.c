/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:42:53 by maliew            #+#    #+#             */
/*   Updated: 2022/08/20 17:45:40 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_anim	*sl_init_anim(int frame_count)
{
	t_sl_anim	*anim;

	anim = (t_sl_anim *)malloc(sizeof(t_sl_anim));
	anim->frame_count = frame_count;
	return (anim);
}
