/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:47:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 15:30:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "visu_lem_in.h"

void	ft_color_room(t_room *room, char *str, int n_col, t_coord curseur)
{
	ft_white_pixel(curseur, str);
	if (room->s_or_e == -1)
		ft_green_pixel(curseur, str);
	if (n_col == 1)
		ft_red_pixel(curseur, str);
	if (room->s_or_e == 1)
		ft_blue_pixel(curseur, str);
}

void	ft_print_room(t_room *room, char *str, t_col *col)
{
	t_coord curseur;
	int		n_col;

	n_col = 0;
	while (col)
	{
		if (ft_strcmp(col->name, room->name) == 0)
			n_col = 1;
		col = col->nxt;
	}
	curseur.x = room->coord.x - 10;
	curseur.y = room->coord.y - 10;
	while (curseur.x < room->coord.x + 10)
	{
		while (curseur.y < room->coord.y + 10)
		{
			ft_color_room(room, str, n_col, curseur);
			curseur.y = curseur.y + 1;
		}
		curseur.y = room->coord.y - 10;
		curseur.x = curseur.x + 1;
	}
}
