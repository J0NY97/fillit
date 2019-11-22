/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:50:48 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/22 12:55:52 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_size(char **block)
{
	int *arr;
	int size_x;
	int size_y;

	size_y = 0;
	arr = malloc(2);
	while (block[y])
	{
		size_x = 0;
		while (block[y][x])
			size_x++;
		size_y++;
	}
	arr[0] = size_y;
	arr[1] = size_x;
	return (arr);
}
