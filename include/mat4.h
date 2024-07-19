/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:44:22 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/19 03:23:15 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

typedef struct s_mat4
{
	double	matrix[16];
}	t_mat4;

void	mat4_print(t_mat4 *mat);
void	mat4_multiply(t_mat4 *a, t_mat4 *b, t_mat4 *out);
t_mat4	*mat4_identity(t_mat4 *out);

t_mat4	*mat4_inverse(t_mat4 *mat, t_mat4 *out);
void	divide_line(t_mat4 *mat, int k, double value);
void	swap_lines(t_mat4 *mat, int r, int k);

#endif
