/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/12 20:06:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef enum e_object_type
{
	CYLINDER,
	LIGHT,
	PLANE,
	SPHERE
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
}	t_object;

#endif
