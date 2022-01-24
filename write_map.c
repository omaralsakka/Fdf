/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:39:17 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/24 17:40:25 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_prog *pnt, int *p1, int *p2)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		cols;

	delta_x = p2[0] - p1[0];
	delta_y = p2[1] - p1[1];
	pnt->pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	cols = 800 - sqrt(pnt->rows * pnt->rows + pnt->cols * pnt->cols);
	delta_x /= pnt->pixels;
	delta_y /= pnt->pixels;
	pixel_x = p1[0];
	pixel_y = p1[1];
	set_color(pnt, p1, p2);
	while (pnt->pixels)
	{
		if ((!p1[2] && p2[2]) || (p1[2] && !p2[2]))
			pnt->color = rgb_to_int(1, 0.81, 0);
		mlx_pixel_put(pnt->mlx, pnt->win, (cols + pixel_x), pixel_y,
			pnt->color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pnt->pixels;
	}
}

static void	fill_rows(int *p1, int *p2, t_prog *pnt, int l_gap)
{
	int	offset;

	offset = 100;
	p1[0] = offset + (pnt->i * 20);
	p1[1] = offset + (l_gap * 20);
	p2[0] = offset + (pnt->i * 20) + 20;
	p2[1] = offset + (l_gap * 20);
	rotate_shape(p1);
	rotate_shape(p2);
}

static void	fill_cols(int *p1, int *p2, t_prog *pnt, int l_gap)
{
	int	offset;

	offset = 100;
	p1[0] = offset + (l_gap * 20);
	p1[1] = offset + (pnt->i * 20);
	p2[0] = offset + (l_gap * 20);
	p2[1] = offset + (pnt->i * 20) + 20;
	rotate_shape(p1);
	rotate_shape(p2);
}

static void	draw_cols(t_prog *pnt, int *p1, int *p2, int j)
{
	pnt->i = -1;
	while (++j <= pnt->cols)
	{
		while (++pnt->i < pnt->rows)
		{
			p1[2] = pnt->map[pnt->i][j];
			p2[2] = p1[2];
			if (pnt->map[pnt->i + 1][j] && !pnt->map[pnt->i][j])
				p2[2] = pnt->map[pnt->i + 1][j];
			if (pnt->map[pnt->i][j] && !pnt->map[pnt->i + 1][j])
				p2[2] = pnt->map[pnt->i + 1][j];
			fill_cols(p1, p2, pnt, j);
			if (pnt->i > 0 && j > 0 && pnt->map[pnt->i][j - 1])
				p1[2] = pnt->map[pnt->i][j - 1];
			draw_line(pnt, p1, p2);
		}
		pnt->i = -1;
	}
}

void	write_map(t_prog *pnt, int j)
{
	int	p1[3];
	int	p2[3];

	pnt->i = -1;
	while (++j <= pnt->rows)
	{
		while (++pnt->i < pnt->cols)
		{
			p1[2] = pnt->map[j][pnt->i];
			p2[2] = p1[2];
			if (pnt->map[j][pnt->i + 1])
				p2[2] = pnt->map[j][pnt->i + 1];
			if (pnt->map[j][pnt->i] && !pnt->map[j][pnt->i + 1])
				p2[2] = pnt->map[j][pnt->i + 1];
			fill_rows(p1, p2, pnt, j);
			if (j > 0 && pnt->map[j - 1][pnt->i])
				p1[2] = pnt->map[j - 1][pnt->i];
			draw_line(pnt, p1, p2);
		}
		pnt->i = -1;
	}
	draw_cols(pnt, p1, p2, -1);
}
