/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:43:14 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 19:00:59 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEYPRESS 2
# define KEYPRESSMASK 1
# define REFOCUS 07 
# define DESTROY 17
# define DESTROYMASK 0L

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dot
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;

	int		color;
}				t_dot;

typedef struct s_fdf
{
	int		**matrix;
	int		y;
	int		x;
	int		zoom;
	int		color;
	int		x_shift;
	int		y_shift;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	char	view;
	float	z_scale;
	char	config;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

void	init_game(t_fdf *data, char *file);
void	free_split(char **split);
void	draw(t_fdf *data);
int		clean_exit(t_fdf *data);
int		arrows_down(int key, t_fdf *data);
void	set_isometric(t_fdf *data);
void	set_paralle(t_fdf *data);
void	isometric(t_dot *dot, t_fdf *data);
int		find_mod(float value);
int		find_max(float a, float b);
int		find_color(float z, float z1, int color);

#endif