/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_delet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:32:55 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/28 10:43:28 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	map_char_delet(char **map, char c)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}
