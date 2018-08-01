/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellastline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:22:05 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 14:48:30 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include <stdlib.h>
#include "lem_in.h"

int	ft_dellastline(t_info *data)
{
	t_line	*curseur;

	curseur = data->lst_line;
	if (curseur != NULL)
	{
		if (curseur->nxt == NULL)
		{
			free(curseur->line);
			curseur = NULL;
		}
		else
		{
			while (curseur->nxt->nxt)
				curseur = curseur->nxt;
			free(curseur->nxt->line);
			free(curseur->nxt);
			curseur->nxt = NULL;
		}
	}
	return (0);
}
