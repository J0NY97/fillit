/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/28 10:20:32 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./fillit.h"

int	pre_rec(char **block, int how_many)
{
	int		i;
	int		size;
	char	**map;

	i = 0;
	size = 2;
	while ((how_many * 4) > (size * size))
		size++;
	map = makenewblock('.', size);
	while (recursion(block, map, i, how_many) == 0)
	{
		free(map);
		map = makenewblock('.', size++);
	}
	print_block(map);
	return (1);
}

int	recursion(char **block, char **map, int i, int how_many)
{
	int y;
	int x;

	y = 0;
	if (i == how_many)
		return (1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (actualinsert(map, strto2dstr(block[i]), x, y, 'A' + i) == 1)
			{
				if (recursion(block, map, i + 1, how_many) == 1)
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
