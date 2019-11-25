/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/25 14:52:07 by nneronin         ###   ########.fr       */
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
	int timeout;

	x = 0;
	y = 1;
	size = 5; // fixa senar
	timeout = 0;
	map = makenewblock('.', size);
	printf("pre_rec\n");
	recursive(block, map, x, y, how_many, timeout);
			//if (x == how_many)
			//{
			//	x = 0;
			//	map = makenewblock('.', size++);
			//}
	print_block(map);
	return (1);
}

int	recursive(char **block, char **map, int x, int y, int how_many, int timeout)
{
	int tmp;
	int tmp2;
	
	tmp2 = how_many;
	tmp = y;
	timeout++;
	if (how_many == x || timeout == 50)
	{
		printf("Timeout: %d\n", timeout);
		return (1);
	}
	if (ft_2dstrchr(map, 'A' + x) == 1)
	{
		x++;
		return(recursive(block, map, x, y, how_many, timeout));
	}
	if((actualinsert(map, strto2dstr(block[x]), '.', '#', x) == 1))
	{
		x++;
		printf("V===========================V\n");
		print_block(map);
		printf("x = %d\n", x);
		printf("A===========================A\n");
		if (how_many == x)
			x = 0;
		return(recursive(block, map, x, y, how_many, timeout));
	}
	else
	{
		while (how_many != x)
		{
			map_char_delet(map, 'A' + how_many);
			how_many--;
		}
		while (y >= 0)
		{
			map_char_delet(map, 'A' + (x - y));
			y--;
		}
		//tmp++;
		y = tmp;
		how_many = tmp2;
		printf("what is x: %d\n", x);
		printf("what is y: %d\n", y);
		print_block(map);
		return(recursive(block, map, x, y, how_many, timeout));
	}
	printf("Timeout: %d\n", timeout);
	return (1);
}
