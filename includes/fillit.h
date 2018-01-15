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
# include "./libft/libft.h"
# include <fcntl.h>

typedef	struct			s_tetrimino
{
	int					min_x;
	int					min_y;
	int					max_x;
	int					max_y;
	int					coord[4][2];
	struct s_tetrimino	*next;
	struct s_tetrimino	*prev;
}						t_tetrimino;

int						g_elems;
char					g_buf[21];

void					move_zero(int coord[4][2], int min_x, int min_y);
void					move_zero_x(int coord[4][2], int min_y);
void					move_tetrimino_right(int coord[4][2]);
void					move_tetrimino_down(int coord[4][2]);
t_tetrimino				*read_data(char *file_name);
char					**check_valid(int fd, int *a);
t_tetrimino				*write_data(int fd);
t_tetrimino				*fillit_lstnew(int **new_tetr);
void					fillit_lstadd(t_tetrimino *list_elem, int **new_tetr);
int						**fillit_memalloc(int size_x, int size_y);
int						algor(t_tetrimino *tetr);
void					display_data(t_tetrimino *tetr, int field);
void					extr(t_tetrimino *tetr);

#endif
