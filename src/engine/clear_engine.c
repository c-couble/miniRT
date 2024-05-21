/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:47:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/05/21 04:49:28 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "scene.h"

void	clear_engine(t_engine *engine)
{
	clear_scene(&engine->scene);
	clear_mlx_struct(&engine->mlx);
}