/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:47:09 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/23 12:34:08 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft.h"
# include <stdio.h> //DELETE THIS
# include <fcntl.h>
# include <stdlib.h>

/*This is the struct that saves the map info and to which window it will open*/
typedef struct s_program
{
	void	*mlx;
	void	*win;
	int		cols;
	int		rows;
	int		**map;
	int		z;
}				t_prog;

/* all main functions that are called within the program */
void	ft_cases(int i);
void	read_map(char *map, int fd, t_prog *pnt);
void	write_map(t_prog *pnt ,int i , int j,int loc);
int		key_events(int button);
void	draw_line(t_prog *pnt, int s_x, int s_y, int e_x, int e_y, int color);
int		rgb_to_int(double r, double g, double b);
void 	rotate_shape(int *pixel_x, int *pixel_y, int z);

#endif