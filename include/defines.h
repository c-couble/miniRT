/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:21:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/14 01:28:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCREEN_WIDTH		1920
# define SCREEN_HEIGHT		1080
# define WINDOW_NAME		"miniRT ccouble lespenel"
# define DEFAULT_RAY_SIZE	25
# define MINIMUM_FPS		80
# define MAXIMUM_FPS		100
# define ROLL_ANGLE			0.05
# define SENSITIVITY		2
# define SPEED				50
# define MAX_RAY_LEN		10000
# define INACCURATE_ZERO	10e-8
# define SKY				7591935
# define GREEN				0xFF00
# define BACKGROUND_COLOR	0
# define TILE_DIVIDER		150.

# define NEAR_PLANE			1
# define FAR_PLANE			2000

# define X					0
# define Y					1
# define Z					2

# define AIR_RATIO			1.0
# define DEPTH				8

# define DIFFUSE_RATIO		0.65
# define SPECULAR_RATIO		1
# define SPECULAR_SHINE		64
# define REFLECT_RATIO		0

#endif
