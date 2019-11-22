/** *
 * 1st itertation: empty map
 *      if a goes into map call function with a in map
 * 2nd iteration: a in map
 *      if b goes into map call function with a and b in nmap
 * ...
 * if x doesnt go into map????
 * how it knows to only have a and b in map
 * **/

// fuck recursion vaffö kan vi int bara gå iterative
/* int    recursionthing(char **blocks, char **map, int x, int y)
{
    if (x > how_many)
        return (0);
    if (x == y)
        return (recursionthing(blocks, map, x + 1, y));
    //function to insert block into map'
    //if that function returned true
        return (recurstionthing(blocks, map, x + 1, y));
} */
int idkvafittanjagbygger(void)
{
	int x;
	int y;
	char **tmp;
	int size;

	x = 0;
	y = 0;
	size = 4;
	tmp = ft_strdup(block);
	while (rec(block, map, x, how_many, y) == 0)
	{
			x++
			block = tmp;
			if (x == how_many)
			{
				x = 0;
				map = makenewblock(map, size++);
			}
	}
	return (map);
}

int rec(char **block, char **map, int x, int how_many, int y)
{
	if (x > how_many)
	{
		x = 0;
		rec(block, map, x, how_many, y);
	}
	if ((jonymagicfunction) == 1 && block[x] != NULL)
	{
		y++;
		block[x] = NULL;
		if (y == how_many)
			return (1); //may be return (map)?/?
		rec(block, map, x++, how_many, y);
	}
	if (y > how_many)
	{
		if (block[x] != NULL);
			return (0);
		return(1); // read previous comment
	}
	if (block[x] == NULL)
		rec(block, map, x++, how_many, y);
	if ((jonysmagicfunnction) == 0)
	{
		y++;
		rec(block, map, x++, how_many, y);
	}
}		

int     iterativething(char ** blocks, char **map, int x, int y, int how_many)
{
    // if these dont fit try to mapsize++;
    while (x < how_many && y < how_many)
    {
        //try to insert block to map
        //if 1 or 0
        //    x++;
        //if x >= how_many
        //  x = 0;
        //  y++;
    }
    return (0);
}

int main(void)
{
    // First iteration
    char **map; // TODO: get the min map
    char **blocks;
    int blocktoinsert = 0;
    int firstblock = 0;
    int how_many = 4;

    //recursionthing(blocks, map, blocktoinsert, firstblock);
    if (iterativething(blocks, map, blocktoinsert, firstblock, how_many))
        printf("Found answer!");
    else
        printf("Didnt find answer!");
    return (0);
}
