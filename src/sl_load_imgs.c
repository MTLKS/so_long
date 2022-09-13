/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 01:15:48 by maliew            #+#    #+#             */
/*   Updated: 2022/09/14 02:12:56 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_load_imgs1(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "ground", "./assets/sprites/ground.xpm");
	sl_add_imgs(ctx, "wall", "./assets/sprites/wall.xpm");
	sl_add_imgs(ctx, "coll_1", "./assets/sprites/popcorn.xpm");
	sl_add_imgs(ctx, "coll_2", "./assets/sprites/popcorn2.xpm");
	sl_add_imgs(ctx, "coll_3", "./assets/sprites/popcorn3.xpm");
	sl_add_imgs(ctx, "exit_closed_1", "./assets/sprites/exit_closed1.xpm");
	sl_add_imgs(ctx, "exit_closed_2", "./assets/sprites/exit_closed2.xpm");
	sl_add_imgs(ctx, "exit_closed_3", "./assets/sprites/exit_closed3.xpm");
	sl_add_imgs(ctx, "exit_closed_4", "./assets/sprites/exit_closed4.xpm");
	sl_add_imgs(ctx, "exit_open_1", "./assets/sprites/exit_open1.xpm");
	sl_add_imgs(ctx, "exit_open_2", "./assets/sprites/exit_open2.xpm");
	sl_add_imgs(ctx, "exit_open_3", "./assets/sprites/exit_open3.xpm");
	sl_add_imgs(ctx, "exit_open_4", "./assets/sprites/exit_open4.xpm");
}

static void	sl_load_imgs2(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "move_up", "./assets/sprites/move_up.xpm");
	sl_add_imgs(ctx, "move_down", "./assets/sprites/move_down.xpm");
	sl_add_imgs(ctx, "move_left", "./assets/sprites/move_left.xpm");
	sl_add_imgs(ctx, "move_right", "./assets/sprites/move_right.xpm");
	sl_add_imgs(ctx, "move_count", "./assets/sprites/paws.xpm");
	sl_add_imgs(ctx, "0", "./assets/sprites/0.xpm");
	sl_add_imgs(ctx, "1", "./assets/sprites/1.xpm");
	sl_add_imgs(ctx, "2", "./assets/sprites/2.xpm");
	sl_add_imgs(ctx, "3", "./assets/sprites/3.xpm");
	sl_add_imgs(ctx, "4", "./assets/sprites/4.xpm");
	sl_add_imgs(ctx, "5", "./assets/sprites/5.xpm");
	sl_add_imgs(ctx, "6", "./assets/sprites/6.xpm");
	sl_add_imgs(ctx, "7", "./assets/sprites/7.xpm");
	sl_add_imgs(ctx, "8", "./assets/sprites/8.xpm");
	sl_add_imgs(ctx, "9", "./assets/sprites/9.xpm");
}

static void	sl_load_imgs3(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "plyr0", "./assets/sprites/cat0.xpm");
	sl_add_imgs(ctx, "plyr1", "./assets/sprites/cat1.xpm");
	sl_add_imgs(ctx, "plyr2", "./assets/sprites/cat2.xpm");
	sl_add_imgs(ctx, "plyr3", "./assets/sprites/cat3.xpm");
	sl_add_imgs(ctx, "plyr4", "./assets/sprites/cat4.xpm");
	sl_add_imgs(ctx, "plyr5", "./assets/sprites/cat5.xpm");
	sl_add_imgs(ctx, "plyr6", "./assets/sprites/cat6.xpm");
	sl_add_imgs(ctx, "plyr7", "./assets/sprites/cat7.xpm");
	sl_add_imgs(ctx, "plyr8", "./assets/sprites/cat8.xpm");
	sl_add_imgs(ctx, "plyr9", "./assets/sprites/cat9.xpm");
	sl_add_imgs(ctx, "plyrA", "./assets/sprites/catA.xpm");
	sl_add_imgs(ctx, "plyrB", "./assets/sprites/catB.xpm");
	sl_add_imgs(ctx, "plyrC", "./assets/sprites/catC.xpm");
	sl_add_imgs(ctx, "plyrD", "./assets/sprites/catD.xpm");
	sl_add_imgs(ctx, "plyrE", "./assets/sprites/catE.xpm");
	sl_add_imgs(ctx, "plyrF", "./assets/sprites/catF.xpm");
	sl_add_imgs(ctx, "plyrG", "./assets/sprites/catG.xpm");
	sl_add_imgs(ctx, "plyrH", "./assets/sprites/catH.xpm");
	sl_add_imgs(ctx, "plyrI", "./assets/sprites/catI.xpm");
	sl_add_imgs(ctx, "plyrJ", "./assets/sprites/catJ.xpm");
	sl_add_imgs(ctx, "plyrK", "./assets/sprites/catK.xpm");
	sl_add_imgs(ctx, "plyrL", "./assets/sprites/catL.xpm");
	sl_add_imgs(ctx, "plyrM", "./assets/sprites/catM.xpm");
	sl_add_imgs(ctx, "plyrN", "./assets/sprites/catN.xpm");
}

static void	sl_load_imgs4(t_sl_context *ctx)
{
	sl_add_imgs(ctx, "enem0", "./assets/sprites/enemy0.xpm");
	sl_add_imgs(ctx, "enem1", "./assets/sprites/enemy1.xpm");
	sl_add_imgs(ctx, "enem2", "./assets/sprites/enemy2.xpm");
	sl_add_imgs(ctx, "enem3", "./assets/sprites/enemy3.xpm");
	sl_add_imgs(ctx, "enem4", "./assets/sprites/enemy4.xpm");
	sl_add_imgs(ctx, "enem5", "./assets/sprites/enemy5.xpm");
	sl_add_imgs(ctx, "enem6", "./assets/sprites/enemy6.xpm");
	sl_add_imgs(ctx, "enem7", "./assets/sprites/enemy7.xpm");
	sl_add_imgs(ctx, "enem8", "./assets/sprites/enemy8.xpm");
	sl_add_imgs(ctx, "enem9", "./assets/sprites/enemy9.xpm");
	sl_add_imgs(ctx, "enemA", "./assets/sprites/enemyA.xpm");
	sl_add_imgs(ctx, "enemB", "./assets/sprites/enemyB.xpm");
	sl_add_imgs(ctx, "enemC", "./assets/sprites/enemyC.xpm");
	sl_add_imgs(ctx, "enemD", "./assets/sprites/enemyD.xpm");
	sl_add_imgs(ctx, "enemE", "./assets/sprites/enemyE.xpm");
	sl_add_imgs(ctx, "enemF", "./assets/sprites/enemyF.xpm");
	sl_add_imgs(ctx, "enemG", "./assets/sprites/enemyG.xpm");
	sl_add_imgs(ctx, "enemH", "./assets/sprites/enemyH.xpm");
	sl_add_imgs(ctx, "enemI", "./assets/sprites/enemyI.xpm");
	sl_add_imgs(ctx, "enemJ", "./assets/sprites/enemyJ.xpm");
	sl_add_imgs(ctx, "enemK", "./assets/sprites/enemyK.xpm");
	sl_add_imgs(ctx, "enemL", "./assets/sprites/enemyL.xpm");
	sl_add_imgs(ctx, "enemM", "./assets/sprites/enemyM.xpm");
	sl_add_imgs(ctx, "enemN", "./assets/sprites/enemyN.xpm");
}

void	sl_load_imgs(t_sl_context *ctx)
{
	ctx->imgs = NULL;
	sl_load_imgs1(ctx);
	sl_load_imgs2(ctx);
	sl_load_imgs3(ctx);
	sl_load_imgs4(ctx);
}
