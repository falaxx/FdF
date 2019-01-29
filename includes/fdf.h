/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:37:42 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 15:40:07 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <math.h>
# define WIN_SIZEX 2048
# define WIN_SIZEY 1152

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_rgb;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
	t_rgb			*rgb;
}					t_pos;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_pos			***tab;
	t_pos			***tab2;
	void			*img;
	unsigned char	*s_img;
	int				color;
	int				mode;
	int				line;
	int				swap;
	int				menu;
	int				xa;
	int				xb;
	int				ya;
	int				yb;
	int				za;
	int				zb;
	int				tmp_z;
	int				current;
	int				i;
	int				width;
	int				high;
	float			space;
	float			xteta;
	float			yteta;
	int				x_dif;
	int				y_dif;
	float			zspace;
	char			**av;
	int				x_ctr;
	int				y_ctr;
}					t_fdf;

void				ft_structtab3(int i, t_fdf *lst,
					char **split, char **tabchar);
void				ft_free_tabchar(char *tabchar);
void				ft_linex2(t_fdf *lst);
void				ft_liney2(t_fdf *lst);
void				ft_para(t_fdf *lst, int x, int y);
int					ft_menu(t_fdf *lst, int sizex, int sizey);
int					ft_random7();
void				ft_startspace(t_fdf *lst);
int					ft_expose(void *param);
void				ft_gradient(t_fdf *lst, t_rgb *rgb);
void				ft_calcul_z(t_fdf *lst, int current);
int					ft_percent(int start, int end, int current);
void				ft_color(t_fdf *lst, t_rgb *rgb);
void				ft_color_list(t_rgb *rgb, int color);
void				ft_color_list2(t_rgb *rgb, int color);
void				ft_color_list3(t_rgb *rgb, int color);
void				ft_recenter(t_fdf *lst);
void				ft_lightup_pixel2(t_fdf *lst, int x, int y, t_rgb *rgb);
void				ft_lightup_pixel(t_fdf *lst, int x, int y, t_rgb *rgb);
int					ft_init_image(t_fdf *lst, int sizex, int sizey);
void				ft_highwidth(t_fdf *lst, char **av);
void				ft_init_list(t_fdf *lst);
void				ft_parsing_to_trace(t_fdf *lst);
void				ft_parsing(t_fdf *lst, char **av);
void				ft_trace(t_fdf *lst, int i, int j);
void				ft_find_center(t_fdf *lst);
void				ft_rotation(t_fdf *lst);
int					mouse_move(int x, int y, void *param);
int					mouse_hook(int key, int i, int j, void *param);
int					key_hook(int key, void *param);
void				ft_iso(t_fdf *lst, int i, int j);
#endif
