/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_delet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:32:55 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/22 12:08:27 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	 map_char_delet(char **map, char c)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while(y != 4)
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
/*
int main(void)
{
   char map[5][5] = {
        {"....\0"},
        {"..#.\0"},
        {".##.\0"},
        {"..#.\0"},
		{0}
   };
	map_char_delet(map, '#');
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	return (0);
}*/
