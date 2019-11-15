/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:41:56 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/22 13:32:24 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		min;

	min = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n += 2000000000;
			min = 1;
		}
		n *= -1;
		ft_putchar_fd('-', fd);
		if (min)
			ft_putchar_fd('2', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
