/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:51:50 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:35:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	init_dot(t_fdf *data, t_dot *dot, float x, float y)
{
	if (data->config == '1')
	{
		dot->x1 = x + 1;
		dot->y1 = y;
	}
	if (data->config == '2')
	{
		dot->y1 = y + 1;
		dot->x1 = x;
	}
	dot->x = x;
	dot->y = y;
	dot->z = (data->matrix[(int)dot->y][(int)dot->x]) * data->z_scale;
	dot->z1 = data->matrix[(int)dot->y1][(int)dot->x1] * data->z_scale;
	dot->color = find_color(dot->z, dot->z1, data->color);
	dot->x *= data->zoom;
	dot->y *= data->zoom;
	dot->x1 *= data->zoom;
	dot->y1 *= data->zoom;
	if (data->view == 'i')
		isometric(dot, data);
	dot->x += data->x_shift;
	dot->x1 += data->x_shift;
	dot->y += data->y_shift;
	dot->y1 += data->y_shift;
}

static void	put_pixel(t_img *img, t_dot *dot)
{
	char	*pixel;

	if (dot->x < 0 || dot->x >= 1920 || dot->y < 0 || dot->y >= 1080)
		return ;
	pixel = img->addr + (((int)dot->y) * img->line_length + \
				((int)dot->x) * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = dot->color;
}

static void	bresenham(t_fdf *data, float x, float y, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max;
	t_dot	dot;

	init_dot(data, &dot, x, y);
	x_step = dot.x1 - dot.x;
	y_step = dot.y1 - dot.y;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(dot.x - dot.x1)) || ((int)(dot.y - dot.y1)))
	{
		put_pixel(img, &dot);
		dot.x += x_step;
		dot.y += y_step;
	}
}

void	init_img(t_img *img, t_fdf *data)
{
	img->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;
	t_img	img;

	init_img(&img, data);
	y = -1;
	while (++y < data->y)
	{
		x = -1;
		while (++x < data->x)
		{
			if (x < data->x - 1)
			{
				data->config = '1';
				bresenham(data, x, y, &img);
			}
			if (y < data->y - 1)
			{	
				data->config = '2';
				bresenham(data, x, y, &img);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img);
}
