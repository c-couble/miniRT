/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:17:01 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/13 17:28:35 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

t_vec2	*vec2_create(double x, double y, t_vec2 *out);

#endif
