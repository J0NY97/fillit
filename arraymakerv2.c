/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/15 15:22:45 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	printarray(char **str)
{
	int i = 0;
	printf("%s\n", str[i]);
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

	i = 0;
	how_many = 0;
	if (ac == 2)
	{
		// This is to count howm any
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%d\n", ft_strcmp(line, "\n"));
			if (ft_strcmp(line, "\n") < 0)
				how_many++;
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
			printf("t: %d\n", t);
			if (ft_strcmp(line, "\n") < 0)
			{
				printf("%d\n", get_next_line(fd, &line));
				i++;
			}
			else
			{
				if (str[i][0] == '\0')
				{
					//printf("str is");
					str[i] = ft_strdup(line);
				}
				else
					ft_strjoin(str[i], line);
			//	ft_str(str[i], line);
			//	printf("line: %s", line);
		//		printf("str; %s", str[i]);
				//ft_strjoin(str[i], "\n");
			}
		}
		close(fd);
	}
	printarray(str);
	return (0);
}
