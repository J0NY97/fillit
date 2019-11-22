/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/22 15:46:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

//remove these
#include <dirent.h>

int		part1(char *file)
{
	int how_many;
	int x;
	int fd;
	char *line;

	x = 0;
	how_many = 0;
	fd = open(file, O_RDONLY);
	printf("%d\n", fd);
	while (get_next_line(fd, &line) == 1)
	{
		if (x == 4  && ((ft_strcmp(line, "\n") != 0)))
			return (-1);
		if (ft_strcmp(line, "\n") > 0) //line has shit
		{
			if (ft_strlen(line) != 4)
				return (-2);
			x++;
		}
		if (x == 4 && ((ft_strcmp(line, "\n") == 0) || ft_strchr(line, '\0'))) //if x is 4 and is empty line
		{
			x = 0;
			how_many++;
		}
	}
	close(fd);
	return (how_many);
}

char	**part2(char *file, int how_many, char **str)
{
	char *line;
	int fd;
	int i;
	int t;
	
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

int main(int ac, char **av)
{
	char **str;
	int how_many;
	char *file;
	
	file = NULL;
	str = NULL;
	if (ac == 2)
	{
		struct dirent *de;
		DIR *dr = opendir(av[1]);

		if (dr == NULL)
		{
			ft_putstr("Ccant open directory!\n");
			return (0);
		}
		while ((de = readdir(dr)) != 0)
		{
			if (ft_strcmp(de->d_name, ".") && ft_strcmp(de->d_name, ".."))
			{
				file = ft_strdup(av[1]);
				file = ft_strjoin(file, "/");
				file = ft_strjoin(file, de->d_name);
				printf("%s\n", file);
				how_many = part1(file);
				printf("How many: %d\n", how_many);
				if (how_many <= 0)
					ft_putstr("error\n");
				else
				{
					str = part2(file, how_many, str);
					for (int i = 0; str[i]; i++)
					{
						printf("%d: %s\n", i, str[i]);
					}
				}
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
		}
		closedir(dr);
		return (0);
	}
	return (1);
}
