/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:47:58 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:35:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	set_isometric(t_fdf *data)
{
	data->view = 'i';
	data->x_shift = 260;
	data->y_shift = 180;
	data->zoom = 35;
	data->x_angle = 5.635987;
	data->y_angle = 6.340062;
	data->z_angle = 6.259997;
	data->z_scale = 1;
}

void	set_paralle(t_fdf *data)
{
	data->view = 'p';
	data->x_shift = 130;
	data->y_shift = 140;
	data->zoom = 30;
	data->z_scale = 1;
}
