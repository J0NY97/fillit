/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:24:56 by jsalmi            #+#    #+#             */
/*   Updated: 2019/12/05 16:04:18 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	**strto2dstr(char *input)
{
	char	**str;
	int		y;
	int		x;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 5);
	y = 0;
	while (y < 4)
	{
		x = 0;
		str[y] = (char *)malloc(sizeof(char) * 5);
		while (x < 4)
		{
			str[y][x] = input[i];
			i++;
			x++;
		}
		str[y][x] = '\0';
		i++;
		y++;
	}
	str[y] = 0;
	return (str);
}

char	**makenewblock(char emptychar, int size)
{
	char	**newblock;
	int		y;
	int		x;

	y = 0;
	newblock = (char **)malloc(sizeof(char *) * (size + 1));
	while (y < size)
	{
		x = 0;
		newblock[y] = (char *)malloc(sizeof(char) * (size + 1));
		while (x < size)
		{
			newblock[y][x] = emptychar;
			x++;
		}
		newblock[y][x] = '\0';
		y++;
	}
	newblock[y] = 0;
	return (newblock);
}

void	print_block(char **block)
{
	int i;

	i = 0;
	while (block[i])
	{
		ft_putstr(block[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	get_size(char **block, int map_size[2])
{
	int	size_x;
	int	size_y;

	size_y = 0;
	while (block[size_y])
	{
		size_x = 0;
		while (block[size_y][size_x])
			size_x++;
		size_y++;
	}
	map_size[0] = size_y;
	map_size[1] = size_x;
}
