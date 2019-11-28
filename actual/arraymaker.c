/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/28 11:26:23 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		part1(char *file)
{
	int		how_many;
	int		x;
	int		fd;
	char	*line;

	x = 0;
	how_many = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp(line, "\n") == -10)
		{
			x = 0;
			how_many++;
		}
		else
		{
			if ((ft_strlen(line) != 4) || x > 4)
				return (-1);
			x++;
		}
	}
	if ((how_many == 1 && x < 4) || x == 0 || ft_strcmp(line, "\n") == -10)
		return (-1);
	if (x == 4)
		how_many++;
	close(fd);
	return (how_many);
}

char	**part2(char *file, int how_many, char **str)
{
	char	*line;
	int		fd;
	int		i;
	int		t;

	i = 0;
	t = 0;
	str = (char **)malloc(sizeof(char *) * how_many + 1);
	str[how_many + 1] = 0;
	while (how_many >= 0)
	{
		str[how_many] = ft_strnew(0);
		how_many--;
	}
	fd = open(file, O_RDONLY);
	while ((t = get_next_line(fd, &line)) == 1)
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
	close(fd);
	return (str);
}
