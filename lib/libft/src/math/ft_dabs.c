/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:52:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/19 11:35:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dabs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}
