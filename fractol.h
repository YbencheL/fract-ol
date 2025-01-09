/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:39:37 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/07 16:29:49 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// resolution
# define WIDTH 800
# define HEIGHT 800
// colors
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY    0x808080
# define ORANGE  0xFFA500
# define PINK    0xFFC0CB
# define PURPLE  0x800080
# define BROWN   0xA52A2A

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>

typedef struct s_img
{
	void	*img_p;
	char	*pix;
	int		bits;
	int		endian;
	int		l_len;
}	t_img;

typedef struct s_comx
{
	double	x;
	double	y;
}	t_comx;

typedef struct s_vars
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_v;
	int		iteration;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	offset_x;
	double	offset_y;
}	t_vars;
// src functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
double	ft_atof(const char *str);
// initializing mlx and rendering the output
void	fract_init(t_vars *fract);
void	fract_render(t_vars *fract);
// calculation of the mandelbrot and julia formulas
t_comx	square_comx(t_comx z);
t_comx	sum_comx(t_comx z1, t_comx z2);
// mapping the position of pixels
double	map(double unscaled_num, double old_max,
			double new_min, double new_max);
// allocation errors
void	mall_err(void);
// data about zoom, iterations and shifting
void	data_init(t_vars *fract);
int		close_program(t_vars *vars);
// keys
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	setup_hooks(t_vars *vars);
// ft_printf
int		ft_printf(const char *format, ...);
int		ft_intlen(int n);
int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_puthexo(unsigned long n, int upper);
int		ft_putstr(char *s);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_intlen_base(unsigned int n, int base);
int		ft_putptr(unsigned long addr);
int		ft_handle_percent(const char *format, va_list args);

#endif