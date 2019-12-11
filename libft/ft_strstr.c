/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:46:49 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/26 14:16:44 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!str2[y])
		return ((char *)str1);
	while (str1[x])
	{
		y = 0;
		while (str1[x + y] == str2[y] && str1[x + y])
		{
			if (!str2[y + 1])
				return ((char *)&str1[x]);
			y++;
		}
		x++;
	}
	return (0);
}
