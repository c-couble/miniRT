/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:19:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/22 03:07:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef union u_color
{
	struct s_rgb
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	}	rgb;
	uint32_t	color;
}	t_color;

int	parse_color(t_color *color);

#endif
