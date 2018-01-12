/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulaiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:03:14 by akulaiev          #+#    #+#             */
/*   Updated: 2018/01/09 18:03:15 by akulaiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		check_same_index(int tetr[4][2], int checked_tetr[4][2])
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr[i][0] == checked_tetr[j][0] &&
				tetr[i][1] == checked_tetr[j][1])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static	int		is_empty_field(t_tetrimino *tetr, t_tetrimino *temp_tetr,
								int field)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (temp_tetr->coord[i][0] >= field)
			return (3);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (temp_tetr->coord[i][1] >= field)
			return (2);
		i++;
	}
	while (tetr != temp_tetr)
	{
		if (!check_same_index(tetr->coord, temp_tetr->coord))
			return (1);
		tetr = tetr->next;
	}
	return (0);
}

static	int		recursive_search(t_tetrimino *tetr, t_tetrimino *temp_tetr,
									int field, int flag)
{
	int	check;
	
	while (temp_tetr)
	{
		if (flag == 0)
			move_zero(temp_tetr->coord);
		else
			move_tetrimino_right(temp_tetr->coord);
		while ((check = is_empty_field(tetr, temp_tetr, field)) != 0 && check != 3)
		{
			if (check == 1)
				move_tetrimino_right(temp_tetr->coord);
			else if (check == 2)
			{
				move_zero_x(temp_tetr->coord);
				move_tetrimino_down(temp_tetr->coord);
			}
		}
		if (check == 0 && !(flag = 0))
			temp_tetr = temp_tetr->next;
		if (check == 3 && temp_tetr != tetr && (flag = 1))
			temp_tetr = temp_tetr->prev;
		if (check == 3 && temp_tetr == tetr)
			return (0);
	}
	return (1);
}

extern	int		algor(t_tetrimino *tetr)
{
	int			field;
	int			i;
	t_tetrimino *temp_tetr;

	i = 0;
	temp_tetr = tetr;
	printf("g_elems %d\n", g_elems);
	g_elems = g_elems * 4;
	while (!(field = ft_sqrt(g_elems)))
		g_elems++;
	while (i == 0)
	{
		i = recursive_search(tetr, temp_tetr, field, 0);
		if (i == 0)
			field++;
	}
	return (field);
}
