/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getxandy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:28:16 by jsalmi            #+#    #+#             */
/*   Updated: 2019/12/02 17:39:52 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		getrealx(char **block)
{
	int	y;
	int	x;
	int	realx;

	x = 0;
	realx = -1;
	while (x < 4 && realx < 0)
	{
		y = 0;
		while (y < 4 && realx < 0)
		{
			if (block[y][x] == '#')
			{
				realx = x;
				break ;
			}
			y++;
		}
		x++;
	}
	return (realx);
}

int		getrealy(char **block)
{
	int x;
	int y;
	int realy;

	realy = -1;
	y = 0;
	while (y < 4 && realy < 0)
	{
		x = 0;
		while (x < 4 && realy < 0)
		{
			if (block[y][x] == '#')
			{
				realy = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (realy);
}

void	getrealyandx(int *arr, char **block)
{
	arr[0] = getrealy(block);
	arr[1] = getrealx(block);
}
