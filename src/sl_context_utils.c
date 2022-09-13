/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_context_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:10:32 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 04:47:15 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_context	*sl_context_init(void)
{
	t_sl_context	*ctx;

	ctx = (t_sl_context *)malloc(sizeof(t_sl_context));
	ctx->mlx = mlx_init();
	ctx->win = NULL;
	ctx->player = sl_player_init();
	ctx->colls = sl_coll_init();
	ctx->exit = sl_exit_init();
	ctx->enemy = sl_player_init();
	ctx->imgs = NULL;
	ctx->move_count = 0;
	ctx->enemy_moved = 1;
	return (ctx);
}

void	sl_context_free(t_sl_context *ctx)
{
	sl_map_free(ctx->map, ctx->mlx);
	sl_player_free(ctx->player);
	sl_coll_free(ctx->colls);
	sl_exit_free(ctx->exit);
	sl_player_free(ctx->enemy);
	sl_imgs_free(ctx->imgs, ctx->mlx);
	if (ctx->win)
		mlx_destroy_window(ctx->mlx, ctx->win);
}
