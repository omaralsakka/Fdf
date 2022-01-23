/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:39:17 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/23 12:32:40 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_prog *pnt, int b_x, int b_y, int e_x, int e_y, int color)
{
    double  delta_x;
    double  delta_y;
    int		pixels;
	int		width;
	double  pixel_x;
    double  pixel_y;

	delta_x = e_x - b_x;
	delta_y = e_y - b_y;
	pixel_x = b_x;
    pixel_y = b_y;
	rotate_shape(&b_x, &b_y, pnt->z);
	rotate_shape(&e_x, &e_y, pnt->z);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	width = 800 - sqrt(pnt->rows * pnt->rows + pnt->cols * pnt->cols);

    delta_x /= pixels;
    delta_y /= pixels;    
    if (pnt->z)
        color = rgb_to_int(1, 0.2531 ,1);
    while (pixels)
    {   
        mlx_pixel_put(pnt->mlx, pnt->win, (width + pixel_x), pixel_y, color);
        pixel_x += delta_x;
        pixel_y += delta_y;
        --pixels;
    }
}

void write_map(t_prog *pnt, int i , int j, int loc)
{
    int color = rgb_to_int(1, 1, 1);;
    int beginx = 100;
    int beginy = 100;
    int endx = 140;
    int endy = 100;
    int l_gap = 0;
    int numb;
    int col_gaps;

    while (++j < pnt->rows)
    {
        while (++i <= pnt->cols)
        {
			pnt->z = pnt->map[j][i];
            draw_line(pnt, beginx + loc, beginy + l_gap, endx + loc, endy + l_gap, color);
            loc += 40;
        }
       numb = ((endx - 40) + loc);
       i = -1;
       loc = 0;
       l_gap += 30;
    }
    j = -1;
    loc = 0;
    endx = 100;
    endy = 130;
    col_gaps = (numb - 100) / pnt->cols;

    while (++j <= pnt->cols)
    {
        while (++i < pnt->rows - 1)
        {
            pnt->z = pnt->map[i][j];
            draw_line(pnt, beginx, beginy + loc, endx, endy + loc, color);
            loc += 30;
        }
        i = -1;
        loc = 0;
        beginx += col_gaps;
        endx += col_gaps;
    }
}
