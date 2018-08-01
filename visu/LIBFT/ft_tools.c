/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:37:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 11:12:11 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ft_find_nb returns the first number found in a string char*
** It is mainly used to get a number in the middle of a flag
** string
*/

int		ft_find_nb(char *adr)
{
	char	*tmp;
	char	*ret;
	int		val;

	if (!(ret = malloc(sizeof(char))))
		exit(1);
	if (!(tmp = malloc(2 * (sizeof(char)))))
		exit(1);
	ret[0] = '\0';
	tmp[1] = '\0';
	while ((*adr < '0' || *adr > '9') && *adr != '.'
			&& *adr != ' ' && *adr != '-' && *adr)
		adr++;
	while (*adr >= '0' && *adr <= '9')
	{
		tmp[0] = *adr;
		ret = ft_strjoin(ret, tmp, 1);
		adr++;
	}
	free(tmp);
	val = ft_atoi(ret);
	free(ret);
	return (val);
}

/*
** ft_zero is used to ascertain priority of '.' flag on '0' flag
** in case both flags are present
*/
int		ft_zero(char *str)
{
	while (*str && *str != '.' && !(*str >= '1' && *str <= '9'))
		str++;
	return (ft_find_nb(str));
}

void	ft_replace(char *str, char old, char new, char *tab_flag)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (*str == old)
		{
			if (ft_strlen(tmp) == 1)
				*str = '\0';
			else if (ft_strchr(tab_flag, 'o') && ft_strchr(tab_flag, '#'))
				*(str + 1) = '\0';
			else if (ft_strchr(tab_flag, 'O') && ft_strchr(tab_flag, '#'))
				*(str + 1) = '\0';
			else if (ft_strchr(tab_flag, 'p') && ft_strchr(tab_flag, '.'))
			{
				str[0] = '0';
				str[2] = '\0';
			}
			else
				*str = new;
		}
		str++;
	}
}

/*
** add the flag at the end of the string of flags already written
*/

void	ft_add(char c, char tab[128])
{
	int		i;

	i = 25;
	while (tab[i])
		i++;
	tab[i] = c;
	tab[i + 1] = '\0';
}
