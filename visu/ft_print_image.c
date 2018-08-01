/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:03:20 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/03 23:11:03 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "visu_lem_in.h"
#include "LIBFT/libft.h"

char	*ft_get_image(void *image)
{
	char	*str;
	int		*params;

	if (!(params = (int*)(malloc(3 * (sizeof(int))))))
		exit(1);
	str = mlx_get_data_addr(image, params, params + 1, params + 2);
	free(params);
	return (str);
}

void	ft_color_pixel(char *str, t_coord coord)
{
	if (coord.y * 1920 * 4 + coord.x * 4 > 0
		&& (coord.y * 1920 * 4 + coord.x * 4 + 2) < 1920 * 1080 * 4)
	{
		str[coord.y * 1920 * 4 + coord.x * 4] = (char)255;
		str[coord.y * 1920 * 4 + coord.x * 4 + 1] = (char)255;
		str[coord.y * 1920 * 4 + coord.x * 4 + 2] = (char)255;
	}
}

void	ft_segx(char *str, t_coord a, t_coord b)
{
	t_coord curseur;

	curseur.x = a.x;
	curseur.y = a.y;
	while (curseur.x != b.x || curseur.y != b.y)
	{
		curseur.x = curseur.x + ft_sens(a.x, b.x);
		while ((10000 * abs(curseur.y - a.y)) / abs(curseur.x - a.x)
				< (10000 * abs(b.y - a.y)) / abs(b.x - a.x))
			curseur.y = curseur.y + ft_sens(a.y, b.y);
		ft_color_pixel(str, curseur);
	}
}

void	ft_seg_image(char *str, t_coord a, t_coord b)
{
	t_coord	curseur;

	curseur.x = a.x;
	curseur.y = a.y;
	if (abs(curseur.x - b.x) > abs(curseur.y - b.y))
	{
		ft_segx(str, a, b);
		ft_color_pixel(str, curseur);
	}
	else
	{
		while (curseur.x != b.x || curseur.y != b.y)
		{
			curseur.y = curseur.y + ft_sens(a.y, b.y);
			while ((10000 * abs(curseur.x - a.x)) / abs(curseur.y - a.y)
					< (10000 * abs(b.x - a.x)) / abs(b.y - a.y))
				curseur.x = curseur.x + ft_sens(a.x, b.x);
			ft_color_pixel(str, curseur);
		}
		ft_color_pixel(str, curseur);
	}
}

void	ft_print_image(t_visu *visu, void *mlx, void *window, t_col *col)
{
	void	*image;
	char	*str;
	t_link	*curs_link;
	t_room	*curs_room;

	image = mlx_new_image(mlx, 1920, 1080);
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	str = ft_get_image(image);
	curs_room = visu->data->room;
	while (curs_room->name)
	{
		curs_link = curs_room->lst_link;
		while (curs_link)
		{
			ft_seg_image(str, curs_room->coord, curs_link->link->coord);
			curs_link = curs_link->nxt;
		}
		ft_print_room(curs_room, str, col);
		curs_room = curs_room->nxt;
	}
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	mlx_destroy_image(mlx, image);
}
