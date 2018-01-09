/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:35:51 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/04 15:35:53 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		touch_check(char **s, int x, int y)
{
	int		check;

	check = 0;
	if (x != 3 && y != 3)
	{
		if (s[x + 1][y] == '#')
			check++;
		if (s[x][y + 1] == '#')
			check++;
	}
	else if (x == 3 && y != 3)
	{
		if (s[x][y + 1] == '#')
			check++;
	}
	else if (y == 3 && x != 3)
	{
		if (s[x + 1][y] == '#')
			check++;
	}
	return (check);
}

static int		sqr_valid(char **sqr)
{
	int	x;
	int	y;
	int	t_check;
	int	count_dot;
	int	count_hash;

	t_check = 0;
	count_dot = 0;
	count_hash = 0;
	y = -1;
	while (y++ != 3)
	{
		x = -1;
		while (x++ != 3)
		{
			if (sqr[x][y] == '.')
				count_dot++;
			else if (sqr[x][y] == '#' && (t_check += touch_check(sqr, x, y)))
				count_hash++;
		}
	}
	if (count_dot != 12 || count_hash != 4 || t_check < 3)
		return (0);
	return (1);
}

extern char		**check_valid(int fd, int *a)
{
	char	buf[21];
	char	**sqr_t;
	int		i;

	sqr_t = NULL;
	if ((i = read(fd, buf, 21)))
	{
		if (buf[19] != '\n' || buf[0] == '\n' || i < 20)
		{
			*a = 0;
			return (sqr_t);
		}
		sqr_t = ft_strsplit(buf, '\n');
		if (sqr_t[0] != NULL)
		{
			if (sqr_valid(sqr_t))
				return (sqr_t);
		}
	}
	return (sqr_t);
}
