/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertblocktomap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:33 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 15:29:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	**topleftblock(char **block, int realx, int realy)
{
	char	**newblock;
	int		y;
	int		x;
	int		realrealx;

	realrealx = realx;
	y = 0;
	newblock = makenewblock('.', 4);
	while (realy < 4)
	{
		realx = realrealx;
		x = 0;
		while (realx < 4)
		{
			if (block[realy][realx] == '#')
				newblock[y][x] = '#';
			x++;
			realx++;
		}
		y++;
		realy++;
	}
	return (newblock);
}

int		trytoinsert(char **map, char **block, int x, int y, char c)
{
	int *map_size;
	int yx[2];
	int inserted;

	map_size = get_size(map);
	yx[0] = 0;
	inserted = 0;
	while (block[yx[0]])
	{
		yx[1] = 0;
		while (block[yx[0]][yx[1]] && y + yx[0] < map_size[0]
				&& x + yx[1] < map_size[1])
		{
			if (block[yx[0]][yx[1]] == '#' && map[y + yx[0]][x + yx[1]] == '.')
			{
				map[y + yx[0]][x + yx[1]] = c;
				inserted++;
			}
			yx[1]++;
		}
		yx[0]++;
	}
	return (inserted == 4);
}

int		actualinsert(char **map, char **block, int x, int y, char c)
{
	int *realyx;

	realyx = getrealyandx(block);
	block = topleftblock(block, realyx[1], realyx[0]);
	if (trytoinsert(map, block, x, y, c) == 0)
	{
		map_char_delet(map, c);
		return (0);
	}
	return (1);
}
