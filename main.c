/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:53 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/27 19:32:35 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "printf/ft_printf.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mouse_x;
	int		mouse_y;
}	t_mlx;

int	mlx_end(int event, void *mlx)
{
	if (!event)
		mlx_loop_end(mlx);
	return (0);
}

int	draw_line(int x1, int y1, t_mlx *mlx)
{
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	e;

	x2 = mlx->mouse_x;
	y2 = mlx->mouse_y;
	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x2, y2, 0xFFFFFFFF);
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFFFFFFFF);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
	ft_printf("\n");
}

int	on_mouse_event(int event, void *data)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = data;
	if (event == 1)
	{
		if (mlx->mouse_x > 0)
		{
			mlx_mouse_get_pos(mlx->mlx_ptr, &x, &y);
			draw_line(x, y, mlx);
			mlx->mouse_x = -1;
		}
		else
		{
			mlx_mouse_get_pos(mlx->mlx_ptr, &x, &y);
			mlx->mouse_x = x;
			mlx->mouse_y = y;
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
