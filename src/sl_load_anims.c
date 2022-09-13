/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_anims.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:42:33 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 02:13:25 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_anim1(t_sl_context *ctx)
{
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr0"));
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr1"));
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr2"));
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr3"));
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr4"));
	sl_anim_add_frame(ctx->player->walk_right, sl_get_imgs(ctx->imgs, "plyr5"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyr6"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyr7"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyr8"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyr9"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyrA"));
	sl_anim_add_frame(ctx->player->idle_right, sl_get_imgs(ctx->imgs, "plyrB"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrC"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrD"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrE"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrF"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrG"));
	sl_anim_add_frame(ctx->player->walk_left, sl_get_imgs(ctx->imgs, "plyrH"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrI"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrJ"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrK"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrL"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrM"));
	sl_anim_add_frame(ctx->player->idle_left, sl_get_imgs(ctx->imgs, "plyrN"));
}

static void	sl_load_anim2(t_sl_context *ctx)
{
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem0"));
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem1"));
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem2"));
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem3"));
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem4"));
	sl_anim_add_frame(ctx->enemy->walk_right, sl_get_imgs(ctx->imgs, "enem5"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enem6"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enem7"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enem8"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enem9"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enemA"));
	sl_anim_add_frame(ctx->enemy->idle_right, sl_get_imgs(ctx->imgs, "enemB"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemC"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemD"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemE"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemF"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemG"));
	sl_anim_add_frame(ctx->enemy->walk_left, sl_get_imgs(ctx->imgs, "enemH"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemI"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemJ"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemK"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemL"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemM"));
	sl_anim_add_frame(ctx->enemy->idle_left, sl_get_imgs(ctx->imgs, "enemN"));
}

static void	sl_load_anim3(t_sl_context *ctx)
{
	sl_anim_add_frame(ctx->exit->closed,
		sl_get_imgs(ctx->imgs, "exit_closed_1"));
	sl_anim_add_frame(ctx->exit->closed,
		sl_get_imgs(ctx->imgs, "exit_closed_2"));
	sl_anim_add_frame(ctx->exit->closed,
		sl_get_imgs(ctx->imgs, "exit_closed_3"));
	sl_anim_add_frame(ctx->exit->closed,
		sl_get_imgs(ctx->imgs, "exit_closed_4"));
	sl_anim_add_frame(ctx->exit->open,
		sl_get_imgs(ctx->imgs, "exit_open_1"));
	sl_anim_add_frame(ctx->exit->open,
		sl_get_imgs(ctx->imgs, "exit_open_2"));
	sl_anim_add_frame(ctx->exit->open,
		sl_get_imgs(ctx->imgs, "exit_open_3"));
	sl_anim_add_frame(ctx->exit->open,
		sl_get_imgs(ctx->imgs, "exit_open_4"));
	sl_anim_add_frame(ctx->colls->anim,
		sl_get_imgs(ctx->imgs, "coll_1"));
	sl_anim_add_frame(ctx->colls->anim,
		sl_get_imgs(ctx->imgs, "coll_2"));
	sl_anim_add_frame(ctx->colls->anim,
		sl_get_imgs(ctx->imgs, "coll_3"));
	sl_anim_add_frame(ctx->colls->anim,
		sl_get_imgs(ctx->imgs, "coll_2"));
}

void	sl_load_anims(t_sl_context *ctx)
{
	sl_load_anim1(ctx);
	sl_load_anim2(ctx);
	sl_load_anim3(ctx);
}
