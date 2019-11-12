/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:24 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/12 13:38:58 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	print_usage(char *progname)
{
	ft_putstr(progname);
	ft_putstr(" only accepts one argument.\n");
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
				ft_putnbr(cols);
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
		ft_putnbr(rows);
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

int	istetriminos(char *input, char c1, char c2)
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
				printf("%d found at, y: %d, x: %d\n", filledfound + 1, y, x);
				filledfound++;
			}
			x++;
		}
		y++;
	}
	(void)c1;
	(void)c2;
	return (1);
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
	else if (!istetriminos(input, c1, c2))
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

int	main(int argc, char *argv[])
{
	char c1 = '.';
	char c2 = '#';
	char *toomanyfilled = "....\n.###\n..##\n....";
	char *toofewfilled = ".###\n....\n....\n....";
	char *wrongchars = "AAAA\n####\nAAAA\nAAAA";
	char *nottetriminos = "...#\n..#.\n.#..\n#...";
	char *correct = "....\n....\n####\n....";
	char **str = strto2dstr(correct);

	int x = 0;
	while (str[x])
	{
		printf("%s\n",str[x]);
		x++;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n", toomanyfilled);
	printf("toomanyfilled; 0 : %d\n", check_validity(toomanyfilled, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n", toofewfilled);
	printf("toofewfilled; 0 : %d\n", check_validity(toofewfilled, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n", wrongchars);
	printf("wrongchars; 0 : %d\n", check_validity(wrongchars, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n", nottetriminos);
	printf("nottetriminos: 0 : %d\n", check_validity(nottetriminos, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n", correct);
	printf("correct; 1 : %d\n", check_validity(correct, c1, c2));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	(void)argc;
	(void)argv;
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
