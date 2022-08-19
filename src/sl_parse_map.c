/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:19:04 by maliew            #+#    #+#             */
/*   Updated: 2022/08/19 03:34:41 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_map(t_sl_map **map)
{
	*map = (t_sl_map *)malloc(sizeof(t_sl_map));
	(*map)->data = NULL;
	(*map)->img = NULL;
	(*map)->width = 0;
	(*map)->height = 0;
}

void	sl_generate_map_img(void *mlx, t_sl_map *map)
{
	t_list		*buffer;
	int			i;
	int			j;
	t_sl_img	*ground;
	t_sl_img	*wall;

	map->img = sl_new_img(mlx, map->width * 64, map->height * 64);
	ground = sl_xpm_to_img(mlx, "./assets/sprites/ground.xpm");
	wall = sl_xpm_to_img(mlx, "./assets/sprites/wall.xpm");
	buffer = map->data;
	j = 0;
	while (buffer)
	{
		i = -1;
		while (((char *)buffer->content)[++i])
		{
			if (((char *)buffer->content)[i] == '1')
				sl_copy_image(map->img, wall, i * 64, j * 64);
			else if (ft_strchr("CENP0", ((char *)buffer->content)[i]))
				sl_copy_image(map->img, ground, i * 64, j * 64);
		}
		buffer = buffer->next;
		j++;
	}
}

void	sl_parse_map(t_sl_context *c, char *path)
{
	int		fd;
	char	*buffer;

	fd = open(path, O_RDONLY);
	sl_init_map(&c->map);
	buffer = get_next_line(fd);
	while (buffer)
	{
		c->map->height++;
		ft_lstadd_back(&c->map->data, ft_lstnew(buffer));
		buffer = get_next_line(fd);
	}
	c->map->width = ft_strlen(c->map->data->content);
	sl_generate_map_img(c->mlx, c->map);
}
