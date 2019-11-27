/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:23:45 by jsalmi            #+#    #+#             */
/*   Updated: 2019/11/27 12:31:32 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# include "./libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

// Niklas
int		new_thing(char **block, char **map, int i, char letter, int how_many);
int 	pre_rec(char **block, int how_many);

// Jony
int		actualinsert(char **map, char **block, int x, int y, char c);
int		*getRealXandY(char **block);
char	**topleftblock(char **block, int realx, int realy);
int		trytoinsert(char **map, char **block, int x, int y, char c);

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
char	**makenewblock(char emptychar, int size);
void	print_block(char **block);

#endif
