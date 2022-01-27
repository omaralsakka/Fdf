/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:15:12 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/27 11:44:42 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*This function assign the pressed button to specific effect or 
change to do in the function*/
static void	effects(int button, t_prog *pnt)
{
	if (button == 124)
		pnt->trg = 0;
	if (button == 123)
		pnt->trg = 1;
	if (button == 126)
		pnt->elev++;
	if (button == 125)
		pnt->elev--;
	if (button == 69)
		pnt->size += 1;
	if (button == 78)
		pnt->size -= 1;
	if (button == 8)
	{
		pnt->b_color += rgb_to_int(0.2, 0.1, 0.4);
		pnt->elv_color += rgb_to_int(0.8, 0.2531, 0.1);
		pnt->ver_color += rgb_to_int(0.1, 0.92331, 0.8);
	}
	mlx_clear_window(pnt->mlx, pnt->win);
	write_map(pnt, -1);
}

/*This function responsible to handle the esc button when pressed*/
int	key_events(int button, t_prog *pnt)
{
	if (button == 53 || button == 65307)
		ft_cases(1);
	if (button > 5 && button < 130)
		effects(button, pnt);
	return (0);
}

/*This function responsible for returning a color value*/
int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

/*sets the color for the lines*/
void	set_color(t_prog *pnt, int *p1, int *p2)
{
	if (p1[2] && p2[2])
		pnt->color = pnt->elv_color;
	else
		pnt->color = pnt->b_color;
}

/*This function rotates the coordinates to isometric shape*/
void	rotate_shape(int *p, t_prog *pnt)
{
	int	x;
	int	y;

	x = p[0];
	y = p[1];
	p[0] = (x - y) / sqrt(2);
	p[1] = ((x + (2 * y)) - (p[2] * pnt->elev)) / sqrt(6);
}
