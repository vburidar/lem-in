/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:33:27 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/26 18:44:02 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)(malloc((int)(len + 1) * sizeof(char)))))
		return (NULL);
	else
	{
		while (i < (int)(len))
		{
			new[i] = s[i + start];
			i = i + 1;
		}
		new[i] = '\0';
		return (new);
	}
}
