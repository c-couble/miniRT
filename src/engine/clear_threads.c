/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:36:31 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 04:01:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"

void	clear_threads(t_engine *engine, size_t threads)
{
	size_t	i;

	engine->stop = 1;
	pthread_mutex_unlock(&engine->line_mutex);
	i = 0;
	while (i < threads)
	{
		pthread_join(engine->threads[i], NULL);
		++i;
	}
	pthread_mutex_destroy(&engine->line_mutex);
	free(engine->threads);
}
