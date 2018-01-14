/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:31:02 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/14 16:31:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		search_min(int p[4][2], int c)
{
	int	i;
	int	min;
	int	min_coord;

	min = p[0][c];
	min_coord = 0;
	i = 0;
	while (i < 4)
	{
		if (min > p[i][c])
		{
			min_coord = i;
			min = p[i][c];
		}
		i++;
	}
	return (min_coord);
}

static	int		search_max(int p[4][2], int c)
{
	int	i;
	int	max;
	int	max_coord;

	max = p[0][c];
	max_coord = 0;
	i = 0;
	while (i < 4)
	{
		if (max < p[i][c])
		{
			max_coord = i;
			max = p[i][c];
		}
		i++;
	}
	return (max_coord);
}

extern	void	extr(t_tetrimino *tetr)
{
	tetr->min_y = search_min(tetr->coord, 0);
	tetr->min_x = search_min(tetr->coord, 1);
	tetr->max_y = search_max(tetr->coord, 0);
	tetr->max_x = search_max(tetr->coord, 1);
	if (tetr->next)
		extr(tetr->next);
}
