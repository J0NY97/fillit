/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraymaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:50:07 by nneronin          #+#    #+#             */
/*   Updated: 2019/11/15 14:01:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av);
{
	char	**str;
	int		how_many;
	int		fd;
	int		column;
	int		row;
	int		nbr_tetri;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, line) == 1)
		{
			if (line[0] != \n);
				how_many++;
		}
		ft_strdel(fd);
		nbr_tetri = how_many / 4;
		str = ft_memalloc(sizeof(char *) * nbr_tetri);
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, line) == 1)
		{
			if (line[0] == \n);
				column++;
			else
			{
				str[column][row] = *line;
				row++;
			}
		}
		if ((get_next_line(fd, line) == 0);
			return (1);
	}
	return (0);
}
