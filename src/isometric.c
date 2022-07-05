/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:12:04 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:34:58 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	dot_center(t_dot *tmp_dot, float ap[3])
{	
	tmp_dot->x -= ap[0];
	tmp_dot->x1 -= ap[0];
	tmp_dot->y -= ap[1];
	tmp_dot->y1 -= ap[1];
}

static void	rotate_x(t_dot *dot, t_fdf *fdf)
{
	float	*ax;
	t_dot	tmp_dot;
	float	ap[3];

	ap[0] = (fdf->x) / 2;
	ap[1] = (fdf->y) / 2;
	ax = &fdf->x_angle;
	tmp_dot = *dot;
	dot_center(&tmp_dot, ap);
	dot->y = cos(*ax) * (tmp_dot.y) - sin(*ax) * (tmp_dot.z);
	dot->z = sin(*ax) * (tmp_dot.y) + cos(*ax) * (tmp_dot.z);
	dot->y1 = cos(*ax) * (tmp_dot.y1) - sin(*ax) * (tmp_dot.z1);
	dot->z1 = sin(*ax) * (tmp_dot.y1) + cos(*ax) * (tmp_dot.z1);
}

static void	rotate_y(t_dot *dot, t_fdf *fdf)
{
	float	*ax;
	t_dot	tmp_dot;
	float	ap[3];

	ap[0] = (fdf->x) / 2;
	ap[1] = (fdf->y) / 2;
	ax = &fdf->y_angle;
	tmp_dot = *dot;
	dot_center(&tmp_dot, ap);
	dot->x = cos(*ax) * (tmp_dot.x) + sin(*ax) * (tmp_dot.z);
	dot->x1 = cos(*ax) * (tmp_dot.x1) + sin(*ax) * (tmp_dot.z1);
	dot->z = sin(*ax) * -(tmp_dot.x) + cos(*ax) * (tmp_dot.z);
	dot->z1 = sin(*ax) * -(tmp_dot.x1) + cos(*ax) * (tmp_dot.z1);
}

static void	rotate_z(t_dot *dot, t_fdf *fdf)
{
	float	*ax;
	t_dot	tmp_dot;

	ax = &fdf->z_angle;
	tmp_dot = *dot;
	dot->x = cos(*ax) * (tmp_dot.x) - sin(*ax) * (tmp_dot.y);
	dot->y = sin(*ax) * (tmp_dot.x) + cos(*ax) * (tmp_dot.y);
	dot->x1 = cos(*ax) * (tmp_dot.x1) - sin(*ax) * (tmp_dot.y1);
	dot->y1 = sin(*ax) * (tmp_dot.x1) + cos(*ax) * (tmp_dot.y1);
}

void	isometric(t_dot *dot, t_fdf *data)
{
	float	tmp_x;
	float	tmp_x1;

	rotate_x(dot, data);
	rotate_y(dot, data);
	rotate_z(dot, data);
	tmp_x = dot->x;
	tmp_x1 = dot->x1;
	dot->x = (tmp_x - dot->y) * cos(data->x_angle);
	dot->y = (tmp_x + dot->y) * sin(data->y_angle) - dot->z;
	dot->x1 = (tmp_x1 - dot->y1) * cos(data->x_angle);
	dot->y1 = (tmp_x1 + dot->y1) * sin(data->y_angle) - dot->z1;
}
