/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lstadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:08:31 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/21 15:08:33 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_lstadd(t_tetrimino *list_elem, int **new_tetr)
{
	t_tetrimino *current;
	int			i;
	int			j;

	i = 0;
	current = list_elem;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_tetrimino));
	if (current->next == NULL)
		current->next = NULL;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			current->next->coord[i][j] = new_tetr[i][j];
			j++;
		}
		i++;
	}
	current->next->prev = current;
	current->next->next = NULL;
}
