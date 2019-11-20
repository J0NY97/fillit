#include <stdio.h>

int *getRealXandY(int *arr, char block[5][5])
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

int main(void)
{
    char map[4][4] = {
        {"...."},
        {"...."},
        {"...."},
        {"...."}
    };
    char block[5][5] = {
        {"....\0"},
        {"..#.\0"},
        {".##.\0"},
        {"..#.\0"},
    };
    printf("%s\n", block[0]);
    printf("%s\n", block[1]);
    printf("%s\n", block[2]);
    printf("%s\n", block[3]);
    int arr[3];
    getRealXandY(arr, block);
    printf("%d%d%d\n", arr[0], arr[1], arr[2]);

    return (0);
}