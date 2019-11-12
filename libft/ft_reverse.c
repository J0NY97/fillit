/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:53:02 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/29 13:38:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char		*ft_reverse(char *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (0);
	while (i > 0)
	{
		str[j] = s[i - 1];
		i--;
		j++;
	}
	return (str);
}
