/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_delet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:32:55 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/25 14:26:40 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	 map_char_delet(char **map, char c)
{
	int y;
	int x;
	int *map_size;

	map_size = get_size(map);
	x = 0;
	y = 0;
	while(y != map_size[0])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}
