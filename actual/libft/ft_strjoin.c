/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:00:25 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 16:14:42 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	else if (s1)
		size = ft_strlen(s1);
	else if (s2)
		size = ft_strlen(s2);
	else
		return (0);
	if (!(str = ft_memalloc(size)))
		return (0);
	if (s1)
		ft_strcpy(str, s1);
	else
		ft_strcpy(str, s2);
	if (s1 && s2)
		ft_strcat(str, s2);
	return (str);
}
