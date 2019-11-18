/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/18 12:26:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	printarray(char **str)
{
	int i = 0;
	
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	char	**str;
	char 	*line;
	int		how_many;
	int		fd;
	int		column;
	int		row;
	int		nbr_tetri;
	int i;
	int x;

	i = 0;
	x = 0;
	how_many = 0;
	if (ac == 2)
	{
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
				if (ft_strlen(line) != 4) // || (!ok_chars(line, '#', '.'))) here or after strjoin
					return (-1);
				x++;
			}
		}
		printf("%d\n", how_many);
		str = (char **)malloc(sizeof(char *) * how_many + 1);
		printf("str; %lu, char **: %lu, char *: %lu\n", sizeof(str), sizeof(char **), sizeof(char *));
		str[how_many + 1] = 0;
		close(fd);
		while (how_many >= 0)
		{
			printf("how_many: %d\n", how_many);
			str[how_many] = ft_strnew(0);
			how_many--;
		}
		// This is to copy to str
		fd = open(av[1], O_RDONLY);
		int t = 0;
		while ((t = get_next_line(fd, &line)) == 1)
		{
			//printf("t: %d\n", t);
			if (ft_strcmp(line, "\n") < 0)
			{
				//printf("line: %s\n", line);
				i++;
				printf("\n");
			}
			else
			{
				if (str[i][0] == '\0')
				{
					printf("%s, make new\n", line);
					str[i] = ft_strdup(line);
				}
				else
				{
					printf("%s, join\n", line);
					str[i] = ft_strjoin(str[i], line);
				}
			//	ft_str(str[i], line);
			//	printf("line: %s", line);
		//		printf("str; %s", str[i]);
				str[i] = ft_strjoin(str[i], "\n");
			//	printf("%s %d\n", str[i], i);
			}
		}
		close(fd);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("1: %s\n", str[0]);
	printf("2: %s\n", str[1]);
	printf("3: %s\n", str[2]);
	printf("4: %s\n", str[3]);
//	printarray(str);
	return (0);
}
