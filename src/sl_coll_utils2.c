/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_coll_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:43:31 by maliew            #+#    #+#             */
/*   Updated: 2022/09/04 14:53:05 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_coll_free(t_sl_coll *coll)
{
	sl_anim_free(coll->anim);
	ft_lstclear(&coll->coords, &sl_free_content);
	free(coll);
}
