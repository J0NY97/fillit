/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:23:45 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/25 12:46:44 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# include "./libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

char	**makenewblock(char emptychar, int size);
int		ft_2dstrchr(char **str, char c);
int 	pre_rec(int how_many, char **block);
int		recursive(char **block, char **map, int x, int y, int how_many, int timeout);
char	**strto2dstr(char *input);
int		actualinsert(char **map, char **block, char emptychar, char filledchar, int howmanieth);
int		*getfirstinsertable(char **map, int start_x, char filled);
char	**inserttomap(char **block, int realx, int realy);
int		*getRealXandY(char **block);
void	print_block(char **block);
void	 map_char_delet(char **map, char c);
int		*get_size(char **block);
int		istetriminos(char *input, char c2);
int		atleast2(char **input, int arr[4][2], char c2);
int		correctchars(char *input, char c1, char c2);
char	**part2(char *file, int how_many, char **str);
int		part1(char *file);
int		validity_check(char *str, char emptychar, char filledchar);

#endif
