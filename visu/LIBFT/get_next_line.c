/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:08:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/08/01 11:25:28 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int	ft_test_stock(char **line, char **stock)
{
	char		*tmp;

	if (ft_memchr(*stock, '\n', ft_strlen(*stock)) != NULL)
	{
		*(char*)ft_memchr(*stock, '\n', ft_strlen(*stock)) = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, *stock, 0);
		ft_memdel((void**)&tmp);
		(*stock)[ft_strlen(*stock)] = '\n';
		tmp = *stock;
		*stock = ft_strsub(ft_memchr(*stock, '\n', ft_strlen(*stock)) + 1,
				0, ft_strlen(ft_memchr(*stock, '\n', ft_strlen(*stock))) - 1);
		ft_memdel((void**)&tmp);
		if (stock[0][0] == '\0')
			ft_memdel((void**)stock);
		return (1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *stock, 0);
	ft_memdel((void**)&tmp);
	return (0);
}

int	ft_modif_buf(int ret, char **stock, char buf[BUFF_SIZE], char **line)
{
	char *tmp;

	tmp = *stock;
	*stock = ft_strsub(ft_memchr(buf, '\n', ret) + 1, 0, buf + ret -
			(char*)ft_memchr(buf, '\n', ret) - 1);
	ft_memdel((void**)&tmp);
	(*stock)[buf + ret - (char*)ft_memchr(buf, '\n', ret) - 1] = '\0';
	if (stock[0][0] == '\0')
		ft_memdel((void**)stock);
	*(char*)ft_memchr(buf, '\n', ret) = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buf, 0);
	ft_memdel((void**)&tmp);
	return (1);
}

int	ft_test_buf(int ret, char buf[BUFF_SIZE], char **stock, char **line)
{
	int		len;
	char	*tmp;
	char	*tmp2;

	len = ret;
	while (ft_memchr(buf, '\0', len) != NULL)
	{
		ft_memmove(ft_memchr(buf, '\0', len), ft_memchr(buf, '\0', len) + 1,
				ret - ft_strlen(buf));
		buf[len - 1] = '\0';
		len = len - 1;
	}
	if (ft_memchr(buf, '\n', ret) != NULL)
		return (ft_modif_buf(ret, stock, buf, line));
	tmp = *line;
	tmp2 = ft_strsub(buf, 0, len);
	*line = ft_strjoin(*line, tmp2, 0);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&tmp2);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stock;
	char		buf[BUFF_SIZE];
	int			ret;

	if (line == NULL)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	line[0][0] = '\0';
	if (stock != NULL && ft_test_stock(line, &stock))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_test_buf(ret, buf, &stock, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && line[0][0] == '\0')
		return (0);
	ft_memdel((void**)&stock);
	return (1);
}
