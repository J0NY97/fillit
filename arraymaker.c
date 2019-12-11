/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/12/05 16:23:48 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char	**making_array(char *file, int how_many, char **str)
{
	int fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	how_many = part1(fd, 0, 0, NULL);
	close(fd);
	if (how_many <= 0)
		return (str);
	if (!(str = (char **)malloc(sizeof(char *) * (how_many + 1))))
		return (str);
	while (i < how_many)
		str[i++] = NULL;
	str[how_many] = 0;
	fd = open(file, O_RDONLY);
	str = part2(how_many, str, fd);
	close(fd);
	return (str);
}

int		part1(int fd, int how_many, int x, char *temp)
{
	char	*line;

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
		ft_strdel(&temp);
		temp = ft_strdup(line);
		ft_strdel(&line);
	}
	if ((how_many == 1 && x < 4) || x == 0 || ft_strcmp(temp, "\n") == -10)
		return (-1);
	x == 4 ? how_many++ : 0;
	ft_strdel(&temp);
	return (how_many);
}

char	**part2(int how_many, char **str, int fd)
{
	char	*line;
	char	*temp_str;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < how_many)
	{
		if (ft_strcmp(line, "\n") == -10)
			i++;
		else
		{
			if (str[i] == NULL)
				str[i] = ft_strjoin(line, "\n");
			else
			{
				temp_str = ft_strjoin(str[i], line);
				ft_strdel(&str[i]);
				str[i] = ft_strjoin(temp_str, "\n");
				ft_strdel(&temp_str);
			}
		}
		ft_strdel(&line);
	}
	return (str);
}
