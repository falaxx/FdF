/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:01:58 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 14:59:26 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*lst;

	if (ac != 2)
	{
		ft_putstr("usage : ./fdf source_file");
		return (0);
	}
	if (!(lst = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	lst->av = av;
	lst->xteta = 0.52;
	lst->yteta = 0.52;
	ft_parsing(lst, av);
	ft_parsing_to_trace(lst);
	mlx_hook(lst->win_ptr, 2, 0, key_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 4, 0, mouse_hook, (void *)lst);
	mlx_hook(lst->win_ptr, 17, 0, ft_expose, (void *)lst);
	mlx_loop(lst->mlx_ptr);
	return (0);
}
