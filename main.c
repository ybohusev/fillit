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
		write(1, "usage: ./fillit source_file\n", 26);
		exit(0);
	}
	tetr = read_data(argv[1]);
	search_s(tetr);
	printf("all result: %d\n", tetr->coord[1][0]);
	printf("all result: %d\n", tetr->coord[1][1]);
	printf("all result: %d\n", tetr->next->coord[0][0]);
	printf("all result: %d\n", tetr->next->coord[0][1]);
	printf("all result: %d\n", tetr->next->next->coord[0][0]);
	printf("all result: %d\n", tetr->next->next->coord[0][1]);
	system("leaks test");
	return (0);
}
