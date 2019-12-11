/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:37 by jsalmi            #+#    #+#             */
/*   Updated: 2019/12/05 16:03:08 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		usage(void)
{
	ft_putstr("usage: ./fillit target_file\n");
	return (1);
}

int		error(void)
{
	ft_putstr("error\n");
	return (1);
}

int		main(int ac, char **av)
{
	char	**str;
	int		how_many;
	int		i;

	how_many = 0;
	i = 0;
	str = NULL;
	if (ac == 2)
	{
		str = making_array(av[1], how_many, str);
		while (str[how_many])
			how_many++;
		if (str == NULL || how_many > 26)
			return (error());
		while (str[i] && i < how_many)
		{
			if (!validity_check(str[i], '.', '#'))
				return (error());
			i++;
		}
		pre_rec(str, how_many);
	}
	else
		return (usage());
	return (0);
}
