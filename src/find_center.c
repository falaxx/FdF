/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:50:07 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 15:37:05 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_find_center(t_fdf *lst)
{
	if (lst->mode != 3)
	{
		if (lst->tab2[0][0]->x > lst->tab2[lst->high - 1][lst->width - 1]->x)
			lst->x_ctr = lst->tab2[0][0]->x + (abs(lst->tab2[0][0]->x -
			lst->tab2[lst->high - 1][lst->width - 1]->x) / 2);
		else
			lst->x_ctr = lst->tab2[0][0]->x - (abs(lst->tab2[0][0]->x -
			lst->tab2[lst->high - 1][lst->width - 1]->x) / 2);
		if (lst->tab2[0][lst->width - 1]->y > lst->tab2[lst->high - 1][0]->y)
			lst->y_ctr = lst->tab2[0][lst->width - 1]->y -
			(abs(lst->tab2[lst->high - 1][0]->y -
			lst->tab2[0][lst->width - 1]->y) / 2);
		else
			lst->y_ctr = lst->tab2[0][lst->width - 1]->y +
			(abs(lst->tab2[lst->high - 1][0]->y -
			lst->tab2[0][lst->width - 1]->y) / 2);
	}
	else
	{
		lst->x_ctr = lst->width;
		lst->y_ctr = lst->high;
	}
	lst->x_dif = (WIN_SIZEX / 2) - lst->x_ctr;
	lst->y_dif = (WIN_SIZEY / 2) - lst->y_ctr;
}

void	ft_recenter(t_fdf *lst)
{
	int x;
	int y;

	x = 0;
	while (x < lst->high)
	{
		y = 0;
		while (y < lst->width)
		{
			if (lst->mode == 3)
			{
				lst->tab2[x][y]->x += lst->x_dif - (lst->width / 2) *
				lst->space + 100;
				lst->tab2[x][y]->y += lst->y_dif - (lst->high / 2) *
				lst->space;
			}
			else
			{
				lst->tab2[x][y]->x += lst->x_dif;
				lst->tab2[x][y]->y += lst->y_dif;
			}
			y++;
		}
		x++;
	}
}
