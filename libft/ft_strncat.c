/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:43:54 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/31 14:07:31 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = ft_strlen(dest);
	while (i < n && src[i])
	{
		dest[i + k] = src[i];
		i++;
	}
	dest[i + k] = '\0';
	return (dest);
}
