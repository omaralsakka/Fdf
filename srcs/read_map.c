/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:11:54 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/25 14:32:58 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*reading the cols and rows of the given map, then assigning it to
 the struct, the rows set as the rows & the columns as cols*/
static void	read_cols_rows(int fd, char *line, t_prog *pnt)
{
	char	**str;
	char	*tmp;
	int		i;

	i = 0;
	str = ft_strsplit(line, ' ');
	tmp = ft_strdup(line);
	while (str[i])
		i++;
	ft_free_array((void **)str, i);
	pnt->cols = i - 1;
	i = 0;
	while (get_next_line(fd, &tmp))
		i++;
	ft_free(tmp, ft_strlen(tmp));
	pnt->rows = i;
}

/*Mallocing for the map within the struct by making each rows as one 
string and each string contains as many chars as the cols is*/
static void	map_malloc(t_prog *pnt)
{
	int	i;

	i = -1;
	pnt->map = (int **)malloc(sizeof (int *) * pnt->rows + 1);
	if (!(pnt->map))
		ft_cases(5);
	while (++i <= pnt->rows)
	{
		pnt->map[i] = (int *)malloc(sizeof(int) * pnt->cols);
		if (!(pnt->map[i]))
			ft_free_array((void **)pnt->map, i);
	}
}

/*Converting each line content first to number then saving it into each
int within the map array*/
static void	map_assigning(int fd, char *map, t_prog *pnt)
{
	char	**tmp;
	char	*line;
	int		i;
	int		n;

	i = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		n = -1;
		while (tmp[++n])
			pnt->map[i][n] = ft_atoi(tmp[n]);
		ft_free_array((void **)tmp, n);
		if ((n - 1) != pnt->cols)
			ft_cases(6);
		i++;
	}
	close(fd);
}

/*This function initilize the values of the tlist that will be used later
to draw the map*/
static void	init_values(t_prog *pnt)
{
	pnt->elev = 4;
	pnt->size = 20;
	pnt->b_color = rgb_to_int(1, 1, 1);
	pnt->elv_color = rgb_to_int(1, 0.2531, 1);
	pnt->ver_color = rgb_to_int(1, 0.81, 0);
}

/*Reading the givin string map and saving it into the struct pnt*/
void	read_map(char *map, int fd, t_prog *pnt)
{
	char	*line;

	if (!(get_next_line(fd, &line)))
		ft_cases(4);
	if (!(ft_strsplit(line, ' ')))
		ft_cases(4);
	read_cols_rows(fd, line, pnt);
	map_malloc(pnt);
	close(fd);
	map_assigning(fd, map, pnt);
	init_values(pnt);
}
