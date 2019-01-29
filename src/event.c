/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:22:52 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/28 15:37:26 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_hook2(int key, t_fdf *lst)
{
	if (key == 53)
		exit(0);
	if (key == 18)
		lst->mode = 1;
	if (key == 19)
		lst->mode = 2;
	if (key == 20)
		lst->mode = 3;
	if (key == 123)
		lst->xteta += 0.05;
	if (key == 124)
		lst->xteta -= 0.05;
	if (key == 126)
		lst->yteta -= 0.05;
	if (key == 125)
		lst->yteta += 0.05;
	if (key == 78 && lst->zspace > 0.01)
		lst->zspace *= 0.8;
	if (key == 76)
		lst->menu = lst->menu ? 0 : 1;
	if (key == 69 && lst->zspace < 50)
		lst->zspace *= 1.2;
}

void	ft_key_hook3(int key, t_fdf *lst)
{
	if (key == 83)
		lst->color = 1;
	if (key == 84)
		lst->color = 2;
	if (key == 85)
		lst->color = 3;
	if (key == 86)
		lst->color = 4;
	if (key == 87)
		lst->color = 5;
	if (key == 88)
		lst->color = 6;
	if (key == 89)
		lst->color = 7;
	if (key == 91)
		lst->color = 8;
	if (key == 92)
		lst->color = ft_random7();
	if (key == 51)
	{
		ft_startspace(lst);
		lst->xteta = 0.52;
		lst->yteta = 0.52;
	}
}

int		key_hook(int key, void *param)
{
	t_fdf *lst;

	lst = (t_fdf *)param;
	ft_key_hook2(key, lst);
	ft_key_hook3(key, lst);
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst, WIN_SIZEX, WIN_SIZEY);
	ft_parsing_to_trace(lst);
	return (0);
}

int		mouse_hook(int key, int i, int j, void *param)
{
	t_fdf *lst;

	lst = (t_fdf *)param;
	i = j;
	if (key == 4)
	{
		if (lst->space < 40 && lst->zspace < 50)
		{
			lst->space *= 1.2;
			lst->zspace *= 1.2;
		}
	}
	if (key == 5)
	{
		if (lst->space > 0)
		{
			lst->space *= 0.8;
			lst->zspace *= 0.8;
		}
	}
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst, WIN_SIZEX, WIN_SIZEY);
	ft_parsing_to_trace(lst);
	return (0);
}

int		ft_expose(void *param)
{
	t_fdf *lst;

	lst = (t_fdf *)param;
	exit(0);
}
