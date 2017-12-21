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

void	**fillit_memalloc(size_t size_x, size_t size_y)
{
	void	**freshmem;
	size_t	i;

	i = 0;
	if ((freshmem = (void*)malloc(size_x)))
	{
		while (i < size_x)
		{
			if ((freshmem[i] = (void**)malloc(size_y)))
				ft_bzero(freshmem, size_y);
			i++;
		}
		return (freshmem);
	}
	return (NULL);
}
