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
	int				field;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	tetr = read_data(argv[1]);
	field = algor(tetr);
	display_data(tetr, field);
	return (0);
}
