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

typedef	struct			s_tetrimino
{
	int					coord[4][2];
	struct s_tetrimino	*next;
}						t_tetrimino;

void					move_zero(int coord[4][2]);
void					move_tetrimino_right(int coord[4][2]);
void					move_tetrimino_down(int coord[4][2]);
t_tetrimino				*read_data(char *file_name);
int						check_valid(int fd);
t_tetrimino				write_data(fd);

#endif
