/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:41:28 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 16:26:58 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "LIBFT/libft.h"

t_room	*ft_get_start(t_info *data)
{
	t_room	*curs_room;

	curs_room = data->room;
	while (curs_room->s_or_e != 1)
		curs_room = curs_room->nxt;
	return (curs_room);
}

t_path	*ft_cpy_lst(t_path *path)
{
	t_path *cpy;
	t_path *init;

	if (path)
	{
		if (!(cpy = malloc(sizeof(t_path))))
			return (NULL);
		init = cpy;
		cpy->room = path->room;
		cpy->nxt = NULL;
	}
	else
		return (NULL);
	while (path->nxt)
	{
		if (!(cpy->nxt = malloc(sizeof(t_path))))
			return (NULL);
		cpy = cpy->nxt;
		cpy->room = path->nxt->room;
		path = path->nxt;
	}
	cpy->nxt = NULL;
	return (init);
}

void	ft_add_room(t_path_pack path_p, t_room *room, int distance)
{
	t_path	*curs_path;
	t_path	*tmp;

	curs_path = path_p.current->nxt;
	tmp = curs_path;
	while (curs_path)
	{
		tmp = curs_path->nxt;
		free(curs_path);
		curs_path = tmp;
	}
	room->dist = distance;
	if (!(path_p.current->nxt = malloc(sizeof(t_path))))
		exit(1);
	path_p.current->nxt->room = room;
	path_p.current->nxt->nxt = NULL;
}

t_path	*ft_recursive(t_path_pack path_p, t_room *room, int distance)
{
	t_link *curseur;

	curseur = room->lst_link;
	if (distance > room->dist)
		return (path_p.best);
	else if (room->s_or_e == -1)
	{
		ft_add_room(path_p, room, distance);
		ft_free_path(path_p.best);
		path_p.best = ft_cpy_lst(path_p.init);
		return (path_p.best);
	}
	else
	{
		ft_add_room(path_p, room, distance);
		path_p.current = path_p.current->nxt;
		while (curseur)
		{
			path_p.best = ft_recursive(path_p, curseur->link, distance + 1);
			curseur = curseur->nxt;
		}
	}
	return (path_p.best);
}

t_path	*ft_get_path(t_info *data, t_path_pack path_pack)
{
	t_link *curs_link;

	path_pack.best = NULL;
	if (!(path_pack.current = malloc(sizeof(t_path))))
		return (NULL);
	path_pack.current->nxt = NULL;
	path_pack.init = path_pack.current;
	path_pack.current->room = ft_get_start(data);
	path_pack.current->room->dist = 0;
	curs_link = path_pack.current->room->lst_link;
	while (curs_link)
	{
		path_pack.best =
		ft_recursive(path_pack, curs_link->link, 1);
		curs_link = curs_link->nxt;
	}
	ft_free_path(path_pack.init);
	return (path_pack.best);
}
