/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:02:29 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/09 13:18:40 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_vars *fract)
{
	fract->zoom = 1;
	fract->iteration = 100;
	fract->escape_v = 4;
	fract->offset_x = 0;
	fract->offset_y = 0;
}

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->l_len) + (x * (img->bits / 8));
	*(unsigned int *)(img->pix + offset) = color;
}

static void	init_julia(t_vars *fract, t_comx *c, t_comx z)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z.x;
		c->y = z.y;
	}
}

static void	handle_pixel(int x, int y, t_vars *fract)
{
	t_comx	z;
	t_comx	c;
	int		i;
	int		color;

	i = 0;
	z.x = map(x, WIDTH, -2.0, 1.0) * fract->zoom + fract->offset_x;
	z.y = map(y, HEIGHT, -1.5, 1.5) * fract->zoom + fract->offset_y;
	init_julia(fract, &c, z);
	while (i < fract->iteration)
	{
		z = sum_comx(square_comx(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fract->escape_v)
		{
			color = map(i, fract->iteration, BLACK, WHITE);
			pixel_put(x, y, &fract->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fract->img, BLACK);
}

void	fract_render(t_vars *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img_p, 0, 0);
}
