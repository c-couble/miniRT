/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_caustic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:49:55 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 22:06:40 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "engine.h"
#include "ft_string.h"
#include "object/optional_data.h"
#include "object/parse_util.h"

int	parse_caustic(t_engine *engine, t_option *data, char *arg)
{
	char	*save;
	char	*raw_data;

	(void) engine;
	raw_data = ft_strtok_r(arg, ",", &save);
	if (parse_int(&data->photon_nb, raw_data, 0, 10000000) == -1)
		return (-1);
	return (0);
}
