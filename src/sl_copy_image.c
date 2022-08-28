/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:21:10 by maliew            #+#    #+#             */
/*   Updated: 2022/08/27 02:03:13 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_ispixelblack(char *buffer, int pixel)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if ((buffer[pixel + i] | 0x00) != 0x00)
			return (0);
	}
	return (1);
}

/*
** https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html
** https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
*/
void	sl_copy_image(t_sl_img *des, t_sl_img *src, int x, int y)
{
	int		endian;
	int		pixel_bits;
	int		line_bytes;
	int		line_bytes2;
	int		i;
	int		j;
	char	*buffer;
	char	*buffer2;

	buffer = mlx_get_data_addr(src->img, &pixel_bits, &line_bytes, &endian);
	buffer2 = mlx_get_data_addr(des->img, &pixel_bits, &line_bytes2, &endian);
	if (y < 0)
		j = -y;
	else
		j = -1;
	while (++j < src->height && y + j < des->height)
	{
		if (x < 0)
			i = -x;
		else
			i = -1;
		while (++i < src->width && x+i < des->width)
		{
			int pixel = ((j) * line_bytes) + ((i) * 4);
			int pixel2 = ((y + j) * line_bytes2) + ((x + i) * 4);
			if (!sl_ispixelblack(buffer, pixel))
			{
				buffer2[pixel2 + 0] = buffer[pixel + 0];
				buffer2[pixel2 + 1] = buffer[pixel + 1];
				buffer2[pixel2 + 2] = buffer[pixel + 2];
				buffer2[pixel2 + 3] = buffer[pixel + 3];
			}
		}
	}
}
