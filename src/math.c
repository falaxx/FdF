/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:40:23 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 12:03:01 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 100 : (placement / distance) * 100);
}

void	ft_calcul_z(t_fdf *lst, int current)
{
	int percent;

	if (lst->line == 1)
		percent = 100 - (ft_percent(current, lst->xb, lst->xa));
	else
		percent = 100 - (ft_percent(current, lst->yb, lst->ya));
	if (lst->za < lst->zb)
		lst->tmp_z = (lst->zb == lst->za) ? lst->za : ((abs(lst->zb - lst->za)
		* percent) / 100) + lst->za + 1;
	else
		lst->tmp_z = (lst->zb == lst->za) ? lst->za : ((abs(lst->zb - lst->za)
		* percent) / 100) + lst->zb + 1;
}

int		ft_random7(void)
{
	int random;

	random = rand() * 1;
	if (random < 268435455)
		return (1);
	else if (random < 268435455 * 2)
		return (2);
	else if (random < 268435455 * 3)
		return (3);
	else if (random < 268435455 * 4)
		return (4);
	else if (random < 268435455 * 5)
		return (5);
	else if (random < 268435455 * 6)
		return (6);
	else if (random < 268435455 * 7)
		return (7);
	else
		return (8);
}
