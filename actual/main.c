/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:37 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/23 15:11:34 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int main(int ac, char **av)
{
	char	**str;
	int		how_many;

	str = NULL;
	if (ac == 2)
	{
		printf("Here");
		how_many = part1(av[1]);
		printf("%d\n", how_many);
		if (how_many < 1)
		{
			printf("Too few tetrimons in file!\n");
			return (1);
		}
		str = part2(av[1], how_many, str);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
		for (int i = 0; str[i] && i < how_many; i++)
		{
			printf("%d:\n%s\n", i, str[i]);
			if (!validity_check(str[i], '.', '#'))
			{
				ft_putstr("error\n");
				return (1);
			}
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		pre_rec(how_many, str);
	}
	return (0);
}
