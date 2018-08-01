/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 16:04:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/02 17:36:48 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu_lem_in.h"

int		ft_sens(int depart, int arrivee)
{
	if (arrivee > depart)
		return (1);
	else
		return (-1);
}
