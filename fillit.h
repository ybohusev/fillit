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
# include <stdio.h>

# define PRT(X) write(1, #X, 1);

typedef	struct			s_tetrimino
{
	int					coord[4][2];
	struct s_tetrimino	*next;
}						t_tetrimino;

int						g_elems;

void					move_zero(int coord[4][2]);
void					move_tetrimino_right(int coord[4][2]);
void					move_tetrimino_down(int coord[4][2]);
t_tetrimino				*read_data(char *file_name);
char					**check_valid(int fd, int *a);
t_tetrimino				*write_data(int fd);
t_tetrimino				*fillit_lstnew(int **new_tetr);
void					fillit_lstadd(t_tetrimino *list_elem, int **new_tetr);
int						**fillit_memalloc(int size_x, int size_y);
void					search_s(t_tetrimino *tetr);

#endif
