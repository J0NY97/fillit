/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitychecks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:38:52 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 15:44:56 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		correctchars(char *input, char c1, char c2)
{
	while (*input)
	{
		if (*input != c1 && *input != c2 && *input != '\n')
			return (0);
		input++;
	}
	return (1);
}

int		atleast2(char **input, int arr[4][2], char c2)
{
	int		connected;
	int		x;
	int		y;
	int		ij[2];
	char	pos[4];

	connected = 0;
	ij[0] = 0;
	while (ij[0] < 4)
	{
		y = arr[ij[0]][0];
		x = arr[ij[0]][1];
		pos[0] = !(x - 1 < 0) ? input[y][x - 1] : 0;
		pos[1] = !(y - 1 < 0) ? input[y - 1][x] : 0;
		pos[2] = !(x + 1 > 3) ? input[y][x + 1] : 0;
		pos[3] = !(y + 1 > 3) ? input[y + 1][x] : 0;
		ij[1] = -1;
		while (ij[1]++ < 4)
			if (pos[ij[1]] && pos[ij[1]] == c2)
				connected++;
		ij[0]++;
	}
	if (connected >= 6)
		return (1);
	return (0);
}

int		istetriminos(char **str, char c2)
{
	int coords[4][2];
	int yx[2];
	int filledfound;

	yx[0] = 0;
	filledfound = 0;
	while (yx[0] < 4)
	{
		yx[1] = 0;
		while (yx[1] < 4)
		{
			if (str[yx[0]][yx[1]] == c2)
			{
				filledfound < 4 ? coords[filledfound][0] = yx[0] : 0;
				filledfound < 4 ? coords[filledfound][1] = yx[1] : 0;
				filledfound++;
			}
			yx[1]++;
		}
		yx[0]++;
	}
	if (filledfound == 4)
		if (atleast2(str, coords, c2))
			return (1);
	return (0);
}

int		validity_check(char *str, char emptychar, char filledchar)
{
	if (!correctchars(str, emptychar, filledchar))
		return (0);
	else if (!istetriminos(strto2dstr(str), filledchar))
		return (0);
	return (1);
}
