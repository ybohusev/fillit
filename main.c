/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:45:22 by ybohusev          #+#    #+#             */
/*   Updated: 2017/12/04 14:45:25 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	t_tetrimino		*tetr;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	tetr = read_data(argv[1]);
	
	int i = 0;

	while (i < 4)
	{
		printf("all result Y: %d\t\t", tetr->coord[i][0]);
		printf("all result X: %d\n", tetr->coord[i][1]);
		i++;
	}
	printf("\n");
	algor(tetr);
	i = 0;
	while (i < 4)
	{
		printf("all result Y: %d\t\t", tetr->coord[i][0]);
		printf("all result X: %d\n", tetr->coord[i][1]);
		i++;
	}

	return (0);
}
