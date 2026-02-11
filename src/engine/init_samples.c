/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_samples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:48:51 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/11 03:49:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "engine.h"

int	init_samples(t_engine *engine)
{
	engine->sampling = 0;
	engine->sample_nb = 1;
	engine->samples_size = (engine->mlx.height + 1) * (engine->mlx.width + 1)
		* sizeof(t_colorf);
	engine->samples = malloc(engine->samples_size);
	if (engine->samples == NULL)
		return (-1);
	return (0);
}
