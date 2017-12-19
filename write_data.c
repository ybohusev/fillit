/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:50:15 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/04 15:50:16 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int				**write_to_arr(char **elem)
{
	printf("write_to_arr\n");

	int		**coord;
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	coord = (int**)fillit_memalloc(4, 2);
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (elem[i][j] == '#')
			{
				coord[c][0] = i;
				coord[c][1] = j;
				c++;
				if (c == 4)
					return (coord);
			}
			j++;
		}
		i++;
	}
	return (coord);
}

extern	t_tetrimino		*write_data(int fd)
{
	t_tetrimino *tetr;
	char		**elem;

	tetr = NULL;
	elem = (char**)fillit_memalloc(4, 5);
	while ((elem = check_valid(fd)))
	{
		// if (elem[0][0] == '\0')
		// {
		// 	write(1, "error\n", 7);
		// 	del_lst(tetr);
		// 	exit(0);	
		// }
		if (!tetr && elem)
			tetr = fillit_lstnew(write_to_arr(elem));
		else if (elem)
			fillit_lstadd(tetr, write_to_arr(elem));
	}
	return (tetr);
}
