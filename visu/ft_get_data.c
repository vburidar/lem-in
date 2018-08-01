/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:11:47 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:36:01 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lem_in.h"
#include "LIBFT/libft.h"

int		ft_get_fd(int argc)
{
	if (argc > 1)
	{
		ft_printf("Lem_in does not take any argument\n");
		return (-1);
	}
	return (0);
}

t_info	*ft_get_nb_ant(int fd, t_info *data)
{
	char *line;

	line = NULL;
	if (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '#')
			ft_printf("no comment or instruction on first line\n");
		if (ft_is_number(line, '\0'))
		{
			ft_add_line(data, line);
			data->nb_ant = ft_atoi(line);
			if (data->nb_ant <= 0)
				return (NULL);
			else if (ft_strlen(line) > 10)
				return (NULL);
			else if (ft_strlen(line) == 10 && ft_strcmp("2147483647", line) < 0)
				return (NULL);
		}
		else
			return (ft_free_l(line));
	}
	else
		return (ft_free_l(line));
	return (data);
}

int		ft_get_room(t_info *data, char *line, char *instruction)
{
	t_room	*curseur;

	curseur = data->room;
	if ((curseur = ft_get_nxt_room(curseur, line)) == NULL)
		return (0);
	curseur->name = ft_next_char(line, ' ');
	while (*line != ' ')
		line++;
	line++;
	curseur->coord.x = ft_atoi(line);
	if (ft_big_nb(line) == 0)
		return (0);
	line = ft_is_number(line, ' ');
	if (ft_big_nb(line) == 0)
		return (0);
	curseur->coord.y = ft_atoi(line);
	curseur->s_or_e = ft_get_s_or_e(instruction);
	curseur->lst_link = NULL;
	curseur->dist = 9999999;
	if (!(curseur->nxt = malloc(sizeof(t_room))))
		return (0);
	ft_bzero(curseur->nxt, sizeof(t_room));
	return (1);
}

int		ft_analysis_line(t_info *data, char *line)
{
	static int	room = 1;
	static char	*instruction = NULL;

	if (ft_add_line(data, line) == NULL)
		return (0);
	if (ft_is_room(line) && room > 0 && (room = 2))
	{
		if (ft_get_room(data, line, instruction) == 0)
			return (0);
		instruction = NULL;
	}
	else if (ft_is_link(line) && (room == 2 || room == 0))
	{
		if (ft_get_link(data, line) == 0)
			return (0);
		room = 0;
	}
	else if (ft_is_instruc(line) || ft_is_comment(line))
	{
		if (room != 0 && ft_is_s_or_e(line))
			instruction = line;
	}
	else
		return (ft_dellastline(data));
	return (1);
}

t_info	*ft_get_data(int argc)
{
	int		fd;
	char	*line;
	t_info	*data;

	line = NULL;
	if (!(data = malloc(sizeof(t_info))))
		return (NULL);
	if (!(data->room = malloc(sizeof(t_room))))
		return (ft_free_data(data));
	data->room->nxt = NULL;
	data->room->name = NULL;
	data->room->lst_link = NULL;
	data->lst_line = NULL;
	if ((fd = ft_get_fd(argc)) == -1)
		return (ft_free_data(data));
	if (ft_get_nb_ant(fd, data) == NULL)
		return (ft_free_data(data));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_analysis_line(data, line) == 0)
			return (data);
	}
	free(line);
	return (data);
}
