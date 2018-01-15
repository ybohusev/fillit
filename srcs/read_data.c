/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:34:23 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/04 15:34:25 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*read_data(char *file_name)
{
	int			fd;
	t_tetrimino	*tetr;

	if (!(fd = open(file_name, O_RDONLY)))
	{
		write(1, "Cannot open file\n", 17);
		exit(0);
	}
	tetr = write_data(fd);
	close(fd);
	return (tetr);
}
