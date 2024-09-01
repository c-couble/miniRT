/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mtl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:28:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 01:41:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_MTL_H
# define OBJ_MTL_H

# include "vector.h"

typedef struct s_obj_mtl
{
	char		*file_name;
	t_vector	materials;
}	t_obj_mtl;

#endif
