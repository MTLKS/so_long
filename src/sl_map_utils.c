/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:37:58 by maliew            #+#    #+#             */
/*   Updated: 2022/08/31 18:28:08 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_is_wall(t_sl_context *c, int x, int y)
{
	t_list	*buffer;
	char	*data;
	int		i;

	buffer = c->map->data;
	i = -1;
	while (++i < y / SPRITE_SIZE)
		buffer = buffer->next;
	data = (char *)buffer->content;
	return (data[x / SPRITE_SIZE] == '1');
}
