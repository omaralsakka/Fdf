/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:47:09 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/25 14:04:37 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft.h"
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
	int		pixels;
	int		color;
	int		i;
	int		trg;
	int		elev;
	int		size;
	int		b_color;
	int		elv_color;
	int		ver_color;
}				t_prog;

/* all main functions that are called within the program */
void	ft_cases(int i);
void	read_map(char *map, int fd, t_prog *pnt);
void	write_map(t_prog *pnt, int j);
int		key_events(int button, t_prog *pnt);
int		rgb_to_int(double r, double g, double b);
void	rotate_shape(int *p, t_prog *pnt);
void	set_color(t_prog *pnt, int *p1, int *p2);

#endif