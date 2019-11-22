/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:38:52 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/22 13:47:41 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/fillit.h"

char **strto2dstr(char *input)
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

int correctchars(char *input, char c1, char c2)
{
	while (*input)
	{
		if (*input != c1 && *input != c2 && *input != '\n')
			return (0);
		input++;
	}
	return (1);
}


// This function needs to be shortened
int atleast2(char **input, int arr[4][2], char c2)
{
	int connected;
	int x;
	int y;
	int i;
	char pos[4];

	connected = 0;
	i = 0;
	while (i < 4)
	{
		y = arr[i][0];
		x = arr[i][1];
		pos[0] = !(x - 1 < 0) ? input[y][x - 1] : 0;
		pos[1] = !(y - 1 < 0) ? input[y - 1][x] : 0;
		pos[2] = !(x + 1 > 3) ? input[y][x + 1] : 0;
		pos[3] = !(y + 1 > 3) ? input[y + 1][x] : 0;
		if (pos[0] && pos[0] == c2)
			connected++;
		if (pos[1] && pos[1] == c2)
			connected++;
		if (pos[2] && pos[2] == c2)
			connected++;
		if (pos[3] && pos[3] == c2)
			connected++;
		i++;
	}
	if (connected >= 6)
		return (1);
	return (0);
}

int	istetriminos(char *input, char c2)
{
	char **str = strto2dstr(input);
	int coords[4][2];
	int x;
	int y = 0;
	int filledfound = 0;

	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (str[y][x] == c2)
			{
				coords[filledfound][0] = y;
				coords[filledfound][1] = x;
				filledfound++;
			}
			x++;
		}
		y++;
	}
	if (filledfound == 4)
		if (atleast2(str, coords, c2))
			return (1);
	return (0);
}
