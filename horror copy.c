/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/22 14:22:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	print_block(char **block)
{
	int i = 0;

	while (block[i])
	{
		printf("%s\n", block[i]);
		i++;
	}
}

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

int pre_rec(int how_many, char **block)
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
	while (rec(block, map, x, y, how_many) == 0)
	{
			x++;
			//if (x == how_many)
			//{
			//	x = 0;
			//	map = makenewblock('.', size++);
			//}
	}
	print_block(map);
	return (1);
}

int	rec(char **block, char **map, int x, int y, int how_many)
{
	int tmp;
	int tmp2;
	
	tmp2 = how_many;
	tmp = y;
	if (block[x] == 0)
		x = 0;
	if((actualinsert(map, strto2dstr(block[x]), x) == 1) && (ft_2dstrchr(map, 'A' + x) == 0))
	{
		x++;
		if (how_many == x)
			return (1);
		return(rec(block, map, x, y);
	}
	else
	{
		while(how_many != x)
		{
			map_char_delet(map, 'A' + how_many);
			how_many--;

		}
		//map_char_delet(map, 'A' + how_many);
		while (y >= 0)
		{
			map_char_delet(map, 'A' + (x - y));
			y--;
		}
		tmp++;
		y = tmp;
		how_many = tmp2;
		return(rec(block, map, x, y, how_many);
	}
}

int main(int ac, char **av)
{
	char	**str;
	int		how_many;
	
	str = NULL;
	if (ac == 2)
	{
		how_many = part1(av);
		printf("%d\n", how_many);
		str = part2(av, how_many, str);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("1: %s\n", str[0]);
		printf("2: %s\n", str[1]);
		printf("3: %s\n", str[2]);
		printf("4: %s\n", str[3]);
		pre_rec(how_many, str);
		return (1);
	}
	return (0);
}
