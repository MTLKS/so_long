/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:46:43 by maliew            #+#    #+#             */
/*   Updated: 2022/08/20 20:19:08 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_context(t_sl_context *c)
{
	t_list	*buffer;

	if (c->map)
	{
		if (c->map->data)
		{
			ft_printf("Map data:\n");
			buffer = c->map->data;
			while (buffer)
			{
				ft_printf("%s", (char *)buffer->content);
				buffer = buffer->next;
			}
			ft_printf("\n");
		}
	}
	if (c->player)
	{
		ft_printf("Player:\nx:%d,y:%d,dir:%d\n",
			c->player->x, c->player->y, c->player->dir);
	}
	if (c->colls)
	{
		buffer = c->colls->coords;
		while (buffer) 
		{
			ft_printf("[%d,%d], ", ((int *)c->colls->coords->content)[0], ((int *)c->colls->coords->content)[1]);
			buffer = buffer->next;
		}
		ft_printf("\n");
	}
}