/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjointest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:38:31 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/15 16:46:23 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
	char **str;
	str[0] = ft_strnew(0);
	str[0] = ft_strdup("....");
	printf("1st strjoin: %s\n", str[0] = ft_strjoin(str[0], "\n"));
	printf("2nd strjoin: %s\n", str[0] = ft_strjoin(str[0], "...."));
	printf("final versi: %s\n", str[0]);
	return (0);
}
