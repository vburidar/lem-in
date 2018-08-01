/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:18:18 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/04 17:45:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_lem_in.h"

t_coord	ft_get_min(t_info *data)
{
	t_room	*curseur;
	t_coord	min;

	min.x = data->room->coord.x;
	min.y = data->room->coord.y;
	curseur = data->room;
	while (curseur->name)
	{
		if (curseur->coord.x < min.x)
			min.x = curseur->coord.x;
		if (curseur->coord.y < min.y)
			min.y = curseur->coord.y;
		curseur = curseur->nxt;
	}
	return (min);
}

t_coord	ft_get_max(t_info *data)
{
	t_room	*curseur;
	t_coord	max;

	max.x = data->room->coord.x;
	max.y = data->room->coord.y;
	curseur = data->room;
	while (curseur->name)
	{
		if (curseur->coord.x > max.x)
			max.x = curseur->coord.x;
		if (curseur->coord.y > max.y)
			max.y = curseur->coord.y;
		curseur = curseur->nxt;
	}
	return (max);
}

void	ft_resize_coord(t_info *data)
{
	t_room	*room;
	t_coord	min;
	t_coord	max;

	room = data->room;
	min = ft_get_min(data);
	max = ft_get_max(data);
	max.x = max.x - min.x;
	max.y = max.y - min.y;
	while (room->name)
	{
		room->coord.x = room->coord.x - min.x;
		room->coord.y = room->coord.y - min.y;
		room->coord.x = (room->coord.x * 1800) / (max.x) + 50;
		room->coord.y = (room->coord.y * 900) / (max.y) + 50;
		room = room->nxt;
	}
}
