/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:39:17 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/02/04 16:36:16 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*This function draws lines to the window screen, by starting from p1x and 
p1y to p2x and p2y, it then calculates line direction which is delta x and y, 
then sets the color of the line and finally loops with pixels amount to draw 
the asked line.*/
static void	draw_line(t_prog *pnt, int *p1, int *p2)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		c_width;

	delta_x = p2[0] - p1[0];
	delta_y = p2[1] - p1[1];
	pnt->pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	c_width = 800 - sqrt(pnt->rows * pnt->rows + pnt->cols * pnt->cols);
	delta_x /= pnt->pixels;
	delta_y /= pnt->pixels;
	pixel_x = p1[0];
	pixel_y = p1[1];
	set_color(pnt, p1, p2);
	while (pnt->pixels)
	{
		if ((p1[2] < p2[2]) || (p1[2] > p2[2]))
			pnt->color = pnt->ver_color;
		mlx_pixel_put(pnt->mlx, pnt->win, (c_width + pixel_x), pixel_y,
			pnt->color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pnt->pixels;
	}
}

/*filling the 2d arrays with rows coordinates, offset is the distance from 
the screen top left side, going to the right*/
static void	fill_rows(int *p1, int *p2, t_prog *pnt, int l_gap)
{
	p1[0] = pnt->offset + (pnt->i * pnt->size);
	p1[1] = pnt->offset + (l_gap * pnt->size);
	p2[0] = pnt->offset + (pnt->i * pnt->size) + pnt->size;
	p2[1] = pnt->offset + (l_gap * pnt->size);
	if (pnt->trg)
	{
		rotate_shape(p1, pnt);
		rotate_shape(p2, pnt);
	}
}

/*filling the 2d arrays with cols coordinates*/
static void	fill_cols(int *p1, int *p2, t_prog *pnt, int l_gap)
{
	p1[0] = pnt->offset + (l_gap * pnt->size);
	p1[1] = pnt->offset + (pnt->i * pnt->size);
	p2[0] = pnt->offset + (l_gap * pnt->size);
	p2[1] = pnt->offset + (pnt->i * pnt->size) + pnt->size;
	if (pnt->trg)
	{
		rotate_shape(p1, pnt);
		rotate_shape(p2, pnt);
	}
}

/*drawing columns lines*/
static void	draw_cols(t_prog *pnt, int *p1, int *p2, int j)
{
	pnt->i = -1;
	while (++j <= pnt->cols)
	{
		while (++pnt->i < pnt->rows)
		{
			p1[2] = pnt->map[pnt->i][j];
			p2[2] = p1[2];
			if (pnt->map[pnt->i + 1][j] > pnt->map[pnt->i][j])
				p2[2] = pnt->map[pnt->i + 1][j];
			if (pnt->map[pnt->i][j] > pnt->map[pnt->i + 1][j])
				p2[2] = pnt->map[pnt->i + 1][j];
			fill_cols(p1, p2, pnt, j);
			if (pnt->i > 0 && j > 0 && pnt->map[pnt->i][j - 1])
				p1[2] = pnt->map[pnt->i][j - 1];
			draw_line(pnt, p1, p2);
		}
		pnt->i = -1;
	}
}

/*Here we start by creating 2 2d arrays which will save starting x,y 
and ending x,y then start drawing the rows first then called drawing cols 
function afterwards*/
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
			if (pnt->map[j][pnt->i] > pnt->map[j][pnt->i + 1])
				p2[2] = pnt->map[j][pnt->i + 1];
			fill_rows(p1, p2, pnt, j);
			if (j > 0 && pnt->map[j - 1][pnt->i])
				p1[2] = pnt->map[j - 1][pnt->i];
			draw_line(pnt, p1, p2);
		}
		pnt->i = -1;
	}
	draw_cols(pnt, p1, p2, -1);
	mlx_string_put(pnt->mlx, pnt->win, 50, 970, 16777215, "Keys Menu");
	mlx_string_put(pnt->mlx, pnt->win, 50, 1000, 16777215, "left & right\
	 arrows: projection | +, - : size | up & down arrows: 3d elevation\
	 | C: colors | esc: exit");
}
