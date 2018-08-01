/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:12:43 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:36:03 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "LIBFT/libft.h"

int		ft_is_comment(char *str)
{
	if (str[0] == '#' && str[1] != '#'
		&& str[1] != '\0')
		return (1);
	return (0);
}

int		ft_is_s_or_e(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	if (ft_strcmp(line, "##end") == 0)
		return (1);
	return (0);
}

int		ft_big_nb(char *line)
{
	int tmp;

	tmp = 0;
	while (line[tmp] && line[tmp] != ' ')
		tmp++;
	if (tmp > 10)
		return (0);
	if (tmp == 10 && ft_strncmp("2147483647", line, 10) < 0)
		return (0);
	return (1);
}

t_info	*ft_free_l(char *line)
{
	free(line);
	return (NULL);
}
