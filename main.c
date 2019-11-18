/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:24 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/14 15:03:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(char *progname)
{
	ft_putstr(progname);
	ft_putstr(": usage error... tidittii.....\n");
}

int fourxfourcheck(char *input)
{
	//check here this validity thingy
	int rows;
	int cols;

	rows = 0;
	cols = 0;
	while (*input)
	{
		cols++;
		if (*input == '\n')
		{
			if (cols != 5)
			{
				ft_putstr("Wrong amount of cols!: ");
				ft_putnbr(cols - 1);
				ft_putchar(':');
				ft_putnbr(rows);
				return (0);
			}
			rows++;
			cols = 0;
		}
		input++;
	}
	if (rows != 3)
	{
		ft_putstr("Wrong amount of rows: ");
		ft_putnbr(rows + 1);
	}
	return (rows == 3);
}

int fourfilled(char *input, char filledchar)
{
	//check here if there are exactly four filled characters
	int x;

	x = 0;
	while (*input)
	{
		if (*input == filledchar)
			x++;
		input++;
	}
	return (x == 4);
}

int correctchars(char *input, char c1, char c2)
{
	// loop through all chars and check if theres
	// is a not valid char
	while (*input)
	{
		if (*input != c1 && *input != c2 && *input != '\n')
		{
			ft_putchar(*input);
			ft_putstr(" is not a valid char.\n");
			return (0);
		}
		input++;
	}
	return (1);
}

char **strto2dstr(char *input)
{
	char **str;
	int y;
	int x;

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

int atleast2(char **input, int arr[4][2], char c2)
{
	// this function should only be called from the istetrimions function
	//
	// x and y can be removed and just copy paste arr[y][x] everywhere xd
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
	printf("connected: %d\n", connected);
	if (connected >= 6)
		return (1);
	return (0);
}

int	istetriminos(char *input, char c2)
{
	// this functions should be called last of all the validity checks
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
				printf("%d found at, y: %d, x: %d\n", filledfound + 1, y, x);
				filledfound++;
			}
			x++;
		}
		y++;
	}
	if (filledfound == 4)
	{
		if (atleast2(str, coords, c2))
			return (1);
	}
	else
		printf("istetriminos: Somehow didnt find 4 filled!\n");
	return (0);
}

void	print_error(void)
{
	ft_putstr("error\n");
}

int	check_validity(char *input, char c1, char c2)
{
	if (!fourxfourcheck(input))
	{
		ft_putstr("fourxfourcheck: error\n");
		return (0);
	}
	else if (!fourfilled(input, c2))
	{
		ft_putstr("fourfilled: error\n");
		return (0);
	}
	else if (!correctchars(input, c1, c2))
	{
		ft_putstr("correctchars: error\n");
		return (0);
	}
	else if (!istetriminos(input, c2))
	{
		ft_putstr("istetriminos: error\n");
		return (0);
	}
	//and so on till all checks are performed
	//if any of those fails then it will return 0
	//and not pass as a valid map
	return (1);
	// if everything is checked and nothing returns 0 it will
	// return 1 and go back to main and do its shit
}

void	add_debug(char *map, char *name, int expectedoutput, char c1, char c2)
{
	printf("%s\n", map);
	printf("%s; %d : %d\n", name, expectedoutput, check_validity(map, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int	main(int argc, char *argv[])
{
	char c1 = '.';
	char c2 = '#';
	char *toomanyfilled = "....\n.###\n..##\n....";
	char *toofewfilled = ".###\n....\n....\n....";
	char *wrongchars = "AAAA\n####\nAAAA\nAAAA";
	char *nottetriminos = "...#\n..#.\n.#..\n#...";
	char *toomanyrows = "....\n#...\n#...\n#...\n#...";
	char *toomanycols = "#....\n#....\n#....\n#....";
	char *correct = "....\n....\n####\n....";
	char *correct2 = "##..\n##..\n....\n....";
	char *correct3 = ".#..\n###.\n....\n....";
	
	add_debug(toomanyfilled, "toomanyfilled", 0, c1, c2);
	add_debug(toofewfilled, "toofewfilled", 0, c1, c2);
	add_debug(wrongchars, "wrongchar", 0, c1, c2);
	add_debug(nottetriminos, "nottetriminos", 0, c1, c2);
	add_debug(toomanyrows, "toomanyrows", 0, c1, c2);
	add_debug(toomanycols, "toomanycols", 0, c1, c2);
	add_debug(correct, "correct", 1, c1, c2);
	add_debug(correct2, "correct2", 1, c1, c2);
	add_debug(correct3, "correct3", 1, c1, c2);
	(void)argc;
	(void)argv;

	/***
	 * idea for how to get maps from file
	char ***maps;
	maps = (char ***)malloc(sizeof(char **) * );
	char *line;
	int map = 0;
	int row = 0;
	while (get_next_line)
	{
		line = gnl_read;
		if (ft_strcmp(line, "\n")
			map++;
		else
			ft_strdup(maps[map][row], line);
			row++:
	}
	***/
	/*if (argc != 2)
	{
		print_usage(argv[0]);
		return (1);
	}
	argv++;
	while (*argv)
	{
		// Debug
		ft_putstr("Debug: \n");
		//ft_putstr(*argv);
		ft_putstr(input); // remove this and uncomment the one above this
		ft_putstr("\n");
		// End of debug
		if (!check_validity(input, c1, c2)) // change input to *argv
		{
			print_error();
			//return (1);
			// return 1 here if whole program should exit after one
			// of the maps are invalid
			// Dont return anything if it should still test the
			// rest of the maps...
		}
		else
			ft_putstr("Validity Check Passed\n");
		argv++;
	}*/
	return (0);
}
