/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:43:14 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/03 15:04:12 by ghenaut-         ###   ########.fr       */
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

# define MOD(Value) ({int x; if (Value < 0) x = (-Value); else x = Value; x;})
# define MAX(a, b) ({int x; if (a < b) x = (b); else x = a; x;})

typedef struct s_fdf
{
	int		**matrix;
	int		y;
	int		x;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}   t_fdf;

void    init_game(t_fdf *data, char *file);
void	free_matrix(int **matrix, int y);
void	free_split(char **split);
void	draw(t_fdf *data);

// remove when done
void	print_debug(t_fdf *data);


#endif