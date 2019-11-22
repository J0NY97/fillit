/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/22 11:28:26 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		part1(char **av)
{
	int how_many;
	int x;
	int fd;
	char *line;

	x = 0;
	how_many = 0;
	// This is to count howm any //Should be a separet function in the future.
	fd = open(av[1], O_RDONLY);
	//Function checks if is 4x4, how many tetriminos, if separated with 1 \n
	while (get_next_line(fd, &line) == 1)
	{
		if (x > 4  || ((ft_strcmp(line, "\n") < 0) && x == 0))
			return (-1);
		if (x == 4 && (ft_strcmp(line, "\n") < 0))
		{
			x = 0;
			how_many++;
		}
		if (ft_strcmp(line, "\n") > 0)
		{
			if (ft_strlen(line) != 4)
				return (-1);
			x++;
		}
	}
	close(fd);
	return (how_many);
}

char	**part2(char **av, int how_many, char **str)
{
	char *line;
	int fd;
	int i;
	int t;

	i = 0;
	t = 0;
	//printf("%d\n", how_many);
	str = (char **)malloc(sizeof(char *) * how_many + 1);
	printf("str; %lu, char **: %lu, char *: %lu\n", sizeof(str), sizeof(char **), sizeof(char *));
	str[how_many + 1] = 0;
	while (how_many >= 0)
	{
		printf("how_many: %d\n", how_many);
		str[how_many] = ft_strnew(0);
		how_many--;
	}
	// This is to copy to str
	fd = open(av[1], O_RDONLY);
	while ((t = get_next_line(fd, &line)) == 1)
	{
		//printf("t: %d\n", t);
		if (ft_strcmp(line, "\n") < 0)
		{
			i++;
			printf("\n");
		}
		else
		{
			if (str[i][0] == '\0')
			{
				str[i] = ft_strdup(line);
				printf("%s, make new\n", str[i]);
			}
			else
			{
				printf("%s, join\n", line);
				str[i] = ft_strjoin(str[i], line);
			}
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
	
	str = NULL;
	if (ac == 2)
	{
		how_many = part1(av);
		printf("%d\n", how_many);
		str = part2(av, how_many, str);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("1: %s\n", str[0]);
		printf("2: %s\n", str[1]);
		printf("3: %s\n", str[2]);
		printf("4: %s\n", str[3]);
		return (1);
	}
	return (0);
}
