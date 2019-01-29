/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:39:22 by fmerding          #+#    #+#             */
/*   Updated: 2019/01/28 15:07:44 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_high(t_fdf *lst, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = 0;
	line = NULL;
	lst->high = 0;
	fd = open(av[1], O_RDONLY);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		if (i < 0)
		{
			ft_putstr("invalid file\n");
			exit(0);
		}
		ft_memdel((void **)&line);
		if (i == 0)
			break ;
		lst->high++;
	}
	ft_memdel((void **)&line);
	close(fd);
}

char	**ft_parsingchar(t_fdf *lst, char **av, char **tabchar)
{
	int		fd;
	int		i;
	int		u;
	char	*line;

	line = NULL;
	i = 1;
	u = 0;
	fd = open(av[1], O_RDONLY);
	if (!(tabchar = (char**)malloc(sizeof(char*) * (lst->high))))
		exit(0);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		if (i == 0)
			break ;
		if (!(tabchar[u] = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1))))
			ft_free_tabchar(*tabchar);
		tabchar[u] = ft_strcpy(tabchar[u], line);
		u++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
	return (tabchar);
}

void	ft_structtab2(int i, t_fdf *lst, char **split, char **tabchar)
{
	int j;

	ft_structtab3(i, lst, split, tabchar);
	j = 0;
	while (j < lst->width)
	{
		lst->tab[i][j]->x = j;
		lst->tab[i][j]->y = i;
		lst->tab[i][j]->z = ft_atoi(split[j]);
		lst->tab2[i][j]->z = ft_atoi(split[j]);
		ft_memdel((void **)&split[j]);
		j++;
	}
	ft_memdel((void **)&split);
}

void	ft_parsingstruct(t_fdf *lst, char **tabchar)
{
	int		j;
	int		i;
	char	**split;

	i = 0;
	j = 0;
	split = NULL;
	lst->width = 0;
	while (i < lst->high)
	{
		j = 0;
		split = ft_strsplit(tabchar[i], ' ');
		if (lst->width == 0)
		{
			while (split[j])
				j++;
			lst->width = j;
			ft_init_list(lst);
		}
		ft_structtab2(i, lst, split, tabchar);
		i++;
	}
}

void	ft_parsing(t_fdf *lst, char **av)
{
	char	**tabchar;
	int		i;
	int		u;

	tabchar = NULL;
	u = 0;
	ft_high(lst, av);
	tabchar = ft_parsingchar(lst, av, tabchar);
	ft_parsingstruct(lst, tabchar);
	i = 0;
	while (i < lst->high)
	{
		ft_memdel((void **)&tabchar[i]);
		i++;
	}
	ft_memdel((void **)&tabchar);
}
