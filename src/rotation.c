/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:15:04 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 12:03:53 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_fdf *lst, int x, int y)
{
	int prev_x;
	int prev_y;

	prev_x = lst->tab[x][y]->x + (lst->space * y);
	prev_y = lst->tab[x][y]->y + (lst->space * x);
	lst->tab2[x][y]->x = (prev_x - prev_y) * cos(lst->xteta);
	lst->tab2[x][y]->y = -(lst->tab2[x][y]->z * lst->zspace) + (prev_x + prev_y)
	* sin(lst->yteta);
}

void	ft_para(t_fdf *lst, int x, int y)
{
	lst->tab2[x][y]->x = lst->tab[x][y]->x + lst->space * y + (lst->zspace * 2)
	* lst->tab[x][y]->z;
	lst->tab2[x][y]->y = lst->tab[x][y]->y + lst->space * x + (lst->zspace * 2)
	* lst->tab[x][y]->z;
}
