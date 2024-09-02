/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mtl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 01:28:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 05:57:28 by ccouble          ###   ########.fr       */
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

typedef enum e_mtl_line_type
{
	NEWMTL,
	KA,
	KD,
	KS,
	TF,
	ILLUM,
	DISSOLVE,
	NS,
	NI,
	MAP_KD
}	t_mtl_line_type;

struct	s_engine;
struct	s_option;
int			parse_mtl_file(struct s_engine *engine, t_obj_mtl *mtl, char *file);
t_obj_mtl	*parse_obj_mtl_if_needed(struct s_engine *engine, char *file);

#endif
