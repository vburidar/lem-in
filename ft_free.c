/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 15:59:27 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:48:17 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

t_link	*ft_free_link(t_link *link)
{
	t_link	*curs_link;

	while (link)
	{
		curs_link = link->nxt;
		free(link);
		link = curs_link;
	}
	return (NULL);
}

t_line	*ft_free_line(t_line *line)
{
	t_line	*curs_line;

	while (line)
	{
		curs_line = line->nxt;
		free(line->line);
		free(line);
		line = curs_line;
	}
	return (NULL);
}

t_info	*ft_free_data(t_info *data)
{
	t_room *curs_room;

	while (data->room)
	{
		data->room->lst_link = ft_free_link(data->room->lst_link);
		if (data->lst_line)
			data->lst_line = ft_free_line(data->lst_line);
		curs_room = data->room->nxt;
		free(data->room->name);
		free(data->room);
		data->room = curs_room;
	}
	free(data);
	return (NULL);
}

void	ft_free_path(t_path *path)
{
	t_path *curs_path;

	while (path)
	{
		curs_path = path->nxt;
		free(path);
		path = curs_path;
	}
}

void	ft_free_ant(t_ant *ant)
{
	t_ant	*curs_ant;

	while (ant)
	{
		curs_ant = ant->nxt;
		free(ant);
		ant = curs_ant;
	}
}
