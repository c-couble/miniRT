/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:19:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:19:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

# include <stdint.h>

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

int	parse_rgb(t_rgb *rgb);

#endif
