/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_context_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:10:32 by maliew            #+#    #+#             */
/*   Updated: 2022/09/03 16:24:48 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_context	*sl_context_init(void)
{
	t_sl_context	*ctx;

	ctx = (t_sl_context *)malloc(sizeof(t_sl_context));
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, SCREEN_W, SCREEN_H, "so_long");
	ctx->player = sl_player_init();
	ctx->colls = sl_coll_init();
	ctx->exits = sl_exit_init();
	ctx->enemies = sl_enemy_init();
	ctx->scene = sl_new_img(ctx->mlx, SCREEN_W, SCREEN_H);
	return (ctx);
}
