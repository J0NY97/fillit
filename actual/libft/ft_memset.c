/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:14:06 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/26 16:50:37 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*strstr;

	strstr = (char *)str;
	i = 0;
	while (i < n)
	{
		strstr[i] = c;
		i++;
	}
	return (strstr);
}
