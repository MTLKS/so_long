/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:37:58 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 14:50:42 by maliew           ###   ########.fr       */
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

void	sl_map_free(t_sl_map *map, void *mlx)
{
	ft_lstclear(&map->data, &sl_free_content);
	sl_img_free(map->img, mlx);
	free(map);
}
