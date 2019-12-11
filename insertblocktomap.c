/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertblocktomap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:33 by jsalmi            #+#    #+#             */
/*   Updated: 2019/12/05 16:01:20 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		deletevittuallt(char **block, int return_value)
{
	int i;

	i = 0;
	while (block[i])
	{
		ft_strdel(&block[i]);
		i++;
	}
	free(block);
	return (return_value);
}

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
	deletevittuallt(block, 1);
	return (newblock);
}

int		trytoinsert(char **map, char **block, int arr[2], char c)
{
	int map_size[2];
	int yx[2];
	int inserted;

	get_size(map, map_size);
	yx[0] = 0;
	inserted = 0;
	while (block[yx[0]])
	{
		yx[1] = 0;
		while (block[yx[0]][yx[1]] && arr[0] + yx[0] < map_size[0]
				&& arr[1] + yx[1] < map_size[1])
		{
			if (block[yx[0]][yx[1]] == '#' &&
				map[arr[0] + yx[0]][arr[1] + yx[1]] == '.')
			{
				map[arr[0] + yx[0]][arr[1] + yx[1]] = c;
				inserted++;
			}
			yx[1]++;
		}
		yx[0]++;
	}
	deletevittuallt(block, 1);
	return (inserted == 4);
}

int		actualinsert(char **map, char **block, int arr[2], char c)
{
	int realyx[2];

	getrealyandx(realyx, block);
	block = topleftblock(block, realyx[1], realyx[0]);
	if (trytoinsert(map, block, arr, c) == 0)
	{
		map_char_delet(map, c);
		return (0);
	}
	return (1);
}
