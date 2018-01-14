/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_memalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:16:43 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/19 18:16:54 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**fillit_memalloc(int size_x, int size_y)
{
	int		**freshmem;
	int		i;

	i = 0;
	if ((freshmem = (int**)malloc((sizeof(int*) * size_x) + 1)))
	{
		freshmem[size_x] = NULL;
		while (i < size_x)
		{
			if ((freshmem[i] = (int*)malloc(sizeof(int) * size_y)))
				ft_bzero(freshmem[i], size_y * sizeof(int));
			i++;
		}
		return (freshmem);
	}
	return (NULL);
}
