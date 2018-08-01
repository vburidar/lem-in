/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:59:33 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/04 17:02:10 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_lem_in.h"

void	ft_white_pixel(t_coord curseur, char *str)
{
	str[curseur.y * 1920 * 4 + curseur.x * 4] = (char)255;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 1] = (char)255;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 2] = (char)255;
}

void	ft_blue_pixel(t_coord curseur, char *str)
{
	str[curseur.y * 1920 * 4 + curseur.x * 4] = (char)255;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 1] = (char)0;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 2] = (char)0;
}

void	ft_green_pixel(t_coord curseur, char *str)
{
	str[curseur.y * 1920 * 4 + curseur.x * 4] = (char)0;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 1] = (char)255;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 2] = (char)0;
}

void	ft_red_pixel(t_coord curseur, char *str)
{
	str[curseur.y * 1920 * 4 + curseur.x * 4] = (char)0;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 1] = (char)0;
	str[curseur.y * 1920 * 4 + curseur.x * 4 + 2] = (char)255;
}
