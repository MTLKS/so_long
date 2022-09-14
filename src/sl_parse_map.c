/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:19:04 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 12:36:41 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_parse_map_image(t_sl_context *ctx, char c, int x, int y)
{
	if (c == '1')
		sl_copy_image(ctx->map->img, sl_get_imgs(ctx->imgs, "wall"),
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (ft_strchr("CENP0", c))
		sl_copy_image(ctx->map->img, sl_get_imgs(ctx->imgs, "ground"),
			x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	sl_parse_character(t_sl_context *ctx, char c, int x, int y)
{
	if (!ft_strchr("CENP01\n", c))
	{
		ft_printf("Error: Unknown Key '%c' at Ln %d, Col %d.\n",
			c, y + 1, x + 1);
		sl_close(ctx);
	}
	if (c == 'P')
		sl_player_set_coords(ctx, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'C')
		sl_coll_add_coords(ctx->colls, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'E')
		sl_exit_set_coords(ctx, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == 'N')
		sl_enemy_set_coords(ctx, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	sl_loop_map(t_sl_context *ctx,
	void (*f)(t_sl_context *ctx, char c, int x, int y))
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
			f(ctx, ((char *)buffer->content)[x], x, y);
		buffer = buffer->next;
		y++;
	}
}

static int	sl_open_map_fd(t_sl_context *ctx, char *path)
{
	char	*temp;
	int		fd;

	temp = ft_substr(path, ft_strlen(path) - 4, 4);
	if (ft_strncmp(temp, ".ber", 4) != 0)
	{
		ft_printf("Error: Wrong file extension '%s'.\n", path);
		sl_close(ctx);
	}
	free(temp);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot read file '%s'.\n", path);
		sl_close(ctx);
	}
	return (fd);
}

void	sl_parse_map(t_sl_context *ctx, char *path)
{
	int		fd;
	char	*buffer;

	sl_init_map(&ctx->map);
	fd = sl_open_map_fd(ctx, path);
	buffer = get_next_line(fd);
	while (buffer)
	{
		ctx->map->height++;
		ft_lstadd_back(&ctx->map->data, ft_lstnew(sl_map_data_new(buffer)));
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	ctx->map->width = ft_strlen(ctx->map->data->content) - 1;
	ctx->map->img = sl_new_img(ctx->mlx,
			ctx->map->width * SPRITE_SIZE, ctx->map->height * SPRITE_SIZE);
	sl_loop_map(ctx, &sl_parse_character);
	sl_check_map(ctx);
	sl_check_missing_key(ctx);
	sl_check_invalid_path_coll(ctx);
	sl_check_invalid_path_exit(ctx);
}
