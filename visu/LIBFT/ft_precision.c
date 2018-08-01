/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:48:02 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 11:09:56 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*
** ft_dots deals with the particularities of the '.' flag
** Depending on the main flags and secondary flags, various
** behaviours are expected to imitate printf
** tmp [-n] => tabf[0].tab[25 - n] where the flags are stored in binary
*/

char		*ft_dot(char *str, char *tab_flag, char conv)
{
	unsigned int	compteur;
	char			*tmp;

	tmp = tab_flag;
	if (tmp[-21])
	{
		tab_flag = ft_strchr(tab_flag, '.');
		compteur = ft_find_nb(tab_flag + 1);
		if (compteur == 0 && ft_zero(str) == 0 && conv != '%')
			ft_replace(str, '0', ' ', tmp);
		if (*str == '\0')
			return (str);
		if (conv == 'c' && *str == 'a' && *(str + 2) == '1')
			return (str);
		if (tmp[-22] || tmp[-23] || (ft_strchr(str, '-') && conv == 'd'))
			compteur = compteur + 1;
		if (conv == 'p' || (ft_strchr(tmp, '#') && conv == 'x'))
			compteur = compteur + 2;
		if (!(tmp[-7]) && !(tmp[-2]) && !(tmp[-6])
				&& !(tmp[-5]) && !(tmp[-1]))
			str = ft_concat(str, compteur, '0', *tab_flag);
	}
	return (str);
}

/*
** ft_dots deals with the particularities of the '0' and '-' flags
** Depending on the main flags and secondary flags, various
** behaviours are expected to imitate printf
*/

static char	*ft_flag_z_min(char **tab_flag, char conv, char *str, char *tmp)
{
	unsigned int	compteur;

	compteur = ft_zero(*(tab_flag));
	if (ft_strchr(tmp, '0') && ft_strchr(tmp, '-'))
		**tab_flag = '-';
	if (**tab_flag == '0' && (ft_strchr(tmp, '.') && (conv != 'c'
		&& conv != 's' && conv != 'S' && conv != 'C' && conv != '%')))
		str = ft_concat(str, compteur, ' ', **tab_flag);
	else
		str = ft_concat(str, compteur, '0', **tab_flag);
	*tab_flag = *tab_flag + 1;
	while (**tab_flag >= '0' && **tab_flag <= '9')
		*tab_flag = *tab_flag + 1;
	return (str);
}

/*
** ft_precision deals with taking the precision and secondary flags into
** account. Mainly, it means adding zeroes or spaces to the returned string
** according to the users inputs
**
** General rule of thumb
** '.' precision flag has the priority on '0' and '-'
*/

char		*ft_precision(char *str, char *tab_flag, char conv)
{
	char			*tmp;
	unsigned int	compteur;

	tmp = tab_flag;
	str = ft_dot(str, tab_flag, conv);
	while (*tab_flag != '\0')
	{
		if ((*tab_flag == '0' || *tab_flag == '-'))
			str = ft_flag_z_min(&tab_flag, conv, str, tmp);
		else if (*tab_flag == '.')
		{
			tab_flag++;
			while (*tab_flag >= '0' && *tab_flag <= '9')
				tab_flag++;
		}
		else if (*tab_flag >= '1' && *tab_flag <= '9')
		{
			compteur = ft_find_nb(tab_flag);
			str = ft_concat(str, compteur, ' ', *tab_flag);
			tab_flag++;
		}
		else
			tab_flag++;
	}
	return (str);
}
