/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:33:53 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/11 13:35:52 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	fract;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)))
		|| (ac == 2 && (!ft_strncmp(av[1], "burning_ship", 12)))
		|| (ac == 4 && (!ft_strncmp(av[1], "julia", 5))))
	{
		fract.name = av[1];
		if (ac == 4)
		{
			fract.julia_x = ft_atof(av[2]);
			fract.julia_y = ft_atof(av[3]);
		}
		fract_init(&fract);
		fract_render(&fract);
		setup_hooks(&fract);
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_printf("wrong input\n");
		exit(1);
	}
}
