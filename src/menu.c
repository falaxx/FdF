/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:52:01 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/29 18:31:39 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace2(t_fdf *lst)
{
	if (abs(lst->xa - lst->xb) > abs(lst->ya - lst->yb))
		ft_linex2(lst);
	else
		ft_liney2(lst);
}

void	ft_contour(t_fdf *lst, int sizex, int sizey)
{
	ft_color_list(lst->tab2[0][0]->rgb, 1);
	lst->xa = 1;
	lst->ya = 1;
	lst->za = 0;
	lst->xb = sizex - 1;
	lst->yb = 1;
	lst->zb = 0;
	ft_trace2(lst);
	lst->xa = sizex - 1;
	lst->ya = 1;
	lst->xb = sizex - 1;
	lst->yb = sizey - 1;
	ft_trace2(lst);
	lst->xa = 1;
	lst->ya = sizey - 1;
	lst->xb = sizex - 1;
	lst->yb = sizey - 1;
	ft_trace2(lst);
	lst->xa = 1;
	lst->ya = 1;
	lst->xb = 1;
	lst->yb = sizey - 1;
	ft_trace2(lst);
}

int		ft_menu(t_fdf *lst, int sizex, int sizey)
{
	mlx_destroy_image(lst->mlx_ptr, lst->img);
	ft_init_image(lst, sizex, sizey);
	ft_contour(lst, sizex, sizey);
	mlx_put_image_to_window(lst->mlx_ptr, lst->win_ptr, lst->img, 50, 50);
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 65, 0xFFDD60,
		"COMMANDE :");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 125, 0xFFFF90,
		"Fleches directionelles = Rotation");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 160, 0xFFFF90,
		"'+' et '-' = Perspective");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 195, 0xFFFF90,
		"Scroll souris = Zoom");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 230, 0xFFFF90,
		"Touches std 1, 2, 3 = Choix du mode");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 265, 0xFFFF90,
		"Touches num [1-8] = Choix des couleurs");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 300, 0xFFFF90,
		"Touches num 9 = Couleurs random");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 335, 0xFFFF90,
		"Echap = Fermer");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 370, 0xFFFF90,
		"Enter = Afficher/Cacher les commandes");
	mlx_string_put(lst->mlx_ptr, lst->win_ptr, 60, 405, 0xFFFF90,
		"Delete = Reset de la map");
	return (0);
}
