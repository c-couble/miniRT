/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 03:47:05 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/25 04:53:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

typedef enum e_key
{
	MOUSE_LEFT = 1,
	MOUSE_MIDDLE = 2,
	MOUSE_RIGHT = 3,
	MOUSE_WHEELUP = 4,
	MOUSE_WHEELDOWN = 5,
	KEY_SPACE = 32,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_ENTER = 65293,
	KEY_CONTROL = 65507,
	KEY_ESCAPE = 65307,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_NUM1 = 65436,
	KEY_NUM2 = 65433,
	KEY_NUM3 = 65435,
	KEY_NUM4 = 65430,
	KEY_NUM5 = 65437,
	KEY_NUM6 = 65432,
	KEY_NUM7 = 65429,
	KEY_NUM8 = 65431,
	KEY_NUM9 = 65434,
	KEY_MINUS = 65453,
	KEY_PLUS = 65451,
}	t_key;

#endif
