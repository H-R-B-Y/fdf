/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:03:48 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:03:48 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

float	vec3_mag(t_vec3 *vec)
{
	if (!vec)
		return (0);
	return (
		sqrt((vec->x * vec->x)
			+ (vec->y * vec->y)
			+ (vec->z * vec->z))
	);
}

float	vec3_dot(t_vec3 *vec1, t_vec3 *vec2)
{
	if (!vec1 || !vec2)
		return (0);
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

t_vec3	vec3_norm(t_vec3 *vec)
{
	float	mag;

	if (!vec)
		return (t_vec3){0, 0, 0};
	mag = vec3_mag(vec);
	if (mag < 1e-6f)
		return (t_vec3){0, 0, 0};
	return (t_vec3){
		.x = (vec->x / mag),
		.y = (vec->y / mag),
		.z = (vec->z / mag)
	};
}

t_vec3	vec3_add(t_vec3 *vec1, t_vec3 *vec2)
{
	if (!vec1 || !vec2)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){
		.x = (vec1->x + vec2->x),
		.y = (vec1->y + vec2->y),
		.z = (vec1->z + vec2->z)
	});
}

t_vec3	vec3_smult(t_vec3 *vec, float scalar)
{
	if (!vec)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){
		.x = (vec->x * scalar),
		.y = (vec->y * scalar),
		.z = (vec->z * scalar)
	});
}
