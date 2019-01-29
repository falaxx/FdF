/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:41:37 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 14:47:51 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_startspace(t_fdf *lst)
{
	if (lst->high < 20)
	{
		lst->space = 20;
		lst->zspace = 10;
	}
	if (lst->high >= 20 && lst->high < 50)
	{
		lst->space = 10;
		lst->zspace = 5;
	}
	if (lst->high >= 50)
	{
		lst->space = 4;
		lst->zspace = 2;
	}
	lst->color = 2;
}

void	ft_init_list2(t_fdf *lst, int i, int u)
{
	i = 0;
	if (!(lst->tab2 = (t_pos***)malloc(sizeof(t_pos**) * lst->high)))
		exit(0);
	while (i < lst->high)
	{
		if (!(lst->tab2[i] = (t_pos**)malloc(sizeof(t_pos*) * lst->width)))
			exit(0);
		while (u < lst->width)
		{
			if (!(lst->tab2[i][u] = (t_pos*)malloc(sizeof(t_pos))))
				exit(0);
			if (!(lst->tab2[i][u]->rgb = (t_rgb*)malloc(sizeof(t_rgb))))
				exit(0);
			u++;
		}
		i++;
		u = 0;
	}
	ft_startspace(lst);
	lst->mlx_ptr = mlx_init();
	lst->win_ptr = mlx_new_window(lst->mlx_ptr, WIN_SIZEX, WIN_SIZEY, "FdF");
	lst->mode = 1;
	lst->menu = 1;
	ft_init_image(lst, WIN_SIZEX, WIN_SIZEY);
}

void	ft_init_list(t_fdf *lst)
{
	int i;
	int u;

	i = 0;
	u = 0;
	if (!(lst->tab = (t_pos***)malloc(sizeof(t_pos**) * lst->high)))
		exit(0);
	while (i < lst->high)
	{
		if (!(lst->tab[i] = (t_pos**)malloc(sizeof(t_pos*) * lst->width)))
			exit(0);
		while (u < lst->width)
		{
			if (!(lst->tab[i][u] = (t_pos*)malloc(sizeof(t_pos))))
				exit(0);
			if (!(lst->tab[i][u]->rgb = (t_rgb*)malloc(sizeof(t_rgb))))
				exit(0);
			u++;
		}
		i++;
		u = 0;
	}
	ft_init_list2(lst, i, u);
}
