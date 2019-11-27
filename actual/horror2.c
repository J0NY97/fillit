/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/27 13:19:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./fillit.h"

int pre_rec(char **block, int how_many)
{
	int i;
	int size;
	char **map;
	char letter;
	
	i = 0;
	size = 2;
	letter = 'A';
	while ((how_many * 4) > (size * size))
		size++;
	map = makenewblock('.', size);
	while (new_thing(block, map, i, letter, how_many) == 0)
	{
		free(map);
		map = makenewblock('.', size++);
	}	
	print_block(map);
	return (1);
}


int new_thing(char **block, char **map, int i, char letter, int how_many)
{
	int y;
	int x;

	y = 0;
	if (i == how_many)
		return(1);
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(actualinsert(map, strto2dstr(block[i]), y, x, letter + i) == 1)
			{
				if(new_thing(block, map, i + 1, letter, how_many) == 1)
					return (1);
				else
					map_char_delet(map, 'A' + i + 1);
			}
			map_char_delet(map, 'A' + i);
			x++;
		}
		y++;
	}
	return (0);
}
