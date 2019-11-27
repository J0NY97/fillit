/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:50:58 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/25 12:25:23 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	char			*rdest;
	unsigned char	*rsrc;

	rdest = (char *)dest;
	rsrc = (unsigned char *)src;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		rdest[i] = rsrc[i];
		if (rsrc[i] == cc)
			return (&rdest[i + 1]);
		i++;
	}
	return (NULL);
}
