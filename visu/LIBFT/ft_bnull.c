/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bnull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:33:25 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/22 18:36:31 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_bnull(void **pointer, size_t length)
{
	size_t			i;
	char			**adr;

	i = 0;
	adr = (char**)(pointer);
	while (i < length)
	{
		adr[i] = NULL;
		i++;
	}
}
