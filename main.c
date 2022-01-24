/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:45:57 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/24 11:37:54 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* REMEMBER TO ADD .C FILES OF ALL USED MLX FUNCTIONS AND PUSH IT !!!! */

int	main(int argc, char **argv)
{
	int		fd;
	t_prog	pnt;

	if (argc != 2)
		ft_cases(2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_cases(2);
	read_map(argv[1], fd, &pnt);
	pnt.mlx = mlx_init();
	pnt.win = mlx_new_window(pnt.mlx, 1680, 1050, "fdf window");
	write_map(&pnt, -1, -1, 0, 0);
	mlx_key_hook(pnt.win, &key_events, &pnt);
	mlx_loop(pnt.mlx);
	return (0);
}
