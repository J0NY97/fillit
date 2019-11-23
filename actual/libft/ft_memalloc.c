/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:06:57 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/07 12:54:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	char *this;

	if (!(this = (void *)malloc(sizeof(size_t) * size)))
		return (0);
	ft_bzero(this, size);
	return (this);
}
