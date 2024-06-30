/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:44:22 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/30 02:11:01 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

typedef struct s_mat4
{
	double	matrix[16];
}	t_mat4;

void	mat4_print(t_mat4 *mat);
t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out);

#endif
