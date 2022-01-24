/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:47:09 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/24 16:32:00 by oabdelfa         ###   ########.fr       */
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
	int		key;
	int		pixels;
	int		color;
}				t_prog;

typedef struct i_program
{
	int		i;
	int		j;
}				i_prog;

/* all main functions that are called within the program */
void	ft_cases(int i);
void	read_map(char *map, int fd, t_prog *pnt);
void	write_map(t_prog *pnt, int i, int j, int loc, int l_gap);
int		key_events(int button, t_prog *pnt);
int		rgb_to_int(double r, double g, double b);
void	rotate_shape(int *p);
void	set_color(t_prog *pnt, int *p1, int *p2);

#endif