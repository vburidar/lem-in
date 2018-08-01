/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:16:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 13:02:40 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dest, void *src, size_t taille)
{
	int		i;
	char	*curseur;
	char	*arrivee;

	curseur = (char*)(src);
	arrivee = (char*)(dest);
	if (dest > src)
	{
		i = (int)(taille - 1);
		while (i >= 0)
		{
			arrivee[i] = curseur[i];
			i = i - 1;
		}
	}
	else
	{
		i = 0;
		while (i < (int)(taille))
		{
			arrivee[i] = curseur[i];
			i = i + 1;
		}
	}
	return (dest);
}
