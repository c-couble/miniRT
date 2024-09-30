/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint8t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:03:20 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 08:15:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_string.h"

int	parse_uint8t(uint8_t *data, char *nptr)
{
	int		n;

	if (nptr == NULL)
		return (-1);
	if (ft_atoi_ptr(&n, nptr) == -1)
		return (-1);
	if (n < 0 || n > 255)
		return (-1);
	*data = n;
	return (0);
}
