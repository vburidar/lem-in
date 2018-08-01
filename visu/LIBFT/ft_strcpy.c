/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:48:36 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/20 20:46:56 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	taille;

	i = 0;
	taille = ft_strlen(src);
	while (i < taille)
	{
		if (src[i])
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
