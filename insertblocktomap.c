#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

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
	newblock = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		x = 0;
		newblock[i] = (char *)malloc(sizeof(char) * size + 1);
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
	newblock = makenewblock('.');
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

int *getfirstinsertable(char **map, int start_y, int start_x, char filled)
{
	int map_size;
	int *yx;
	int end = 0;

	yx = malloc(2);
	yx[0] = -1;
	yx[1] = -1;
	map_size = ft_strlen(map[0]);
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
	int *yx;
	int y = 0;
	int x = 0;
	int end = 0;
	int inserted = 0;

	yx = malloc(2);
	yx = getfirstinsertable(map, 0, howmanieth, '#');
	if (yx[0] >= 0 && yx[1] >= 0)
	{
		while (block[y])
		{
			if (end == 1)
				x = 0;
			while (block[y][x])
			{
				printf("%c", block[y][x]);
				if (block[y][x] == filledchar)
				{
					printf("found filled inblock: %d, %d\n", y, x);
					if (map[yx[0] + y][yx[1] + x] == emptychar)
					{
						printf("the same is emtpy in map: %d, %d\n", yx[0] + y, yx[1] + x);
						map[yx[0] + y][yx[1] + x] = filledchar;
						inserted++;
					}
				}
				x++;
			}
			printf("\n");
			end = 1;
			y++;
		}
		if (inserted == 4)
		{
			printf("yes, %d, %d\n", yx[0], yx[1]);
			return (1);
		}
		printf("Only %d inserted!\n", inserted);
		return (0);
	}
	printf("No, %d, %d\n", yx[0], yx[1]);
	return (0);
}

char **makeSquare(void)
{
	char **block;

	block = makenewblock('.');
	block[0][0] = '#';
	block[0][1] = '#';
	block[1][0] = '#';
	block[1][1] = '#';
	return (block);
}

char **makeLineVertical(void)
{
	char **block;

	block = makenewblock('.');
	block[0][0] = '#';
	block[1][0] = '#';
	block[2][0] = '#';
	block[3][0] = '#';
	return (block);
}

char **makeLineHorizontal(void)
{
	char **block;

	block = makenewblock('.');
	block[0][0] = '#';
	block[0][1] = '#';
	block[0][2] = '#';
	block[0][3] = '#';
	return (block);
}

char **makeTLeft(void)
{
	char **block;

	block = makenewblock('.');
	block[0][1] = '#';
	block[1][0] = '#';
	block[1][1] = '#';
	block[2][1] = '#';
	return (block);
}

char **makeTUp(void)
{
	char **block;

	block = makenewblock('.');
	block[1][0] = '#';
	block[1][1] = '#';
	block[1][2] = '#';
	block[0][1] = '#';
	return (block);
}

char **makeTRight(void)
{
	char **block;

	block = makenewblock('.');
	block[0][0] = '#';
	block[1][0] = '#';
	block[2][0] = '#';
	block[1][1] = '#';
	return (block);
}

char **makeTDown(void)
{
	char **block;

	block = makenewblock('.');
	block[0][0] = '#';
	block[0][1] = '#';
	block[0][2] = '#';
	block[1][2] = '#';
	return (block);
}

void	print_block(char **block)
{
	printf("%s\n", block[0]);
    printf("%s\n", block[1]);
    printf("%s\n", block[2]);
    printf("%s\n", block[3]);
}

int main(void)
{
   /* char map[4][4] = {
        {"...."},
        {"...."},
        {"...."},
        {"...."}
    };*/
   /* char block[5][5] = {
        {"....\0"},
        {"..#.\0"},
        {".##.\0"},
        {"..#.\0"},
    }; */
	char **map;
	map = makenewblock('.');
	print_block(map);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	char **block;
	block = makenewblock('.');
	block[1][2] = '#';
	block[2][2] = '#';
	block[3][2] = '#';
	block[2][1] = '#';
	print_block(block);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int arr[3];
	getRealXandY(arr, block);
	
	char **newblock;
	newblock = inserttomap(block, arr[1], arr[0]);
	print_block(newblock);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%d%d%d\n", arr[0], arr[1], arr[2]);
	printf("First block inserted; %d\n", actualinsert(map, newblock, '.', '#', 0));
	print_block(map);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	char **newblock2;
	newblock2 = makenewblock('.');
	newblock2 = makeTLeft();
	print_block(newblock2);
	printf("Second block inserted; %d\n", actualinsert(map, newblock2, '.', '#', 1));
	print_block(map);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	char **newblock3;
	newblock3 = makeSquare();
	print_block(newblock3);
	printf("Third block inserted; %d\n", actualinsert(map, newblock3, '.', '#', 2));
	print_block(map);
	return (0);
}
