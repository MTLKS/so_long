/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_anims.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:42:33 by maliew            #+#    #+#             */
/*   Updated: 2022/09/03 16:44:28 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_anim1(t_sl_context *ctx)
{
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->idle_right, ctx->imgs->plyr_idle_right_2);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->idle_left, ctx->imgs->plyr_idle_left_2);
	sl_anim_add_frame(ctx->player->walk_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->walk_right, ctx->imgs->plyr_walk_right_1);
	sl_anim_add_frame(ctx->player->walk_right, ctx->imgs->plyr_idle_right_1);
	sl_anim_add_frame(ctx->player->walk_right, ctx->imgs->plyr_walk_right_2);
	sl_anim_add_frame(ctx->player->walk_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->walk_left, ctx->imgs->plyr_walk_left_1);
	sl_anim_add_frame(ctx->player->walk_left, ctx->imgs->plyr_idle_left_1);
	sl_anim_add_frame(ctx->player->walk_left, ctx->imgs->plyr_walk_left_2);
	sl_anim_add_frame(ctx->exits->closed, ctx->imgs->exit_closed_1);
	sl_anim_add_frame(ctx->exits->closed, ctx->imgs->exit_closed_2);
	sl_anim_add_frame(ctx->exits->closed, ctx->imgs->exit_closed_3);
	sl_anim_add_frame(ctx->exits->closed, ctx->imgs->exit_closed_4);
	sl_anim_add_frame(ctx->exits->open, ctx->imgs->exit_open_1);
	sl_anim_add_frame(ctx->colls->anim, ctx->imgs->coll_1);
	sl_anim_add_frame(ctx->colls->anim, ctx->imgs->coll_2);
}

void	sl_load_anims(t_sl_context *ctx)
{
	sl_load_anim1(ctx);
}
