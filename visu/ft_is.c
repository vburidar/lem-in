/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:22:58 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:10:42 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "LIBFT/libft.h"
#include "lem_in.h"

char	*ft_is_number(char *str, char c)
{
	while (*str != c && *str)
	{
		if (*str > '9' || *str < '0')
			return (NULL);
		str++;
	}
	if (*str != c)
		return (NULL);
	if (*str)
		str++;
	return (str);
}

int		ft_isnant(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_room(char *str)
{
	int i;

	i = 0;
	if (*str == ' ')
		return (0);
	while (*str && *str != ' ')
		str++;
	if (*str == '\0')
		return (0);
	str++;
	if ((str = ft_is_number(str, ' ')) == NULL)
		return (0);
	if ((str = ft_is_number(str, '\0')) == NULL)
		return (0);
	return (1);
}

int		ft_is_link(char *str)
{
	int i;

	i = 0;
	while (str[i] != '-')
	{
		if (str[i] == ' ' || str[i] == '\0')
			return (0);
		i++;
	}
	i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_instruc(char *str)
{
	if (str[0] && str[1])
	{
		if (str[0] == '#' && str[1] == '#'
			&& str[2] != '\0')
			return (1);
	}
	return (0);
}
