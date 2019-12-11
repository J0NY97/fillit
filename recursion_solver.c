/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/12/05 16:08:44 by jsalmi           ###   ########.fr       */
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
		deletevittuallt(map, 1);
		map = makenewblock('.', size++);
	}
	print_block(map);
	deletevittuallt(map, 1);
	return (1);
}

int	recursion(char **block, char **map, int i, int how_many)
{
	int yx[2];

	yx[0] = 0;
	if (i == how_many)
		return (1);
	while (map[yx[0]])
	{
		yx[1] = 0;
		while (map[yx[0]][yx[1]])
		{
			if (actualinsert(map, strto2dstr(block[i]), yx, 'A' + i) == 1)
			{
				if (recursion(block, map, i + 1, how_many) == 1)
					return (1);
				else
					map_char_delet(map, 'A' + i + 1);
			}
			map_char_delet(map, 'A' + i);
			yx[1]++;
		}
		yx[0]++;
	}
	return (0);
}
