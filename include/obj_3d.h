/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:01:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/21 05:15:45 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_3D
# define OBJ_3D

# include "vector.h"

typedef struct s_obj_3d
{
	char		*file_name;
	t_vector	vertices;
}	t_obj_3d;

#endif
