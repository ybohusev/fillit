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

extern	void	move_zero(int coord[4][2], int min_x, int min_y)
{
	int	i;

	while (coord[min_y][0] > 0)
	{
		i = 0;
		while (i < 4)
		{
			coord[i][0]--;
			i++;
		}
	}
	while (coord[min_x][1] > 0)
	{
		i = 0;
		while (i < 4)
		{
			coord[i][1]--;
			i++;
		}
	}
}

extern	void	move_zero_x(int coord[4][2], int min_x)
{
	int	i;

	while (coord[min_x][1] > 0)
	{
		i = 0;
		while (i < 4)
		{
			coord[i][1]--;
			i++;
		}
	}
}
