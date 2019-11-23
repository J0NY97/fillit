/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:02:02 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/28 12:42:59 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_itoa(int n)
{
	int		nbrcount;
	int		i;
	char	*str;
	int		neg;

	i = 0;
	nbrcount = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (nbrcount + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	neg = n < 0 ? -1 : 0;
	n *= n < 0 ? -1 : 1;
	while (nbrcount + neg > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
		nbrcount--;
	}
	neg == -1 ? str[i] = '-' : 0;
	i += neg == -1 ? 1 : 0;
	str[i] = '\0';
	str = ft_reverse(str);
	return (str);
}
