/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:37 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 12:45:56 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		usage(void)
{
	ft_putstr("usage: ./fillit target_file\n");
	return (1);
}

int		error(void)
{
	ft_putstr("error\n");
	return (1);
}

int main(int ac, char **av)
{
	char	**str;
	int		how_many;

	str = NULL;
	if (ac == 2)
	{
	//	printf("Here");
		how_many = part1(av[1]);
	//	printf("%d\n", how_many);
		if (how_many < 1)
		{
		//	printf("Too few tetrimons in file!\n");
			return (error());
		}
		str = part2(av[1], how_many, str);
	//	printf("~~~~~~~~~~~Validity Check~~~~~~~~~~~\n");	
		for (int i = 0; str[i] && i < how_many; i++)
		{
	//		printf("%d:\n%s\n", i, str[i]);
			if (!validity_check(str[i], '.', '#'))
				return (error());
		}
	//	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		pre_rec(str, how_many);
	}
	else
		return (usage());
	return (0);
}
