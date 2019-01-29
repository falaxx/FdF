/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_to_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:27:03 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 11:34:41 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_tab2(t_fdf *lst)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (i < lst->high)
	{
		while (j < lst->width)
		{
			if (lst->mode != 3)
				ft_iso(lst, i, j);
			else
				ft_para(lst, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	ft_find_center(lst);
	ft_recenter(lst);
}

void	ft_parsing_to_trace2(t_fdf *lst, int i, int j)
{
	i = 0;
	j = 0;
	while (j < lst->width)
	{
		while (i < lst->high - 1)
		{
			lst->xa = lst->tab2[i][j]->x;
			lst->ya = lst->tab2[i][j]->y;
			lst->za = lst->tab2[i][j]->z;
			lst->xb = lst->tab2[i + 1][j]->x;
			lst->yb = lst->tab2[i + 1][j]->y;
			lst->zb = lst->tab2[i + 1][j]->z;
			ft_trace(lst, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_color_fill(t_fdf *lst)
{
	if (lst->mode == 1 || lst->mode == 3)
		ft_color_list(lst->tab2[0][0]->rgb, lst->color);
	fill_tab2(lst);
}

void	ft_parsing_to_trace(t_fdf *lst)
{
	int i;
	int j;

	i = 0;
	ft_color_fill(lst);
	while (i < lst->high)
	{
		j = 0;
		while (j < lst->width - 1)
		{
			lst->xa = lst->tab2[i][j]->x;
			lst->ya = lst->tab2[i][j]->y;
			lst->za = (lst->zspace) ? lst->tab2[i][j]->z : 0;
			lst->xb = lst->tab2[i][j + 1]->x;
			lst->yb = lst->tab2[i][j + 1]->y;
			lst->zb = (lst->zspace) ? lst->tab2[i][j + 1]->z : 0;
			ft_trace(lst, i, j);
			j++;
		}
		i++;
	}
	ft_parsing_to_trace2(lst, i, j);
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 0, 0);
	if (lst->menu == 1)
		ft_menu(lst, 400, 400);
}
