/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:21:47 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 14:30:46 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pre_x(t_fdf *lst)
{
	lst->line = 1;
	lst->swap = 0;
	lst->i = 1;
	if (lst->xb < lst->xa)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
		lst->swap = 1;
	}
	lst->current = lst->xa;
}

void	ft_linex(t_fdf *lst, int i, int j)
{
	float	tmp;
	float	d;

	ft_pre_x(lst);
	tmp = lst->ya;
	d = lst->yb - lst->ya;
	ft_color(lst, lst->tab2[i][j]->rgb);
	lst->i = lst->ya > lst->yb ? -1 : 1;
	d /= (lst->xb - lst->xa);
	while (lst->xa != lst->xb)
	{
		lst->xa++;
		tmp = tmp + d;
		if (d > 0)
		{
			if (tmp > lst->ya + 0.5)
				lst->ya += lst->i;
		}
		else
		{
			if (tmp < lst->ya - 0.5)
				lst->ya += lst->i;
		}
		ft_color(lst, lst->tab2[i][j]->rgb);
	}
}

void	ft_pre_y(t_fdf *lst)
{
	lst->line = 2;
	lst->swap = 0;
	lst->i = 1;
	if (lst->yb < lst->ya)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
		lst->swap = 1;
	}
	lst->current = lst->ya;
}

void	ft_liney(t_fdf *lst, int i, int j)
{
	float tmp;
	float d;

	ft_pre_y(lst);
	d = lst->xb - lst->xa;
	tmp = lst->xa;
	ft_color(lst, lst->tab2[i][j]->rgb);
	lst->i = lst->xa > lst->xb ? -1 : 1;
	d /= (lst->yb - lst->ya);
	while (lst->ya != lst->yb)
	{
		lst->ya++;
		tmp = tmp + d;
		if (d > 0)
		{
			if (tmp > lst->xa + 0.5)
				lst->xa += lst->i;
		}
		else
		{
			if (tmp < lst->xa - 0.5)
				lst->xa += lst->i;
		}
		ft_color(lst, lst->tab2[i][j]->rgb);
	}
}

void	ft_trace(t_fdf *lst, int i, int j)
{
	if (abs(lst->xa - lst->xb) > abs(lst->ya - lst->yb))
		ft_linex(lst, i, j);
	else
		ft_liney(lst, i, j);
}
