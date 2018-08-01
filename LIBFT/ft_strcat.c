/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:26:59 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 13:04:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		i = i + 1;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}
