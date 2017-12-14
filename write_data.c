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

t_tetrimino		*write_data(int fd)
{
	t_tetrimino *list;
	char		**elem;

	elem = check_valid(fd);
	while (elem != NULL)
	{
		
		elem = check_valid(fd);
	}
	return(list)
}