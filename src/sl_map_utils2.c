/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:32:55 by maliew            #+#    #+#             */
/*   Updated: 2022/09/12 20:16:22 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sl_map_data_new(char *str)
{
	void	*buffer;

	buffer = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_memcpy(buffer, str, ft_strlen(str) + 1);
	return (buffer);
}

void	sl_check_missing_key(t_sl_context *ctx)
{
	if (ctx->player->x == 0 || ctx->player->y == 0)
	{
		ft_printf("Error: Missing key 'P'.\n");
		sl_close(ctx);
	}
	else if (ctx->exit->x == 0 || ctx->exit->y == 0)
	{
		ft_printf("Error: Missing key 'E'.\n");
		sl_close(ctx);
	}
	else if (ft_lstsize(ctx->colls->coords) == 0)
	{
		ft_printf("Error: Missing key 'C'.\n");
		sl_close(ctx);
	}
}

void	sl_check_invalid_path_coll(t_sl_context *ctx)
{
	t_list			*buffer;
	t_sl_pathfind	*pf;
	int				error;

	buffer = ctx->colls->coords;
	while (buffer)
	{
		pf = sl_pf_new(ctx->player->x / SPRITE_SIZE,
				ctx->player->y / SPRITE_SIZE,
				((int *)(buffer->content))[0] / SPRITE_SIZE,
				((int *)(buffer->content))[1] / SPRITE_SIZE);
		sl_pathfind(ctx, pf);
		error = !pf->moves;
		ft_lstclear(&pf->moves, &sl_free_content);
		free(pf);
		if (error)
		{
			ft_printf("Error: No valid path to Collectible at [%d, %d].\n",
				((int *)(buffer->content))[0] / SPRITE_SIZE,
				((int *)(buffer->content))[1] / SPRITE_SIZE);
			sl_close(ctx);
		}
		pf = NULL;
		buffer = buffer->next;
	}
}

void	sl_check_invalid_path_exit(t_sl_context *ctx)
{
	t_sl_pathfind	*pf;
	int				error;

	pf = sl_pf_new(ctx->player->x / SPRITE_SIZE, ctx->player->y / SPRITE_SIZE,
			ctx->exit->x / SPRITE_SIZE, ctx->exit->y / SPRITE_SIZE);
	sl_pathfind(ctx, pf);
	error = !pf->moves;
	ft_lstclear(&pf->moves, &sl_free_content);
	free(pf);
	if (error)
	{
		ft_printf("Error: No valid path to Exit at [%d, %d].\n",
			ctx->exit->x / SPRITE_SIZE, ctx->exit->y / SPRITE_SIZE);
		sl_close(ctx);
	}
}

void	sl_map_copy_image(t_sl_img *buffer, t_sl_context *c)
{
	sl_copy_image(buffer, c->map->img,
		(SCREEN_W - SPRITE_SIZE) / 2 - c->player->x,
		(SCREEN_H - SPRITE_SIZE) / 2 - c->player->y);
}
