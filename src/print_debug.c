/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:30:13 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/02 17:39:48 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_debug(t_fdf *data)
{
	int i = 0;
    int j = 0;

    while (i < data->y - 1)
    {
        j = 0;
        while (j < data->x - 1)
        {
            ft_printf("%3d", data->matrix[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
    ft_printf("\n\n");
}