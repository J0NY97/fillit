/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:07:17 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/26 13:42:47 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*asdf;
	char	*qwer;
	size_t	i;

	asdf = (char *)str1;
	qwer = (char *)str2;
	i = 0;
	if (!n || asdf == qwer)
		return (str1);
	if (qwer < asdf)
	{
		while (n-- > 0)
		{
			asdf[n] = qwer[n];
		}
	}
	else
	{
		while (i < n)
		{
			asdf[i] = qwer[i];
			i++;
		}
	}
	return (asdf);
}
