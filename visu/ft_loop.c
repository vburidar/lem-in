/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:12:24 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 16:05:57 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "visu_lem_in.h"
#include "LIBFT/libft.h"

void	ft_fill_col(char *line, t_col *col)
{
	line++;
	while (*line)
	{
		if (*line == 'L' && *(line - 1) == ' ')
		{
			while (col->nxt)
				col = col->nxt;
			col->nxt = malloc(sizeof(t_col));
			col->nxt->name = ft_get_name(line + 1, '-');
			col = col->nxt;
			col->nxt = NULL;
		}
		line++;
	}
}

t_col	*ft_get_col(void)
{
	char	*line;
	int		i;
	t_col	*col;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	ft_printf("%s\n", line);
	col = malloc(sizeof(t_col));
	col->name = ft_get_name(line + 1, '-');
	col->nxt = NULL;
	ft_fill_col(line, col);
	free(line);
	return (col);
}

int		ft_keyevent(int keyevent, t_visu *visu)
{
	t_col	*col;
	t_col	*tmp;

	if (keyevent == 53)
	{
		ft_free_data(visu->data);
		free(visu);
		exit(1);
	}
	if (keyevent == 125)
	{
		col = ft_get_col();
		ft_print_image(visu, visu->mlx, visu->win, col);
		while (col)
		{
			tmp = col->nxt;
			free(col->name);
			free(col);
			col = tmp;
		}
	}
	return (0);
}

void	ft_loop(t_info *data)
{
	void	*mlx;
	void	*win;
	t_visu	*visu;

	visu = malloc(sizeof(t_visu));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "mlx_42");
	visu->mlx = mlx;
	visu->data = data;
	visu->win = win;
	ft_print_image(visu, visu->mlx, visu->win, NULL);
	mlx_key_hook(win, ft_keyevent, visu);
	mlx_loop(mlx);
}
