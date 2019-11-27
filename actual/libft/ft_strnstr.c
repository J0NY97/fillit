/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:31:37 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/26 14:22:18 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (!str2[y])
		return ((char *)str1);
	while (str1[x] && x < n)
	{
		y = 0;
		while (str1[x + y] == str2[y] && str1[x + y] && x + y < n)
		{
			if (!str2[y + 1])
				return ((char *)&str1[x]);
			y++;
		}
		x++;
	}
	return (0);
}
