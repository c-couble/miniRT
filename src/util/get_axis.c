/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:13:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 21:36:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "vec3.h"                                                               
                                                                                
double  get_axis(t_vec3 *v, int axis)                                           
{                                                                               
    if (axis == X)                                                              
        return (v->x);                                                          
    if (axis == Y)
        return (v->y);
    return (v->z);
}
