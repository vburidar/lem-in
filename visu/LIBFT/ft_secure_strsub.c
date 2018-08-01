/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_strsub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:17:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 11:25:07 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_secure_strsub(char *s, int start, int compteur)
{
	char *del;

	del = s;
	s = ft_strsub(s, start, compteur);
	free(del);
	return (s);
}
