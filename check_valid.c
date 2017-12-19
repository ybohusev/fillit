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

#include "libft.h"

static int		touch_check(char **s, int x, int y)
{
	int		check;

	check = 0;
	if (s[x + 1][y] == '#')
		check++;
	if (s[x][y + 1] == '#')
		check++;
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
	while (y++ != 4)
	{
		x = -1;
		while (x++ !=  4)
		{
			if (sqr[x][y] == '.')
				count_dot++;
			if (sqr[x][y] == '#' && (t_check += touch_check(sqr, x, y)))
				count_hash++;
		}
	}
	if (count_dot != 12 || count_hash != 4 || t_check < 3)
		return (0);
	return (1);
}

extern char		**check_valid(int fd)
{
	char	buf[21];
	char	**sqr_t;
	int		count_t;

	count_t = 0;
	sqr_t = NULL;
	while (read(fd, buf, 21))
		{
			if (count_t == 26 || buf[19] != '\n' || buf [0] == '\n')
				return ("Err");
			sqr_t = ft_strsplit(buf, '\n');
			if (sqr_valid(sqr_t))
				count_t++;
			else
				return ("Err");
		}
	return (sqr_t);
}	
