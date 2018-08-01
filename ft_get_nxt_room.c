/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nxt_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:30:39 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 15:43:14 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

t_room	*ft_get_nxt_room(t_room *room, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'L' || line[i] == '-')
			return (NULL);
		i++;
	}
	while (room->nxt)
	{
		tmp = ft_next_char(line, ' ');
		if (ft_strcmp(tmp, room->name) == 0)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		room = room->nxt;
	}
	return (room);
}
