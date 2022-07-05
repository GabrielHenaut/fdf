/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:14:35 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:35:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	find_x(t_fdf *data, char *file)
{
	char	**rtn;
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	rtn = ft_split(line, ' ');
	while (rtn[i])
		i++;
	data->x = i;
	free(line);
	free_split(rtn);
	close(fd);
}

static void	find_y(t_fdf *data, char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->y = i;
	close(fd);
}

static void	init_matrix(t_fdf *data, char *file)
{
	int		i;

	find_x(data, file);
	find_y(data, file);
	i = -1;
	data->matrix = (int **)malloc((data->y + 1) * sizeof(int *));
	while (++i < data->y)
		data->matrix[i] = (int *)malloc((data->x + 1) * sizeof(int));
}

static void	init_data(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "FDF");
	data->x_shift = 260;
	data->y_shift = 180;
	data->color = 0x78dc20;
	data->zoom = 35;
	data->x_angle = 5.635987;
	data->y_angle = 6.340062;
	data->z_angle = 6.259997;
	data->z_scale = 1;
	data->view = 'i';
}

void	init_game(t_fdf *data, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**rtn;

	init_data(data);
	init_matrix(data, file);
	fd = open(file, O_RDONLY);
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		rtn = ft_split(line, ' ');
		while (rtn[++i])
			data->matrix[j][i] = atoi(rtn[i]);
		j++;
		free(line);
		free_split(rtn);
		line = get_next_line(fd);
	}
}
