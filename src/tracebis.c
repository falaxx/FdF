/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracebis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:58:11 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 14:32:25 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pre_x2(t_fdf *lst)
{
	lst->line = 1;
	lst->swap = 0;
	if (lst->xb < lst->xa)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
		lst->swap = 1;
	}
	lst->current = lst->xa;
	ft_lightup_pixel2(lst, lst->xa, lst->ya, lst->tab2[0][0]->rgb);
}

void	ft_linex2(t_fdf *lst)
{
	float	tmp;
	float	d;

	ft_pre_x2(lst);
	tmp = lst->ya;
	d = lst->yb - lst->ya;
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
		ft_lightup_pixel2(lst, lst->xa, lst->ya, lst->tab2[0][0]->rgb);
	}
}

void	ft_pre_y2(t_fdf *lst)
{
	lst->line = 2;
	lst->swap = 0;
	if (lst->yb < lst->ya)
	{
		ft_swap(&lst->xa, &lst->xb);
		ft_swap(&lst->ya, &lst->yb);
		lst->swap = 1;
	}
	lst->current = lst->ya;
	ft_lightup_pixel2(lst, lst->xa, lst->ya, lst->tab2[0][0]->rgb);
}

void	ft_liney2(t_fdf *lst)
{
	float tmp;
	float d;

	ft_pre_y2(lst);
	tmp = lst->xa;
	d = lst->xb - lst->xa;
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
		ft_lightup_pixel2(lst, lst->xa, lst->ya, lst->tab2[0][0]->rgb);
	}
}
