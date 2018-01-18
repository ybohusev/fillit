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

static	void			delete_alloc(void **data)
{
	int	j;

	j = 0;
	while (data[j])
	{
		free(data[j]);
		data[j] = NULL;
		j++;
	}
	free(data);
	data = NULL;
}

static	void			write_to_arr(char **elem, int **coord)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (elem[i][j] == '#')
			{
				coord[c][0] = i;
				coord[c][1] = j;
				c++;
			}
			j++;
		}
		i++;
	}
}

extern	t_tetrimino		*write_data(int fd)
{
	int			i;
	t_tetrimino *tetr;
	char		**elem;
	int			**data;

	tetr = NULL;
	i = 1;
	data = fillit_memalloc(4, 2);
	while ((elem = check_valid(fd, &i)) && i)
	{
		write_to_arr(elem, data);
		if (!tetr)
			tetr = fillit_lstnew(data);
		else
			fillit_lstadd(tetr, data);
		delete_alloc((void**)elem);
		i++;
	}
	delete_alloc((void**)data);
	if ((!(i) || i > 27) && (write(1, "error\n", 6)))
		exit(0);
	g_elems = i - 1;
	extr(tetr);
	return (tetr);
}
