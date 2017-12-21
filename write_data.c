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

static	void			delete_alloc(void	**data)
{
	int	j;

	j = -1;
	while (data[++j])
		free(data[j]);
	free(data);
}

static	int				**write_to_arr(char **elem)
{
	int		**coord;
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	coord = (int**)fillit_memalloc(4, 2);
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
			}
			j++;
		}
		i++;
	}
	return (coord);
}

extern	t_tetrimino		*write_data(int fd)
{
	int			*error;
	int			i;
	t_tetrimino *tetr;
	char		**elem;
	int			**data;

	tetr = NULL;
	i = 1;
	error = &i;
	elem = (char**)fillit_memalloc(4, 5);
	while ((elem = check_valid(fd, error)) && *error)
	{
		data = write_to_arr(elem);
		if (!tetr)
			tetr = fillit_lstnew(data);
		else
			fillit_lstadd(tetr, data);
		delete_alloc((void**)elem);
		delete_alloc((void**)data);
		i++;
	}
	if ((!(*error) || i > 26) && (write(1, "error\n", 7)))
		exit(0);
	return (tetr);
}
