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

int *getRealXandY(char **block)
{
    int x;
    int y;
    int realX;
    int realY;
    int isRealFilled;
	int *arr;

	arr = malloc(2);
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

int *getfirstinsertable(char **map, int start_x, char empty)
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
			if (map[start_y][start_x] == empty)
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

int trytoinsert(char **map, char **block, char emptychar, char filledchar,  int startx, char c)
{
	int starty;
	int *map_size;
	int x;
	int y;
	int inserted;
	
	map_size = get_size(map); 
	starty = startx / map_size[0];
	startx = startx % map_size[1];
	x = 0;
	y = 0;
	inserted = 0;
	printf("starty: %d, startx: %d, mapY: %d, mapX: %d\n", starty, startx, map_size[0], map_size[1]);
	while (block[y])
	{
		x = 0;
		while (block[y][x])
		{
			if (block[y][x] == filledchar)
			{
				if (starty + y >= map_size[0] || startx + x >= map_size[1])
				{
					printf("Doenst exist!: %d, %d\n", starty + y, startx + x);
					return (0);
				}
				printf("insert to: %d, %d\n", starty + y, startx + x);
				if (map[starty + y][startx + x] == emptychar)
				{
					printf("Trying to insert to: %d, %d\n", starty + y, startx + x);
					map[starty + y][startx + x] = c;
					inserted++;
					printf("Inserted: %d\n", inserted);
				}
			}
			x++;
		}
		y++;
	}
	printf("inserted: %d, char: %c\n", inserted, c);
	if (inserted == 4)
		return (1);
	return (0);
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
	block = inserttomap(block, realyx[1], realyx[0]);
	print_block(block);
	while (trytoinsert(map, block, emptychar, filledchar, startx, c) == 0)
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
/*
int	oldactualinsert(char **map, char **block, char emptychar, char filledchar, int howmanieth)
{
	printf("Inside actualinsert!\n");
	int *yx;
	int *realyx;
	int y;
	int x;
	int end;
	int inserted;
	char c = 'A' + howmanieth;
	int startx = 0;

	y = 0;
	x = 0;
	end = 0;
	inserted = 0;
	realyx = getRealXandY(block);
	printf("IsFilled: %d\n", realyx[2]);
	block = inserttomap(block, realyx[1], realyx[0]);
	while (inserted != 4)
	{
		printf("Startx: %d\n", startx);
		yx = getfirstinsertable(map, startx, emptychar);
		if (realyx[2] != 1)
			yx[1] -= 1;
		printf("yx: %d, %d\n", yx[0], yx[1]);
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
						if (yx[0] + y >= ft_strlen(map[0]) || yx[1] + x >= ft_strlen(map[0]))
						{
							printf("Doenst exist!: %d, %d\n", yx[0] + y, yx[1] + x);
							return (0);
						}
						printf("insert to: %d, %d\n", yx[0] + y, yx[1] + x);
						if (map[yx[0] + y][yx[1] + x] == emptychar)
						{
							printf("Trying to insert to: %d, %d\n", yx[0] + y, yx[1] + x);
							map[yx[0] + y][yx[1] + x] = c;
							inserted++;
							printf("Inserted: %d\n", inserted);
						}
					}
					x++;
				}
				end = 1;
				y++;
			}
			if (inserted == 4)
			{
				//trytoinsert(map, block, startx);
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
			}
		}
	}
	return (0);
}
*/
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
