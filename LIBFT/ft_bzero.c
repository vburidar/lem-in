/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:54:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 14:35:23 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *pointer, size_t length)
{
	size_t			i;
	unsigned char	*adr;

	i = 0;
	adr = (unsigned char*)(pointer);
	while (i < length)
	{
		adr[i] = 0;
		i = i + 1;
	}
}
