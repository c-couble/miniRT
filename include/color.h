/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:19:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 16:23:04 by ccouble          ###   ########.fr       */
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
# define NO_TEXTURE 7434869

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

int			parse_color(t_color *color);
uint32_t	add_color(t_color *c1, t_color *c2);
uint32_t	multiply_color(t_color *c1, t_color *c2);
uint32_t	add_scale_color(t_color *c1, t_color *c2, double ratio);
uint32_t	scale_color(t_color *c1, double ratio);
uint32_t	get_normal_color(struct s_ray *camera_ray);
uint32_t	get_uv_color(struct s_ray *camera_ray);
uint32_t	interpolate_color(uint32_t a, uint32_t b, int curr, int max);
uint32_t	get_depth_color(int value, int max_value);

#endif
