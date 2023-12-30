/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:10:00 by mmoussou          #+#    #+#             */
/*   Updated: 2023/12/30 22:09:34 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_1(t_coords c1, t_coords c2, t_coords d, t_mlx *mlx)
{
	int	e;

	if (d.x >= d.y)
	{
		e = d.x;
		d.x *= 2;
		d.y *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (++c1.x == c2.x)
				break ;
			e -= d.y;
			if (e < 0)
			{
				c1.y++;
				e += d.x;
			}
		}
	}
	else
	{
		e = d.y;
		d.y *= 2;
		d.x *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (++c1.y == c2.y)
				break ;
			e -= d.x;
			if (e < 0)
			{
				c1.x++;
				e += d.y;
			}
		}
	}
}

void	draw_line_2(t_coords c1, t_coords c2, t_coords d, t_mlx *mlx)
{
	int	e;

	if (d.x >= -d.y)
	{
		e = d.x;
		d.x *= 2;
		d.y *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (++c1.x == c2.x)
				break ;
			e += d.y;
			if (e < 0)
			{
				c1.y--;
				e += d.x;
			}
		}
	}
	else
	{
		e = d.y;
		d.y *= 2;
		d.x *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (--c1.y == c2.y)
				break ;
			e += d.x;
			if (e > 0)
			{
				c1.x++;
				e += d.y;
			}
		}
	}
}

void	draw_line_3(t_coords c1, t_coords c2, t_coords d, t_mlx *mlx)
{
	int	e;

	if (-d.x >= d.y)
	{
		e = d.x;
		d.x *= 2;
		d.y *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (--c1.x == c2.x)
				break ;
			e += d.y;
			if (e >= 0)
			{
				c1.y++;
				e += d.x;
			}
		}
	}
	else
	{
		e = d.y;
		d.y *= 2;
		d.x *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (++c1.y == c2.y)
				break ;
			e += d.x;
			if (e <= 0)
			{
				c1.x--;
				e += d.y;
			}
		}
	}
}

void	draw_line_4(t_coords c1, t_coords c2, t_coords d, t_mlx *mlx)
{
	int	e;

	if (d.x <= d.y)
	{
		e = d.x;
		d.x *= 2;
		d.y *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (--c1.x == c2.x)
				break ;
			e -= d.y;
			if (e >= 0)
			{
				c1.y--;
				e += d.x;
			}
		}
	}
	else
	{
		e = d.y;
		d.y *= 2;
		d.x *= 2;
		while (1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
			if (--c1.y == c2.y)
				break ;
			e -= d.x;
			if (e >= 0)
			{
				c1.x--;
				e += d.y;
			}
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_straight(int xy, t_coords c1, t_coords c2, t_mlx *mlx)
{
	if (xy)
	{
		if (c1.x > c2.x)
			ft_swap(&c1.x, &c2.x);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
		while (c1.x++ < c2.x)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
	}
	else
	{
		if (c1.y > c2.y)
			ft_swap(&c1.y, &c2.y);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
		while (c1.y++ < c2.y)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFFFFFFF);
	}
}

void	draw_line(t_coords c1, t_coords c2, t_mlx *mlx)
{
	t_coords	d;

	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c1.x, c1.y, 0xFFD950FF);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c2.x, c2.y, 0xFF4CA3FF);
	d.x = c2.x - c1.x;
	if (d.x)
	{
		if (d.x > 0)
		{
			d.y = c2.y - c1.y;
			if (d.y)
			{
				if (d.y > 0)
					draw_line_1(c1, c2, d, mlx);
				else
					draw_line_2(c1, c2, d, mlx);
			}
			else
				draw_straight(1, c1, c2, mlx);
		}
		else
		{
			d.y = c2.y - c1.y;
			if (d.y)
			{
				if (d.y > 0)
					draw_line_3(c1, c2, d, mlx);
				else
					draw_line_4(c1, c2, d, mlx);
			}
			else
				draw_straight(1, c1, c2, mlx);
		}
	}
	else
		draw_straight(0, c1, c2, mlx);
}
