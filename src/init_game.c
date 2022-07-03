/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:14:35 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/02 18:13:00 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void find_x(t_fdf *data, char *file)
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

static void find_y(t_fdf *data, char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		i++;
		free(line);
	}
	data->y = i;
	close(fd);
}

static void init_matrix(t_fdf *data, char *file)
{
	int		i;

	find_x(data, file);
	find_y(data, file);
	i = -1;
	data->matrix = (int**)malloc((data->y + 1) * sizeof(int *));
	while (++i < data->y)
		data->matrix[i] = (int*)malloc((data->x + 1) * sizeof(int));
}

void    init_game(t_fdf *data, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**rtn;

	init_matrix(data, file);
	fd = open(file, O_RDONLY);
	j = 0;
	while((line = get_next_line(fd)))
	{
		i = -1;
		rtn = ft_split(line, ' ');
		while (rtn[++i])
			data->matrix[j][i] = atoi(rtn[i]);
		j++;
		// ft_printf("%s\n", line);
		free(line);
		free_split(rtn);
	}
}