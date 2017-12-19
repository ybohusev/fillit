/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:11:26 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/23 16:11:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
#include <stdio.h>

typedef	struct			s_tetrimino
{
	int					coord[4][2];
	struct s_tetrimino	*next;
}						t_tetrimino;

void					move_zero(int coord[4][2]);
void					move_tetrimino_right(int coord[4][2]);
void					move_tetrimino_down(int coord[4][2]);
t_tetrimino				*read_data(char *file_name);
char					**check_valid(int fd);
t_tetrimino				*write_data(int fd);
t_tetrimino				*fillit_lstnew(int **new_tetr);
void					fillit_lstadd(t_tetrimino *list_elem, int **new_tetr);
void					del_lst(t_tetrimino *tetrim);
void					**fillit_memalloc(size_t size_x, size_t size_y);

#endif
