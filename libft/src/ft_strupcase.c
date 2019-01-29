/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:52:13 by jgehin            #+#    #+#             */
/*   Updated: 2018/11/19 13:52:25 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		if (str[ct] >= 97 && str[ct] <= 122)
			str[ct] = str[ct] - 32;
		++ct;
	}
	return (str);
}
