/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:53 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/28 21:04:53 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_end(int event, void *mlx)
{
	if (!event)
		mlx_loop_end(mlx);
	return (0);
}

int	on_mouse_event(int event, void *data)
{
	t_mlx		*mlx;
	t_coords	c;

	mlx = data;
	if (event == 1)
	{
		if (mlx->mouse_x > 0)
		{
			mlx_mouse_get_pos(mlx->mlx_ptr, &c.x, &c.y);
			draw_line(c, mlx);
			mlx->mouse_x = -1;
		}
		else
		{
			mlx_mouse_get_pos(mlx->mlx_ptr, &c.x, &c.y);
			mlx->mouse_x = c.x;
			mlx->mouse_y = c.y;
		}
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mouse_x = -1;
	mlx.mouse_y = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 727, 727, "ft_seekers");
	mlx_on_event(mlx.mlx_ptr, mlx.win_ptr, 5, mlx_end, mlx.mlx_ptr);
	mlx_on_event(mlx.mlx_ptr, mlx.win_ptr, 2, on_mouse_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	return (0);
}
