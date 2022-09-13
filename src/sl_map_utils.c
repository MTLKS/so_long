/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:37:58 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 04:29:10 by maliew           ###   ########.fr       */
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
	if (map->img)
		sl_img_free(map->img, mlx);
	free(map);
}

void	sl_init_map(t_sl_map **map)
{
	*map = (t_sl_map *)malloc(sizeof(t_sl_map));
	(*map)->data = NULL;
	(*map)->img = NULL;
	(*map)->width = 0;
	(*map)->height = 0;
}

void	sl_check_wall(t_sl_context *ctx, char *data, int edge, int i)
{
	int	error;

	error = 0;
	if (edge)
	{
		while (*data)
		{
			if (*data != '1' && *data != '\n')
				error = 1;
			data++;
		}
	}
	else if (data[0] != '1' || data[ft_strlen(data) - 2] != '1')
		error = 1;
	if (error)
	{
		ft_printf("Error: Map not closed by walls on Ln %d.\n", i);
		sl_close(ctx);
	}
}

void	sl_check_map(t_sl_context *ctx)
{
	t_list	*buffer;
	int		i;

	buffer = ctx->map->data;
	i = 1;
	while (buffer)
	{
		if (!((int)ft_strlen(buffer->content) - 1 == ctx->map->width
				|| ((int)ft_strlen(buffer->content) == ctx->map->width
					&& i == ctx->map->height)))
		{
			ft_printf("Error: Wrong width on Ln %d.\n", i);
			sl_close(ctx);
		}
		sl_check_wall(ctx, buffer->content,
			(i == 1 || i == ctx->map->height), i);
		buffer = buffer->next;
		i++;
	}
}
