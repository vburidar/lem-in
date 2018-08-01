/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:03:46 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:29:49 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

int		ft_get_s_or_e(char *instruction)
{
	if (instruction != NULL && ft_strcmp(instruction, "##start") == 0)
		return (1);
	if (instruction != NULL && ft_strcmp(instruction, "##end") == 0)
		return (-1);
	return (0);
}

t_room	*ft_find_room(char *name, t_room *room)
{
	while (room && room->name)
	{
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		room = room->nxt;
	}
	return (NULL);
}

int		ft_add_link(t_room *r_1, t_room *r_2)
{
	t_link	*link;

	link = r_1->lst_link;
	if (r_1->lst_link == NULL)
	{
		if (!(r_1->lst_link = malloc(sizeof(t_link))))
			return (0);
		r_1->lst_link->link = r_2;
		r_1->lst_link->nxt = NULL;
	}
	else
	{
		while (link->nxt != NULL)
			link = link->nxt;
		if (!(link->nxt = malloc(sizeof(t_link))))
			return (0);
		link->nxt->link = r_2;
		link->nxt->nxt = NULL;
	}
	return (1);
}

int		ft_get_link(t_info *data, char *line)
{
	char	*name_1;
	char	*name_2;
	t_room	*room_1;
	t_room	*room_2;

	name_1 = ft_next_char(line, '-');
	room_1 = ft_find_room(name_1, data->room);
	while (*line != '-')
		line++;
	name_2 = ft_next_char(line + 1, '\0');
	room_2 = ft_find_room(name_2, data->room);
	if (room_1 == NULL || room_2 == NULL)
	{
		free(name_1);
		free(name_2);
		return (0);
	}
	if (ft_add_link(room_1, room_2) == 0 || ft_add_link(room_2, room_1) == 0)
		return (0);
	free(name_1);
	free(name_2);
	return (1);
}
