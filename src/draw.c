/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:51:50 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/03 15:12:25 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	// int z1;

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z = data->matrix[(int)y][(int)x];
	// z1 = data->matrix[(int)y1][(int)x1];
	data->color = (z) ? 0xe80cc0c : 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while(((int)(x - x1)) || ((int)(y - y1)))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,x ,y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->y - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}