/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:46:47 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 15:10:20 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lightup_pixel(t_fdf *lst, int x, int y, t_rgb *rgb)
{
	int new_x;

	if (x < WIN_SIZEX && y < WIN_SIZEY && x > 0 && y > 0)
	{
		new_x = x * 4 + ((WIN_SIZEX * 4) * y);
		lst->s_img[new_x] = rgb->r;
		lst->s_img[new_x + 1] = rgb->g;
		lst->s_img[new_x + 2] = rgb->b;
		lst->s_img[new_x + 3] = rgb->alpha;
	}
}

void	ft_lightup_pixel2(t_fdf *lst, int x, int y, t_rgb *rgb)
{
	int new_x;

	if (x < 400 && y < 400 && x > 0 && y > 0)
	{
		new_x = x * 4 + ((400 * 4) * y);
		lst->s_img[new_x] = rgb->r;
		lst->s_img[new_x + 1] = rgb->g;
		lst->s_img[new_x + 2] = rgb->b;
		lst->s_img[new_x + 3] = rgb->alpha;
	}
}

int		ft_init_image(t_fdf *lst, int sizex, int sizey)
{
	int size;
	int	bpp;
	int endian;

	size = sizex;
	bpp = 4;
	endian = 0;
	lst->img = mlx_new_image(lst->mlx_ptr, sizex, sizey);
	lst->s_img = (unsigned char*)(mlx_get_data_addr(lst->img, &(bpp), &(size),
	&(endian)));
	return (0);
}
