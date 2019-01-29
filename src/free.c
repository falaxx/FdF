/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:10:27 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 15:10:30 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tabchar(char *tabchar)
{
	ft_memdel((void **)&tabchar);
	exit(0);
}

void	ft_structtab3(int i, t_fdf *lst, char **split, char **tabchar)
{
	int j;

	j = 0;
	while (split[j])
		j++;
	if (j != lst->width)
	{
		i = 0;
		while (i < lst->high)
		{
			ft_memdel((void **)&tabchar[i]);
			i++;
		}
		j = 0;
		while (split[j])
		{
			ft_memdel((void **)&split[j]);
			j++;
		}
		ft_memdel((void **)&tabchar);
		ft_memdel((void **)&split);
		ft_putstr("invalid file\n");
		exit(0);
	}
}
