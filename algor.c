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

static	void	choise_act(t_tetrimino *temp_tetr, int check)
{
	if (check == 1)
		move_tetrimino_right(temp_tetr->coord);
	else if (check == 2)
	{
		move_zero_x(temp_tetr->coord);
		move_tetrimino_down(temp_tetr->coord);
	}
}

static	int		check_same_index(int tetr[4][2], int checked_tetr[4][2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetr[i][0] == checked_tetr[j][0] && tetr[i][1] == checked_tetr[j][1])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static	int		is_empty_field(t_tetrimino *tetr, t_tetrimino *temp_tetr, int field)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (temp_tetr->coord[i][0] > field)
			return (3);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (temp_tetr->coord[i][1] > field)
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

static	void	recursive_search(t_tetrimino *tetr, t_tetrimino *temp_tetr, int field, int flag)
{
	int	check;

	if (!flag)
		move_zero(temp_tetr->coord);
	while ((check = is_empty_field(tetr, temp_tetr, field)))
	{
		choise_act(temp_tetr, check);
	}
	if (temp_tetr->next)
		recursive_search(tetr, temp_tetr->next, field, 0);
}

extern	void	algor(t_tetrimino *tetr)
{
	int	field;
	
	field = 0;
	t_tetrimino *temp_tetr;

	temp_tetr = tetr;
	/*search smallest field*/
	recursive_search(tetr, temp_tetr, field, 0);
}
