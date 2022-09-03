/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:19:04 by maliew            #+#    #+#             */
/*   Updated: 2022/09/03 17:48:40 by maliew           ###   ########.fr       */
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

void	sl_parse_character(t_sl_context *ctx, char c, int x, int y)
{
	if (c == 'P')
		sl_player_set_coords(ctx->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'C')
		sl_coll_add_coords(ctx->colls, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'E')
		sl_exit_add_coords(ctx->exits, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (c == '1')
		sl_copy_image(ctx->map->img, ctx->imgs->wall,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (ft_strchr("CENP0", c))
		sl_copy_image(ctx->map->img, ctx->imgs->ground,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c != '\n')
	{
		ft_printf("Map Error: Unknown Key '%c' at Ln %d, Col %d.\n",
			c, x + 1, y + 1);
		sl_close();
	}
}

void	sl_loop_map(t_sl_context *ctx)
{
	t_list	*buffer;
	int		x;
	int		y;

	buffer = ctx->map->data;
	y = 0;
	while (buffer)
	{
		x = -1;
		while (((char *)buffer->content)[++x])
			sl_parse_character(ctx, ((char *)buffer->content)[x], x, y);
		buffer = buffer->next;
		y++;
	}
}

static void	sl_check_map(t_sl_context *ctx)
{
	t_list	*buffer;
	int		i;

	buffer = ctx->map->data->content;
	while (buffer)
	{

	}
}

static void	*sl_map_data_new(char *str)
{
	void	*buffer;

	buffer = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_memcpy(buffer, str, ft_strlen(str) + 1);
	return (buffer);
}

void	sl_parse_map(t_sl_context *ctx, char *path)
{
	int		fd;
	int		len;
	char	*buffer;

	fd = open(path, O_RDONLY);
	// if (fd == -1)
		// send error
	sl_init_map(&ctx->map);
	buffer = get_next_line(fd);
	len = ft_strlen(buffer);
	while (buffer)
	{
		ctx->map->height++;
		ft_lstadd_back(&ctx->map->data, ft_lstnew(sl_map_data_new(buffer)));
		free(buffer);
		buffer = get_next_line(fd);

	}
	ctx->map->width = ft_strlen(ctx->map->data->content);
	ctx->map->img = sl_new_img(ctx->mlx,
			ctx->map->width * SPRITE_SIZE, ctx->map->height * SPRITE_SIZE);
	sl_loop_map(ctx);
}
