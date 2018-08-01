/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:46:14 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 13:01:50 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_inner_getwchar(wchar_t wc, char wcs[MB_CUR_MAX + 1])
{
	if ((wc <= 0x7f && MB_CUR_MAX >= 1) || (wc <= 0xff && MB_CUR_MAX == 1))
		wcs[0] = (char)wc;
	else if (wc <= 0x7ff && MB_CUR_MAX >= 2)
	{
		wcs[0] = (char)(wc >> 6 | 192);
		wcs[1] = (char)((wc & 63) | 128);
	}
	else if (wc <= 0xffff && MB_CUR_MAX >= 3)
	{
		wcs[0] = (char)(wc >> 12 | 0xe0);
		wcs[1] = (char)((wc >> 6 & 0x3f) | 0x80);
		wcs[2] = (char)((wc & 0x3f) | 0x80);
	}
	else if (wc <= 0x10ffff && MB_CUR_MAX >= 4)
	{
		wcs[0] = (char)(wc >> 18 | 0xe0);
		wcs[1] = (char)((wc >> 12 & 0x3f) | 0x80);
		wcs[2] = (char)((wc >> 6 & 0x3f) | 0x80);
		wcs[2] = (char)((wc & 0x3f) | 0x80);
	}
	return (ft_strdup(wcs));
}

char		*ft_getwchar(wchar_t wc)
{
	char	wcs[MB_CUR_MAX + 1];

	ft_bzero(wcs, MB_CUR_MAX + 1);
	return (ft_inner_getwchar(wc, wcs));
}
