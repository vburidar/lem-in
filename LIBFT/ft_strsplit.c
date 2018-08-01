/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/21 17:14:09 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_nblignes(const char *str, char c)
{
	int		i;
	int		mot;
	int		nb_mot;

	i = 0;
	mot = 0;
	nb_mot = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			if (mot == 0)
			{
				mot = 1;
				nb_mot = nb_mot + 1;
			}
			i = i + 1;
		}
		mot = 0;
		if (str[i])
			i = i + 1;
	}
	return (nb_mot);
}

static char	*ft_alloc_lignes(char **tab, const char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			j = j + 1;
			i = i + 1;
		}
		if (j != 0)
		{
			if (!(tab[k] = (char*)malloc(j * sizeof(char))))
				return (NULL);
			k = k + 1;
		}
		j = 0;
		if (str[i])
			i = i + 1;
	}
	return ((char*)str);
}

static char	**ft_tabcpy(const char *str, char **tab, int k, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			tab[k][j] = str[i];
			j = j + 1;
			i = i + 1;
		}
		if (j != 0)
		{
			tab[k][j] = '\0';
			k = k + 1;
		}
		j = 0;
		if (str[i])
			i = i + 1;
	}
	tab[k] = NULL;
	return (tab);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		k;

	k = 0;
	if (str == NULL)
		return (NULL);
	if (!(tab = (char**)malloc((ft_nblignes(str, c) + 1) * sizeof(char*))))
		return (NULL);
	ft_alloc_lignes(tab, str, c);
	tab = ft_tabcpy(str, tab, k, c);
	return (tab);
}
