/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:30:39 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:35:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* 119 = w || 97 = a || 115 = s || 100 = d || 65362 = aroow_up */
/* 65364 = arrow_down || 65361 = arrow_left ||65361 = arrow_right || 44 = , */
/* 46 = . || 120 = x || 122 = z */
static void	handle_keys_1(int key, t_fdf *data)
{
	if (key == 119)
		data->y_shift -= 10;
	if (key == 97)
		data->x_shift -= 10;
	if (key == 115)
		data->y_shift += 10;
	if (key == 100)
		data->x_shift += 10;
	if (key == 65362)
		data->y_angle += 0.02;
	if (key == 65364)
		data->y_angle -= 0.02;
	if (key == 65363)
		data->x_angle += 0.02;
	if (key == 65361)
		data->x_angle -= 0.02;
	if (key == 44)
		data->z_angle += 0.02;
	if (key == 46)
		data->z_angle -= 0.02;
	if (key == 120)
		data->zoom += 2;
	if (key == 122)
		data->zoom -= 2;
}

/* 105 = i || 112 = p || 49 = 1 || 50 = 2 || 51 = 3 || 99 = c || 118 = v*/
static void	handle_keys_2(int key, t_fdf *data)
{
	if (key == 105)
		set_isometric(data);
	if (key == 112)
		set_paralle(data);
	if (key == 49)
		data->color = 0xff2121;
	if (key == 50)
		data->color = 0x78dc20;
	if (key == 51)
		data->color = 0x36a5e4;
	if (key == 99)
		data->z_scale -= 0.3;
	if (key == 118)
		data->z_scale += 0.3;
}

int	arrows_down(int key, t_fdf *data)
{
	handle_keys_1(key, data);
	handle_keys_2(key, data);
	if (key == 113 || key == 65307)
	{
		clean_exit(data);
		return (0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
