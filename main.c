/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:45:57 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/24 19:41:23 by oabdelfa         ###   ########.fr       */
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
	pnt.elev = 4;
	pnt.size = 20;
	pnt.b_color = rgb_to_int(1, 1, 1);
	pnt.elv_color = rgb_to_int(1, 0.2531, 1);
	pnt.ver_color = rgb_to_int(1, 0.81, 0);
	write_map(&pnt, -1);
	mlx_key_hook(pnt.win, &key_events, &pnt);
	mlx_loop(pnt.mlx);
	return (0);
}
