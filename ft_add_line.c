/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:10:44 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 14:42:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "LIBFT/libft.h"

t_info	*ft_add_line(t_info *data, char *line)
{
	t_line *curseur;

	curseur = data->lst_line;
	if (curseur == NULL)
	{
		if (!(data->lst_line = malloc(sizeof(t_line))))
			return (NULL);
		data->lst_line->line = line;
		data->lst_line->nxt = NULL;
	}
	else
	{
		while (curseur->nxt)
			curseur = curseur->nxt;
		if (!(curseur->nxt = malloc(sizeof(t_line))))
			return (NULL);
		curseur->nxt->line = line;
		curseur->nxt->nxt = NULL;
	}
	return (data);
}
