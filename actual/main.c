/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:37 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/23 12:59:54 by jsalmi           ###   ########.fr       */
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
		str = part2(av[1], how_many, str);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		for (int i = 0; str[i] && i < how_many; i++)
		{
			printf("%d: %s\n",i, str[i]);
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		pre_rec(how_many, str);
		return (1);
	}
	return (0);
}
