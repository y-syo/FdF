/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:19 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/30 22:09:30 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// --------------- INCLUDES ---------------

# include "../MacroLibX/includes/mlx.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

// --------------- STRUCTS ---------------

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mouse_x;
	int		mouse_y;
}	t_mlx;

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_map;

// --------------- FUNCS ---------------

void	draw_line(t_coords c1, t_coords c2, t_mlx *mlx);

#endif
