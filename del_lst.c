/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:51:56 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/19 15:51:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_lst(t_tetrimino *tetrim)
{
	int	i;

	i = 0;
	if (tetrim)
	{
		if (tetrim->next == NULL)
		{
			while (i < 4)
			{
				free(tetrim->coord[i]);
				i++;
			}
			tetrim = NULL;
		}
		else
		{
			del_lst(tetrim->next);
		}
	}
	return ;
}
