/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:24:56 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 15:25:59 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	**strto2dstr(char *input)
{
	char	**str;
	int		y;
	int		x;

	str = ft_memalloc(sizeof(char *) * 5);
	str[0] = ft_memalloc(5);
	str[1] = ft_memalloc(5);
	str[2] = ft_memalloc(5);
	str[3] = ft_memalloc(5);
	str[4] = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			str[y][x] = *input;
			input++;
			x++;
		}
		str[y][x] = '\0';
		input++;
		y++;
	}
	return (str);
}

char	**makenewblock(char emptychar, int size)
{
	char	**newblock;
	int		i;
	int		x;

	i = 0;
	newblock = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		x = 0;
		newblock[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (x < size)
		{
			newblock[i][x] = emptychar;
			x++;
		}
		newblock[i][x] = '\0';
		i++;
	}
	newblock[i] = 0;
	return (newblock);
}

void	print_block(char **block)
{
	int i;

	i = 0;
	while (block[i])
	{
		printf("%s\n", block[i]);
		i++;
	}
}

int		*get_size(char **block)
{
	int	*arr;
	int	size_x;
	int	size_y;

	size_y = 0;
	arr = malloc(2);
	while (block[size_y])
	{
		size_x = 0;
		while (block[size_y][size_x])
			size_x++;
		size_y++;
	}
	arr[0] = size_y;
	arr[1] = size_x;
	return (arr);
}
