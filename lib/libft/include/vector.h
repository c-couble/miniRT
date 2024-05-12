/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:13:30 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/12 17:03:39 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

# define BASE_ALLOC 16

typedef struct s_vector
{
	size_t	elemsize;
	size_t	size;
	size_t	allocated;
	void	*array;

}	t_vector;

int		add_vector(t_vector *this, const void *data, size_t count);
int		add_vector_at(t_vector *this, const void *new, size_t at);
void	*at_vector(t_vector *this, size_t i);
int		set_value_vector(t_vector *this, const void *data, size_t i);
int		reallocate_vector(t_vector *this);
void	clear_vector(t_vector *this);
void	remove_vector(t_vector *this, size_t i);
void	init_vector(t_vector *this, size_t elemsize);
void	set_alloc_size(t_vector *this, size_t count);
int		merge_vector(t_vector *to, t_vector *from, size_t i);

#endif
