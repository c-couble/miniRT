/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:21:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/25 04:31:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCREEN_WIDTH		1000
# define SCREEN_HEIGHT		1000
# define WINDOW_NAME		"miniRT ccouble lespenel"
# define DEFAULT_RAY_SIZE	5
# define MINIMUM_FPS		20
# define MAXIMUM_FPS		20
# define ROLL_ANGLE			0.05
# define SENSITIVITY		2
# define SPEED				80
# define MAX_RAY_LEN		1000000
# define INACCURATE_ZERO	10e-8
# define BACKGROUND_COLOR	0
# define TILE_DIVIDER		150.

# define NEAR_PLANE			1
# define FAR_PLANE			1000000

# define X					0
# define Y					1
# define Z					2

# define PHOTON_PER_OBJ		100000
# define PHOTON_RADIUS		05
# define AIR_RATIO			1.0
# define DEPTH				8
# define LOW_RENDER_DEPTH   5

# define DIFFUSE_RATIO		0.65
# define SPECULAR_RATIO		1
# define SPECULAR_SHINE		64
# define REFLECT_RATIO		0

#endif
