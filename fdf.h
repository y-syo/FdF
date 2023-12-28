/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:19 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/28 20:25:56 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// --------------- INCLUDES ---------------

# include "MacroLibX/includes/mlx.h"
# include "printf/ft_printf.h"

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

// --------------- FUNCS ---------------

int	draw_line(t_coords c1, t_mlx *mlx);

#endif
