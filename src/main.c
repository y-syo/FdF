/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:53 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/30 22:23:51 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_end(int event, void *mlx)
{
	if (!event)
		mlx_loop_end(mlx);
	return (0);
}

/*int	on_mouse_event(int event, void *data)
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
}*/

void	draw_map(t_map *map, t_mlx *mlx)
{
	t_coords	c1;
	t_coords	c2;
	for (int i = 0; i + 1 < 16; i++)
	{
		ft_printf("%d | %d\n", map[i].x, map[i].y);
		if (map[i].x != 3 && map[i].y)
		{
			c1.x = map[i].x * 50;
			c1.y = map[i].y * 50;
			c2.x = map[i + 1].x * 50;
			c2.y = map[i + 1].y * 50;
			draw_line(c1, c2, mlx);
		}
		if (i < 12)
		{
			c2.x = map[i + 4].x * 50;
			c2.y = map[i + 4].y * 50;
			draw_line(c1, c2, mlx);
		}
	}
}

void	parse(int argc, char **argv, t_map **map)
{
	(void)argc;
	(void)argv;
	*map = malloc(16 * sizeof(t_map));
	for (int i = 0; i < 16; i++)
	{
		(*map)[i].x = i % 4;
		(*map)[i].y = i / 4;
		(*map)[i].z = 1;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	*map;

	mlx.mouse_x = -1;
	mlx.mouse_y = -1;
	if (argc == 2)
		parse(argc, argv, &map);
	else
		return (-1);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 727, 727, "kys");
	mlx_on_event(mlx.mlx_ptr, mlx.win_ptr, 5, mlx_end, mlx.mlx_ptr);
	// mlx_on_event(mlx.mlx_ptr, mlx.win_ptr, 2, on_mouse_event, &mlx);
	draw_map(map, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	return (0);
}
