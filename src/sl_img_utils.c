/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:45:51 by maliew            #+#    #+#             */
/*   Updated: 2022/09/08 04:03:58 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_img	*sl_xpm_to_img(t_sl_context *ctx, char *path)
{
	t_sl_img	*res;

	res = (t_sl_img *)malloc(sizeof(t_sl_img));
	res->img = mlx_xpm_file_to_image(ctx->mlx, path, &res->width, &res->height);
	if (res->img == NULL)
	{
		ft_printf("Error: Missing asset '%s'.\n", path);
		sl_close(ctx);
	}
	return (res);
}

t_sl_img	*sl_new_img(void *mlx, int width, int height)
{
	t_sl_img	*res;

	res = (t_sl_img *)malloc(sizeof(t_sl_img));
	res->img = mlx_new_image(mlx, width, height);
	res->width = width;
	res->height = height;
	return (res);
}

void	sl_img_free(t_sl_img *img, void *mlx)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}
