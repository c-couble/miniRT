/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:21:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 17:52:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SCREEN_WIDTH		1920 / 2 
# define SCREEN_HEIGHT		1080 / 2
# define WINDOW_NAME		"miniRT ccouble lespenel"
# define DEFAULT_RAY_SIZE	25
# define MINIMUM_FPS		20
# define MAXIMUM_FPS		80
# define ROLL_ANGLE			0.05
# define SENSITIVITY		2
# define SPEED				90
# define MAX_RAY_LEN		1000000
# define INACCURATE_ZERO	10e-8
# define BACKGROUND_COLOR	9211020
# define TILE_DIVIDER		150.

# define NEAR_PLANE			1
# define FAR_PLANE			5000

# define X					0
# define Y					1
# define Z					2

# define AIR_RATIO			1.0
# define DEPTH				8
# define LOW_RENDER_DEPTH   5

# define DIFFUSE_RATIO		0.65
# define SPECULAR_RATIO		1
# define SPECULAR_SHINE		64
# define REFLECT_RATIO		0

#endif
