/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:15:12 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/23 12:32:58 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*This function responsible to handle the esc button when pressed*/
int	key_events(int button)
{
	if (button == 53 || button == 65307)
		ft_cases(1);
	return (0);
}

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void rotate_shape(int *pixel_x, int *pixel_y, int z)
{
    int x = *pixel_x;
    int y = *pixel_y;
    
    *pixel_x = (x - y) / sqrt(2);
    *pixel_y = (x + 2 * y - z) / sqrt(6);
}