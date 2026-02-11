/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:19:59 by ccouble           #+#    #+#             */
/*   Updated: 2026/02/05 20:15:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

# define SKY	7591935
# define RED	0xFFFF0000
# define GREEN	0xFF00FF00
# define BLUE	0xFF0000FF
# define WHITE	0xFFFFFFFF
# define YELLOW	0xFFFFFF00
# define ORANGE	0xFFFFA500
# define CYAN	0xFF00FFFF
# define PURPLE	0xFF800080

struct	s_ray;

typedef union u_color
{
	struct s_rgb
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	}	rgb;
	uint32_t	color;
}	t_color;

typedef struct s_colorf
{
	float	r;
	float	g;
	float	b;
}	t_colorf;

void		color_zero(t_colorf *color);
t_colorf	color_normalize(t_color in);
uint32_t	color_denormalize(t_colorf in);
t_colorf	color_scale(t_colorf to_scale, double ratio);
t_colorf	color_add(t_colorf a, t_colorf b);
t_colorf	color_multiply(t_colorf a, t_colorf b);
t_colorf	color_add_scale(t_colorf a, t_colorf b, double ratio);

int			parse_color(t_colorf *color);

t_colorf	get_normal_color(struct s_ray *camera_ray);
t_colorf	get_uv_color(struct s_ray *camera_ray);
uint32_t	interpolate_color(uint32_t a, uint32_t b, int curr, int max);
uint32_t	get_depth_color(int value, int max_value);

#endif
