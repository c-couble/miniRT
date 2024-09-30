/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:21:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 13:38:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCREEN_WIDTH		1920 * 2
# define SCREEN_HEIGHT		1080 * 2

# define DEPTH				12
# define LOW_RENDER_DEPTH   5
# define DEFAULT_RAY_SIZE	25
# define MINIMUM_FPS		20
# define MAXIMUM_FPS		20
# define THREADS			16
# define ROLL_ANGLE			0.05
# define SENSITIVITY		2
# define CAMERA_SPEED		80
# define DEFAULT_BACKGROUND	0
# define TILE_DIVIDER		150.

//Caustic parameters
# define ESTIMATION_SCALE	100
# define FORCE_P_RAY		1
# define DEFAULT_NN			5
# define KNN_MAX			50
# define CA_BBOX_SCALING	0.025
# define DEFAULT_BANDWIDTH  0.60

//Defaults material values
# define AIR_RATIO			1.0
# define DIFFUSE_RATIO		0.65
# define SPECULAR_RATIO		1
# define SPECULAR_SHINE		64
# define REFLECT_RATIO		0

# define WINDOW_NAME		"miniRT ccouble lespenel"
# define X					0
# define Y					1
# define Z					2
# define NEAR_PLANE			1
# define FAR_PLANE			1000000
# define MAX_RAY_LEN		1000000
# define INACCURATE_ZERO	10e-8

#endif
