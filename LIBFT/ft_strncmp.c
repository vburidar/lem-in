/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:51:50 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:32:26 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*curseur1;
	unsigned char	*curseur2;

	curseur1 = (unsigned char*)(s1);
	curseur2 = (unsigned char*)(s2);
	i = 0;
	while (curseur1[i] == curseur2[i]
			&& i < (int)(n) && curseur1[i] && curseur2[i])
		i = i + 1;
	if (curseur1[i] != curseur2[i] && i < (int)(n))
		return (curseur1[i] - curseur2[i]);
	else
		return (0);
}
