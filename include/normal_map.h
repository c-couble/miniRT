/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 04:42:17 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 09:20:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_MAP_H
# define NORMAL_MAP_H

# include "engine.h"
# include "object/optional_data.h"
# include "ray.h"
# include "texture.h"

typedef struct s_normal_map
{
	t_texture	*file;
}	t_normal_map;

void	apply_normal_map(t_ray *ray);
int		parse_normal_map(t_engine *engine, t_option *data, char *arg);

#endif
