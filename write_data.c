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

static	int				**write_to_arr(char elem[4][5])
{
	int		coord[4][2];
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
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
	char		elem[4][5];

	elem = check_valid(fd);
	tetr = ft_lstnew(write_to_arr(elem));
	while (elem != NULL)
	{
		elem = check_valid(fd);
		if (elem != NULL)
			ft_lstadd(tetr, write_to_arr(elem));
	}
	return (tetr);
}
