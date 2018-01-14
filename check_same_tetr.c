/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same_tetr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:20:39 by akulaiev          #+#    #+#             */
/*   Updated: 2018/01/14 18:20:41 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrimino	*move_list(int coord1[4][2], int coord2[4][2],
		t_tetrimino *temp_tetr)
{
	int i;
	int count_same;

	i = 0;
	count_same = 0;
	while (i < 4)
	{
		if (coord1[i][0] == coord2[i][0] && coord1[i][1] == coord2[i][1])
			count_same++;
		if (count_same == 3)
		{
			if (temp_tetr->prev)
				temp_tetr = temp_tetr->prev;
			else
				return (temp_tetr);
			check_same_tetr(temp_tetr);
		}
		i++;
	}
	return (temp_tetr->prev);
}

t_tetrimino			*check_same_tetr(t_tetrimino *temp_tetr)
{
	int			i;
	int			coord[4][2];
	int			coord_prev[4][2];
	int			count_same;

	i = 0;
	count_same = 0;
	while (i < 4)
	{
		coord[i][0] = temp_tetr->coord[i][0];
		coord_prev[i][0] = temp_tetr->prev->coord[i][0];
		coord[i][1] = temp_tetr->coord[i][1];
		coord_prev[i][1] = temp_tetr->prev->coord[i][1];
		i++;
	}
	move_zero(coord, temp_tetr->min_x, temp_tetr->min_y);
	move_zero(coord_prev, temp_tetr->prev->min_x,
			temp_tetr->prev->min_y);
	return (move_list(coord, coord_prev, temp_tetr));
}
