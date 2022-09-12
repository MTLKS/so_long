/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:45:22 by maliew            #+#    #+#             */
/*   Updated: 2022/09/12 21:21:48 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_img	*sl_get_movecount_img(t_sl_context *c, int n)
{
	if (n == 0)
		return (sl_get_imgs(c->imgs, "0"));
	else if (n == 1)
		return (sl_get_imgs(c->imgs, "1"));
	else if (n == 2)
		return (sl_get_imgs(c->imgs, "2"));
	else if (n == 3)
		return (sl_get_imgs(c->imgs, "3"));
	else if (n == 4)
		return (sl_get_imgs(c->imgs, "4"));
	else if (n == 5)
		return (sl_get_imgs(c->imgs, "5"));
	else if (n == 6)
		return (sl_get_imgs(c->imgs, "6"));
	else if (n == 7)
		return (sl_get_imgs(c->imgs, "7"));
	else if (n == 8)
		return (sl_get_imgs(c->imgs, "8"));
	else
		return (sl_get_imgs(c->imgs, "9"));
}

void	sl_put_movecount(t_sl_img *buffer, t_sl_context *c, int n, int flag)
{
	static int	x;

	if (flag)
		x = 1;
	if (n >= 10)
		sl_put_movecount(buffer, c, n / 10, 0);
	sl_copy_image(buffer, sl_get_movecount_img(c, n % 10), x * SPRITE_SIZE, 0);
	x++;
}

void	sl_print_movecount(t_sl_img *buffer, t_sl_context *c)
{
	sl_put_movecount(buffer, c, c->move_count, 1);
}
