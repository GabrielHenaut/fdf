/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:52:08 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/05 20:35:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	find_mod(float value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

int	find_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	find_color(float z, float z1, int color)
{
	if (z || z1)
		return (color);
	else
		return (0xffffff);
}
