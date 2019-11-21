/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:56 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/21 16:07:29 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

int pre_rec(void)
{
	int x;
	int y;
	char **tmp;
	int size;

	x = 0;
	y = 0;
	size = 4;
	tmp = ft_strdup(block);
	map = makenewblock('.', size);
	while (rec(block, map, x, how_many, y) == 0)
	{
			x++
			block = tmp;
			if (x == how_many)
			{
				x = 0;
				map = makenewblock('.', size++);
			}
	}
	print_block(map);
	return (1);
}

int rec(char **block, char **map, int x, int how_many, int y)
{
	if (x > how_many)
	{
		x = 0;
		rec(block, map, x, how_many, y);
	}
	if ((actualinsert(map, block, '.', '#', x) == 1) && block[x] != NULL)
	{
		y++;
		block[x] = NULL;
		if (y == how_many)
			return (1); //may be return (map)?/?
		rec(block, map, x++, how_many, y);
	}
	if (y > how_many)
	{
		if (block[x] != NULL);
			return (0);
		return(1); // read previous comment
	}
	if (block[x] == NULL)
		rec(block, map, x++, how_many, y);
	if (actualinsert(map, block, '.', '#', x) == 0)
	{
		y++;
		rec(block, map, x++, how_many, y);
	}
	return(-1);
}
