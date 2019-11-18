/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:45:18 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/25 14:18:35 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*rstr1;
	char	*rstr2;

	rstr1 = (char *)str1;
	rstr2 = (char *)str2;
	i = 0;
	if (!n || rstr1 == rstr2)
		return (str1);
	while (i < n)
	{
		rstr1[i] = rstr2[i];
		i++;
	}
	return (rstr1);
}
