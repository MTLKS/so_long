/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:45:51 by maliew            #+#    #+#             */
/*   Updated: 2022/08/27 02:22:25 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_img	*sl_xpm_to_img(void *mlx, char *path)
{
	t_sl_img	*res;

	res = (t_sl_img *)malloc(sizeof(t_sl_img));
	res->img = mlx_xpm_file_to_image(mlx, path, &res->width, &res->height);
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

void	t_sl_img_free(void *mlx, t_sl_img *img)
{
	mlx_destroy_image(mlx, img->img);
	free(img);
}
