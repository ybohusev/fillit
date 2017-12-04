/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:26:26 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/24 19:26:29 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	move_tetrimino_right(int coord[4][2])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		coord[i][1]++;
		i++;
	}
}

extern	void	move_tetrimino_down(int coord[4][2])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		coord[i][0]++;
		i++;
	}
}

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

extern	void	move_zero(int coord[4][2])
{
	int	min;
	int	i;

	min = search_min(coord, 0);
	while (coord[min][0] > 0)
	{
		i = 0;
		while (i < 4)
		{
			coord[i][0]--;
			i++;
		}
	}
	min = search_min(coord, 1);
	while (coord[min][1] > 0)
	{
		i = 0;
		while (i < 4)
		{
			coord[i][1]--;
			i++;
		}
	}
}
