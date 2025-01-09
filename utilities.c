/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:07:15 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/09 13:09:29 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
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
	(void)x;
	(void)y;
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom /= 1.1;
	fract_render(vars);
	return (0);
}

void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_program, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
}
