/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_delet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:32:55 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/22 12:02:40 by nneronin         ###   ########.fr       */
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
		while(x != '\0')
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int main(void)
{
   char map[4][5] = {
        {"....\0"},
        {"..#.\0"},
        {".##.\0"},
        {"..#.\0"},
   };
	map_char_delet(map, '#');
	printf("%s\n", map);
	return (0);
}
