/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:39:17 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/23 19:36:01 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_prog *pnt, int b_x, int b_y, int e_x, int e_y)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		cols;

	delta_x = e_x - b_x;
	delta_y = e_y - b_y;
	pnt->pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	cols = 800 - sqrt(pnt->rows * pnt->rows + pnt->cols * pnt->cols);
	delta_x /= pnt->pixels;
	delta_y /= pnt->pixels;
	pixel_x = b_x;
	pixel_y = b_y;
	set_color(pnt);
	while (pnt->pixels)
	{
		mlx_pixel_put(pnt->mlx, pnt->win, (cols + pixel_x), pixel_y,
			pnt->color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pnt->pixels;
	}
}

static void	fill_rows(int *p1, int *p2, int loc, int l_gap, int z)
{
	int	offset;

	offset = 100;
	p1[0] = offset + loc;
	p1[1] = offset + l_gap;
	p2[0] = offset + loc + 40;
	p2[1] = offset + l_gap;
	rotate_shape(p1, z);
	rotate_shape(p2, z);
}

static void	fill_cols(int *p1, int *p2, int loc, int l_gap, int z)
{
	int	offset;

	offset = 100;
	p1[0] = offset + l_gap;
	p1[1] = offset + loc;
	p2[0] = offset + l_gap;
	p2[1] = offset + loc + 30;
	rotate_shape(p1, z);
	rotate_shape(p2, z);
}

void	write_map(t_prog *pnt, int i, int j, int loc, int l_gap)
{
	int	numb;
	int	col_gaps;
	int	p1[2];
	int	p2[2];

	while (++j <= pnt->rows)
	{
		while (++i < pnt->cols)
		{
			pnt->z = pnt->map[j][i];
			fill_rows(p1, p2, loc, l_gap, pnt->z);
			if (j > 0 && pnt->map[j - 1][i])
				pnt->z = pnt->map[j - 1][i];
			draw_line(pnt, p1[0], p1[1], p2[0], p2[1]);
			loc += 40;
		}
		if (loc)
			numb = loc + 40;
		i = -1;
		loc = 0;
		l_gap += 30;
	}
	j = -1;
	l_gap = 0;
	col_gaps = numb - (pnt->cols * 40);
	loc = 0;
	while (++j <= pnt->cols)
	{
		while (++i <= pnt->rows - 1)
		{
			pnt->z = pnt->map[i][j];
			fill_cols(p1, p2, loc, l_gap, pnt->z);
			if (pnt->map[i][j - 1])
				pnt->z = pnt->map[i][j - 1];
			draw_line(pnt, p1[0], p1[1], p2[0], p2[1]);
			loc += 30;
		}
		i = -1;
		loc = 0;
		l_gap += col_gaps;
	}
}
