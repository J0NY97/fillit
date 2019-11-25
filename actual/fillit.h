/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:23:45 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/25 15:47:38 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# include "./libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

// Niklas
int 	pre_rec(int how_many, char **block);
int		recursive(char **block, char **map, int x, int y, int how_many, int timeout);

// Jony
int		actualinsert(char **map, char **block, char emptychar, char filledchar, int howmanieth);
int		*getRealXandY(char **block);
char	**topleftblock(char **block, int realx, int realy);
int		trytoinsert(char **map, char **block, int startx, char c);

// Arraymaker
int		part1(char *file);
char	**part2(char *file, int how_many, char **str);

// Validity checks
int		validity_check(char *str, char emptychar, char filledchar);
int		correctchars(char *input, char c1, char c2);
int		istetriminos(char *input, char c2);
int		atleast2(char **input, int arr[4][2], char c2);

// Help functions
int		*get_size(char **block);
void	 map_char_delet(char **map, char c);
char	**strto2dstr(char *input);
int		ft_2dstrchr(char **str, char c);
char	**makenewblock(char emptychar, int size);
void	print_block(char **block);

#endif
