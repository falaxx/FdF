/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:53:07 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 11:49:05 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(t_fdf *lst, t_rgb *rgb)
{
	if (lst->mode == 1 || lst->mode == 3)
		ft_lightup_pixel(lst, lst->xa, lst->ya, lst->tab2[0][0]->rgb);
	else if (lst->mode == 2)
	{
		ft_calcul_z(lst, lst->current);
		if (lst->tmp_z < 1)
			lst->color = 3;
		else if (lst->tmp_z >= 1 && lst->tmp_z < 140)
			lst->color = 2;
		else if (lst->tmp_z >= 140 && lst->tmp_z < 210)
			lst->color = 5;
		else
			lst->color = 4;
		ft_color_list(rgb, lst->color);
		ft_lightup_pixel(lst, lst->xa, lst->ya, rgb);
	}
}

void	ft_color_list(t_rgb *rgb, int color)
{
	if (color == 1)
	{
		rgb->r = 20;
		rgb->g = 40;
		rgb->b = 255;
		rgb->alpha = 20;
	}
	else if (color == 2)
	{
		rgb->r = 50;
		rgb->g = 255;
		rgb->b = 50;
		rgb->alpha = 0;
	}
	else if (color == 3)
	{
		rgb->r = 255;
		rgb->g = 145;
		rgb->b = 0;
		rgb->alpha = 0;
	}
	else
		ft_color_list2(rgb, color);
}

void	ft_color_list2(t_rgb *rgb, int color)
{
	if (color == 4)
	{
		rgb->r = 255;
		rgb->g = 255;
		rgb->b = 255;
		rgb->alpha = 0;
	}
	else if (color == 5)
	{
		rgb->r = 0;
		rgb->g = 85;
		rgb->b = 180;
		rgb->alpha = 0;
	}
	else if (color == 6)
	{
		rgb->r = 0;
		rgb->g = 245;
		rgb->b = 245;
		rgb->alpha = 0;
	}
	else
		ft_color_list3(rgb, color);
}

void	ft_color_list3(t_rgb *rgb, int color)
{
	if (color == 7)
	{
		rgb->r = 255;
		rgb->g = 80;
		rgb->b = 240;
		rgb->alpha = 0;
	}
	else if (color == 8)
	{
		rgb->r = 40;
		rgb->g = 150;
		rgb->b = 255;
		rgb->alpha = 0;
	}
}
