/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:34:44 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 18:05:29 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "LIBFT/libft.h"

char	*ft_next_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	return (ft_strsub(str, 0, i));
}
