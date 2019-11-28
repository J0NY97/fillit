/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/28 12:53:01 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char	**part0(char *file, int how_many, char **str)
{
	int fd;
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	how_many = part1(fd, i);
	close(fd);
	if (how_many <= 0)
		return (str);
	fd = open(file, O_RDONLY);
	str = part2(how_many, str, fd);
	close(fd);
	return (str);
}

int		part1(int fd, int how_many)
{
	int		x;
	char	*line;

	x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp(line, "\n") == -10 && x != 0)
		{
			x = 0;
			how_many++;
		}
		else
		{
			if ((ft_strlen(line) != 4) || x > 4 ||
					(ft_strcmp(line, "\n") == -10 && x == 0))
				return (-1);
			x++;
		}
	}
	if ((how_many == 1 && x < 4) || x == 0 || ft_strcmp(line, "\n") == -10)
		return (-1);
	if (x == 4)
		how_many++;
	return (how_many);
}

char	**part2(int how_many, char **str, int fd)
{
	char	*line;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * how_many + 1);
	str[how_many + 1] = 0;
	while (how_many >= 0)
	{
		str[how_many] = ft_strnew(0);
		how_many--;
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp(line, "\n") < 0)
			i++;
		else
		{
			if (str[i][0] == '\0')
				str[i] = ft_strdup(line);
			else
				str[i] = ft_strjoin(str[i], line);
			str[i] = ft_strjoin(str[i], "\n");
		}
	}
	return (str);
}
