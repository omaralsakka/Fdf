/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:32:25 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/19 10:12:00 by oabdelfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* This function handles all kinds of message casses, and used in simple form by
sending a specific number that corresponds to a message case, first case is the
only case that ends without an error */

void ft_cases(int i)
{   
    if (i == 1)
    {
		ft_putendl("Thank you, Bye Bye");
		exit(0);
    }
    if (i == 2)
    {
		ft_putendl("fdf: missing file operand");
		ft_putendl("usage: './fillit <filename>'"); 
    }
    if (i == 3)
		ft_putendl("Error: File missing");
    if (i == 4)
		ft_putendl("Error: File Error");
	if (i == 5)
		ft_putendl("Error: Map mallocing unsuccecful");
	if (i == 6)
		ft_putendl("Error: Map width error");
	exit (EXIT_FAILURE);
}