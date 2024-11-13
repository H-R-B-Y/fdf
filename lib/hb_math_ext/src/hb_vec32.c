/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_vec32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:36:19 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:36:19 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hb_math_ext.h"

t_vec3	vec3_mult(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	result;

	if (!vec1 || !vec2)
		return ((t_vec3){0, 0, 0});
	result.x = vec1->x * vec2->x;
	result.y = vec1->y * vec2->y;
	result.z = vec1->z * vec2->z;
	return (result);
}
