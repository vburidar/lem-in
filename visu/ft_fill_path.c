/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:47:29 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:48:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

t_ant	*ft_init_ant(t_ant *ant, int nb_ant, t_path *path)
{
	int		cmp;
	t_ant	*init;

	cmp = 2;
	if (!(ant = malloc(sizeof(t_ant))))
		return (NULL);
	init = ant;
	ant->nb = 1;
	ant->room = path->room;
	ant->nxt = NULL;
	while (cmp <= nb_ant)
	{
		if (!(ant->nxt = malloc(sizeof(t_ant))))
			return (NULL);
		ant = ant->nxt;
		ant->nb = cmp;
		ant->room = path->room;
		ant->nxt = NULL;
		cmp++;
	}
	return (init);
}

t_room	*ft_find_nxt_room(t_room *room, t_path *path)
{
	t_path	*curseur;

	curseur = path;
	while (curseur->room != room)
		curseur = curseur->nxt;
	return (curseur->nxt->room);
}

int		ft_print_path(t_ant *ant, int nb_ant, t_path *best)
{
	if (ant->room && ant->room->s_or_e == -1)
	{
		ant->room = NULL;
		nb_ant = nb_ant - 1;
	}
	else if (ant->room)
		ant->room = ft_find_nxt_room(ant->room, best);
	if (ant->room != NULL)
		ft_printf("L%d-%s ", ant->nb, ant->room->name);
	ant = ant->nxt;
	return (nb_ant);
}

void	ft_fill_path(t_info *data, t_path *best)
{
	t_ant	*ant;
	t_ant	*init_ant;
	int		nb_ant;

	ant = NULL;
	nb_ant = data->nb_ant;
	ant = ft_init_ant(ant, nb_ant, best);
	init_ant = ant;
	while (nb_ant > 0)
	{
		while (ant && ant->room != best->room)
		{
			nb_ant = ft_print_path(ant, nb_ant, best);
			ant = ant->nxt;
		}
		if (ant)
		{
			ant->room = ft_find_nxt_room(ant->room, best);
			ft_printf("L%d-%s ", ant->nb, ant->room->name);
		}
		if (nb_ant != 0)
			ft_printf("\n");
		ant = init_ant;
	}
	ft_free_ant(init_ant);
}
