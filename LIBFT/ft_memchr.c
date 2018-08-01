/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:32:51 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 13:02:27 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *src, int c, size_t taille)
{
	int		i;
	char	*curseur;

	i = 0;
	curseur = (char*)(src);
	while (i < (int)(taille))
	{
		if (curseur[i] == (char)(c))
			return (curseur + i);
		i = i + 1;
	}
	return (NULL);
}
