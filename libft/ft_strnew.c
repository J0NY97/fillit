/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:18:47 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/07 12:40:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_memset(str, '\0', size + 1);
	return (str);
}
