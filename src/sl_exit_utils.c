/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:52:07 by maliew            #+#    #+#             */
/*   Updated: 2022/08/21 15:18:49 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_exit	*sl_exit_init(void)
{
	t_sl_exit	*exit;

	exit = (t_sl_exit *)malloc(sizeof(t_sl_exit));
	exit->open = sl_anim_init();
	exit->closed = sl_anim_init();
	exit->coords = NULL;
	return (exit);
}

void	sl_exit_add_coords(t_sl_exit *exit, int x, int y)
{
	int	*arr;

	arr = (int *)malloc(2 * sizeof(int));
	arr[0] = x;
	arr[1] = y;
	ft_lstadd_back(&exit->coords, ft_lstnew(arr));
}
