/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:12:29 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/01 20:30:12 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "lem_in.h"

void	ft_print_data(t_info *data)
{
	while (data->room->name)
	{
		ft_printf("name = %s, x = %d, y = %d s_or_e = %d\n",
		data->room->name, data->room->coord.x,
		data->room->coord.y, data->room->s_or_e);
		while (data->room->lst_link->nxt)
		{
			ft_printf("link %s\n", data->room->lst_link->link->name);
			data->room->lst_link = data->room->lst_link->nxt;
		}
		data->room = data->room->nxt;
	}
}
