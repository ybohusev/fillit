/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:27:59 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/14 16:28:10 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	free_malloc(char **data)
{
	int i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	data = NULL;
}

static	void	set_arr(char **smallest, t_tetrimino *tetr, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		smallest[tetr->coord[i][0]][tetr->coord[i][1]] = c;
		i++;
	}
	if (tetr->next)
		set_arr(smallest, tetr->next, c + 1);
}

extern	void	display_data(t_tetrimino *tetr, int field)
{
	char	**smallest;
	int		i;

	i = 0;
	smallest = (char**)malloc(sizeof(char*) * field + 1);
	while (i < field)
	{
		smallest[i] = (char*)malloc((sizeof(char) * field + 1));
		smallest[i][field] = '\0';
		smallest[i] = ft_memset(smallest[i], '.', field);
		i++;
	}
	set_arr(smallest, tetr, 'A');
	i = 0;
	while (i < field)
	{
		ft_putstr(smallest[i]);
		ft_putchar('\n');
		i++;
	}
	smallest[field] = NULL;
	free_malloc(smallest);
}
