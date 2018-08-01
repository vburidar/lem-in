/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:08:36 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 06:30:53 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

t_info	*ft_check_startend(t_info *data)
{
	t_room		*curseur;
	int			start;
	int			end;

	start = 0;
	end = 0;
	curseur = data->room;
	while (curseur && curseur->name)
	{
		if (curseur->s_or_e == 1)
			start = 1;
		if (curseur->s_or_e == -1)
			end = 1;
		curseur = curseur->nxt;
	}
	if (start == 0 || end == 0)
		return (ft_free_data(data));
	return (data);
}

t_line	*ft_print_line(t_line *lst_line)
{
	t_line *tmp;

	while (lst_line)
	{
		tmp = lst_line;
		ft_printf("%s\n", lst_line->line);
		lst_line = lst_line->nxt;
		free(tmp->line);
		free(tmp);
		tmp = NULL;
	}
	ft_printf("\n");
	return (NULL);
}

int		ft_print_error(t_info *data)
{
	if (data != NULL)
		ft_free_data(data);
	ft_printf("ERROR\n");
	return (0);
}

int		ft_s_or_e(t_info *data)
{
	t_room	*curseur;
	int		test;

	curseur = data->room;
	test = 0;
	while (curseur)
	{
		if (curseur->s_or_e != 0)
			test++;
		curseur = curseur->nxt;
	}
	if (test > 2)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_info		*data;
	t_path_pack	path_pack;

	(void)argv;
	path_pack.init = NULL;
	path_pack.current = NULL;
	data = ft_get_data(argc);
	if (data == NULL || ft_check_startend(data) == NULL
			|| ft_s_or_e(data) == 0)
		ft_printf("ERROR\n");
	else
	{
		path_pack.best = ft_get_path(data, path_pack);
		if (path_pack.best != NULL)
		{
			data->lst_line = ft_print_line(data->lst_line);
			ft_fill_path(data, path_pack.best);
			ft_free_data(data);
			ft_free_path(path_pack.best);
		}
		else
			return (ft_print_error(data));
	}
	return (0);
}
