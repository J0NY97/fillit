/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/23 12:07:09 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./fillit.h"

int ft_2dstrchr(char **str, char c)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (ft_strchr(str[x], c))
			return (1);
		x++;
	}
	return (0);
}

int		pre_rec(int how_many, char **block)
{
	int x;
	int y;
	char **tmp;
	int size;
	char **map;

	x = 0;
	y = 1;
	how_many = 4;
	size = 4;
	map = makenewblock('.', size);
	printf("pre_rec\n");
	recursive(block, map, x, y, how_many);
			//if (x == how_many)
			//{
			//	x = 0;
			//	map = makenewblock('.', size++);
			//}
	print_block(map);
	return (1);
}

int	recursive(char **block, char **map, int x, int y, int how_many)
{
	int tmp;
	int tmp2;
	
	tmp2 = how_many;
	tmp = y;
	//if (block[x] == 0)
	//	x = 0;
	if (ft_2dstrchr(map, 'A' + x) == 0)
	{
		if((actualinsert(map, strto2dstr(block[x]), '.', '#', x) == 1))
		{
			printf("%d\n", ('A' + x));
			printf("actualinsert\n");
			x++;
			if (how_many == x)
			{
				printf("return (1);");
				return (1);
			}
			print_block(map);
			printf("End od actual\n");
			return(recursive(block, map, x, y, how_many));
		}
	}
	else
	{
		while(how_many != x)
		{
			map_char_delet(map, 'A' + how_many);
			how_many--;

		}
		while (y >= 0)
		{
			map_char_delet(map, 'A' + (x - y));
			y--;
		}
		tmp++;
		y = tmp;
		how_many = tmp2;
		return(recursive(block, map, x, y, how_many));
	}
	return (-1);
}

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
		printf("1: %s\n", str[0]);
		printf("2: %s\n", str[1]);
		printf("3: %s\n", str[2]);
		printf("4: %s\n", str[3]);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");		
		pre_rec(how_many, str);
		return (1);
	}
	return (0);
}
