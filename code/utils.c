/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:42:17 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/17 13:26:51 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	allocation_error(void)
{
	perror("Memory allocation error\n");
	exit(1);
}

double	scale_and_map(double x_y, double hei_wid, double comx1, double comx2)
{
	double	scaled;

	scaled = (x_y) / (hei_wid) * (comx2 - comx1) + comx1;
	return (scaled);
}

void	fract_init(t_vars *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		allocation_error();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (fract->win == NULL)
	{
		close_program(fract);
		allocation_error();
	}
	fract->img.img_p = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (fract->img.img_p == NULL)
	{
		close_program(fract);
		allocation_error();
	}
	fract->img.pix = mlx_get_data_addr(fract->img.img_p, &fract->img.bits,
			&fract->img.l_len, &fract->img.endian);
	fract->zoom = 1;
	fract->iteration = 66;
	fract->escape_v = 4;
	fract->offset_x = 0;
	fract->offset_y = 0;
}
