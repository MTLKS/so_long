/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_imgs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 00:33:36 by maliew            #+#    #+#             */
/*   Updated: 2022/09/08 03:59:30 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_add_imgs(t_sl_context *ctx, char *key, char *path)
{
	t_sl_imgs	*new_img;

	new_img = (t_sl_imgs *)malloc(sizeof(t_sl_imgs));
	new_img->key = ft_strdup(key);
	new_img->img = sl_xpm_to_img(ctx, path);
	new_img->next = ctx->imgs;
	ctx->imgs = new_img;
}

t_sl_img	*sl_get_imgs(t_sl_imgs *imgs, char *key)
{
	while (imgs)
	{
		if (ft_strncmp(imgs->key, key, ft_strlen(key)) == 0)
			return (imgs->img);
		imgs = imgs->next;
	}
	return (NULL);
}

void	sl_imgs_free(t_sl_imgs *imgs, void *mlx)
{
	t_sl_imgs	*temp;

	while (imgs)
	{
		temp = imgs;
		imgs = imgs->next;
		sl_img_free(temp->img, mlx);
		free(temp->key);
		free(temp);
	}
}
