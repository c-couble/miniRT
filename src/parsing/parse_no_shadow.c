/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_no_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:02:14 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/15 10:07:31 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	parse_no_shadow(t_engine *engine, t_option *data, char *arg)
{
	(void) engine;
	data->has_shadow = arg[0] != '1';
	return (0);
}
