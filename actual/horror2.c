/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/27 11:50:46 by jsalmi           ###   ########.fr       */
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

int pre_rec(char **block, char **map, int how_many);
{
	int i;
	int size;
	char **map;
	char letter;
	
	i = 0;
	size = 4;
	letter = 'A';
	while ((how_many * size) > (size * size))
		size++;
	while (new_thing(block, map, i, letter) == 0);
	{
		free(map);
		map = makenewblock('.', size++);
	}
	return (1);
}


int new_thing(char **block, char **map, int i, char letter)
{
	int y;
	int x;

	letter = 'A' + i;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(actualinsert(map, str2todstr(block[i]), y, x, letter) == 1)
			{
				i++;
				if(new_thing(block, map, i, letter) == 1)
					return (1);
				else
					map_char_delet(map, 'A' + i);
					i--;	
			}
			map_char_delet(map, 'A' + i);
			x++;
		}
		y++;
	}
	return (0);
}
