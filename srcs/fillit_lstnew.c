/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:44:28 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/19 17:44:29 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*fillit_lstnew(int **new_tetr)
{
	t_tetrimino	*new;
	int			i;
	int			j;

	i = 0;
	if ((new = malloc(sizeof(t_tetrimino))) == NULL)
		return (NULL);
	if (new_tetr == NULL)
		return (NULL);
	else
	{
		while (i < 4)
		{
			j = 0;
			while (j < 2)
			{
				new->coord[i][j] = new_tetr[i][j];
				j++;
			}
			i++;
		}
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
