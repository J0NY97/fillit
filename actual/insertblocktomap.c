#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./fillit.h"

void	print_block(char **block)
{
	int i = 0;

	while (block[i])
	{
		printf("%s\n", block[i]);
		i++;
	}
}

int	*get_size(char **block)
{
	int *arr;
	int size_x;
	int size_y;

	size_y = 0;
	arr = malloc(2);
	while (block[size_y])
	{
		size_x = 0;
		while (block[size_y][size_x])
			size_x++;
		size_y++;
	}
	arr[0] = size_y;
	arr[1] = size_x;
	return (arr);
}

int getrealx(char **block)
{
	int y;
	int x;
	int realx;

    x = 0;
	realx = -1;
    while (x < 4 && realx < 0)
    {
        y = 0;
        while (y < 4 && realx < 0)
        {
            if (block[y][x] == '#')
            {
                realx = x;
                break ;
            }
            y++;
        }
        x++;
    }
    return (realx);
}

int getrealy(char **block)
{
    int x;
    int y;
    int realy;

    realy = -1;
    y = 0;
    while (y < 4 && realy < 0)
    {
        x = 0;
        while (x < 4 && realy < 0)
        {
            if (block[y][x] == '#')
            {
                realy = y;
                break ;
            }
            x++;
        }
        y++;
    }
	return (realy);
}

int *getRealXandY(char **block)
{
	int *realyx;

	realyx = malloc(2);
	realyx[0] = getrealy(block);
	realyx[1] = getrealx(block);
	return (realyx);
}

char	**makenewblock(char emptychar, int size)
{
	char **newblock;
	int	i;
	int x;

	i = 0;
	newblock = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		x = 0;
		newblock[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (x < size)
		{
			newblock[i][x] = emptychar;
			x++;
		}
		newblock[i][x] = '\0';
		i++;
	}
	newblock[i] = 0;
	return (newblock);
}

char	**topleftblock(char **block, int realx, int realy)
{
	char **newblock;
	int y;
	int x;
	int realrealx;

	realrealx = realx;
	y = 0;
	newblock = makenewblock('.', 4);
	while (realy < 4)
	{
		realx = realrealx;
		x = 0;
		while (realx < 4)
		{
			if (block[realy][realx] == '#')
				newblock[y][x] = '#';
			x++;	
			realx++;
		}
		y++;
		realy++;
	}
	return (newblock);
}

int trytoinsert(char **map, char **block, int startx, char c)
{
	int starty;
	int *map_size;
	int x;
	int y;
	int inserted;
	
	map_size = get_size(map); 
	starty = startx / map_size[0];
	startx = startx % map_size[1];
	y = 0;
	inserted = 0;
	while (block[y])
	{
		x = 0;
		while (block[y][x] && starty + y < map_size[0] && startx + x < map_size[1])
		{
			if (block[y][x] == '#')
			{
				if (map[starty + y][startx + x] == '.')
				{
					map[starty + y][startx + x] = c;
					inserted++;
				}
			}
			x++;
		}
		y++;
	}
	return (inserted == 4);
}

int	actualinsert(char **map, char **block, char emptychar, char filledchar, int howmanieth)
{
	int startx;
	int *realyx;
	char c = 'A' + howmanieth;
	int *map_size;

	map_size = get_size(map);
	startx = 0;
	realyx = getRealXandY(block);
	block = topleftblock(block, realyx[1], realyx[0]);
	print_block(block);
	while (trytoinsert(map, block, startx, c) == 0)
	{
		printf("startx: %d\n", startx);
		map_char_delet(map, c);
		print_block(map);
		print_block(block);
		startx++;
		if (startx >= (map_size[0] * map_size[1]))
			return (0);
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
