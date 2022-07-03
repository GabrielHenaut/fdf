/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:52:55 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/03 15:12:07 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_file_extension(char *s)
{
	size_t	offset;

	offset = ft_strlen(s) - 4;
	if (ft_strncmp(".fdf", s + offset, 5) == 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
    t_fdf data;

    if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		exit(1);
		return (1);
	}
    if (!is_valid_file_extension(argv[1]))
	{
		ft_printf("Error\nInvalid file extension\n");
		exit(1);
		return (1);
	}
    init_game(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "FDF");
	data.zoom = 20;
	draw(&data);
	// mlx_key_hook(data.win_ptr, deal_key, NULL);
	mlx_loop(data.mlx_ptr);
    print_debug(&data);
    free_matrix(data.matrix, data.y);
}