/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:07:15 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/17 14:05:36 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_vars *vars)
{
	if (vars->img.img_p)
		mlx_destroy_image(vars->mlx, vars->img.img_p);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_program(vars);
	else if (keycode == 65361)
		vars->offset_x -= 0.05 / vars->zoom;
	else if (keycode == 65362)
		vars->offset_y -= 0.05 / vars->zoom;
	else if (keycode == 65363)
		vars->offset_x += 0.05 / vars->zoom;
	else if (keycode == 65364)
		vars->offset_y += 0.05 / vars->zoom;
	fract_render(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	mouse_x = (double)x / WIDTH * (1.0 - (-2.0)) + (-2.0);
	mouse_y = (double)y / HEIGHT * (1.5 - (-1.5)) + (-1.5);
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 1 / 1.1;
	else
		zoom_factor = 1.0;
	if (zoom_factor != 1.0)
	{
		vars->offset_x = (vars->offset_x - mouse_x) * zoom_factor + mouse_x;
		vars->offset_y = (vars->offset_y - mouse_y) * zoom_factor + mouse_y;
		vars->zoom *= zoom_factor;
		fract_render(vars);
	}
	return (0);
}

void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_program, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}
