/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:15:12 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/24 16:36:39 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*This function responsible to handle the esc button when pressed*/
int	key_events(int button, t_prog *pnt)
{
	(void)pnt;
	if (button == 53 || button == 65307)
		ft_cases(1);
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

void	set_color(t_prog *pnt, int *p1, int *p2)
{
	if (p1[2] && p2[2])
		pnt->color = rgb_to_int(1, 0.2531, 1);
	else
		pnt->color = rgb_to_int(1, 1, 1);
}

/*This function rotates the coordinates to isometric shape*/
void	rotate_shape(int *p)
{
	int	x;
	int	y;

	x = p[0];
	y = p[1];
	p[0] = (x - y) / sqrt(2);
	p[1] = ((x + (2 * y)) - (p[2] * 4)) / sqrt(6);
}
