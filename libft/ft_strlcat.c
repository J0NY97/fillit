/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:48:38 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/23 09:36:49 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	int		slen;
	int		dlen;

	x = 0;
	y = 0;
	slen = ft_strlen(src);
	while (dest[x] && x < size)
	{
		x++;
	}
	dlen = x;
	while (size > (x + 1) && src[y])
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (x < size)
		dest[x] = '\0';
	return (dlen + slen);
}
