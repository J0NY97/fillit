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
int *getRealXandY(int *arr, char **block)
{
    int x;
    int y;
    int realX;
    int realY;
    int isRealFilled;

    isRealFilled = 0;
    realX = -1;
    realY = -1;
    y = 0;
    x = 0;
    //get Y
    while (y < 4 && realY < 0)
    {
        x = 0;
        while (x < 4 && realY < 0)
        {
            if (block[y][x] == '#')
            {
                realY = y;
                break ;
            }
            x++;
        }
        y++;
    }
    //get X
    y = 0;
    x = 0;
    while (x < 4 && realX < 0)
    {
        y = 0;
        while (y < 4 && realX < 0)
        {
            if (block[y][x] == '#')
            {
                realX = x;
                break ;
            }
            y++;
        }
        x++;
    }
    if (block[realY][realX] == '#')
        isRealFilled = 1;
    arr[0] = realY;
    arr[1] = realX;
    arr[2] = isRealFilled;
    return (arr);
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

char	**inserttomap(char **block, int realx, int realy)
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

int *getfirstinsertable(char **map, int start_x, char filled)
{
	int map_size;
	int *yx;
	int end = 0;
	int start_y;

	yx = malloc(2);
	yx[0] = -1;
	yx[1] = -1;
	map_size = ft_strlen(map[0]);
	start_y = start_x / map_size;
	start_x = start_x % map_size;
	while (start_y < map_size)
	{
		if (end == 1)
			start_x = 0;
		while (start_x < map_size)
		{
			if (map[start_y][start_x] != filled)
			{
				yx[0] = start_y;
				yx[1] = start_x;
				return (yx);
			}
			start_x++;
		}
		end = 1;
		start_y++;
	}
	return (yx);
}

int	actualinsert(char **map, char **block, char emptychar, char filledchar, int howmanieth)
{
	printf("INside actualinsert\n");
	int *yx;
	int *realyx;
	int y = 0;
	int x = 0;
	int end = 0;
	int inserted = 0;
	int timeout = 0;
	char c = 'A' + howmanieth;
	int startx = howmanieth;
	yx = malloc(2);
	realyx = malloc(2);
	realyx = getRealXandY(realyx, block);
	block = inserttomap(block, realyx[1], realyx[0]);
	while (inserted != 4) //&& timeout < 5)
	{
		yx = getfirstinsertable(map, startx, filledchar);
		if (yx[0] == -1 || yx[1] == -1)
			return (0);
		if (yx[0] >= 0 && yx[1] >= 0)
		{
			while (block[y])
			{
				if (end == 1)
					x = 0;
				while (block[y][x])
				{
					if (block[y][x] == filledchar)
					{
						if (map[yx[0] + y][yx[1] + x] == emptychar)
						{
							map[yx[0] + y][yx[1] + x] = c;
							inserted++;
						}
					}
					x++;
				}
				end = 1;
				y++;
			}
			if (inserted == 4)
			{
				return (1);
			}
			else
			{
				inserted = 0;
				print_block(map);
				print_block(block);
				map_char_delet(map, c);
				startx++;
				y = 0;
				x = 0;
			//	timeout++;
			}
			//return (0);
		}
	}
	return (0);
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
