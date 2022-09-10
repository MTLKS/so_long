/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:32:55 by maliew            #+#    #+#             */
/*   Updated: 2022/09/09 02:54:51 by maliew           ###   ########.fr       */
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
