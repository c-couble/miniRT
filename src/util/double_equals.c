/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 05:34:20 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/26 05:34:57 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int	double_equals(double a, double b)
{
	return (a - INACCURATE_ZERO <= b && b <= a + INACCURATE_ZERO);
}
