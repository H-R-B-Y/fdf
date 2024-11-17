/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:57:59 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 16:57:59 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

float	vec2_mag(t_vec2 *vec)
{
	if (!vec)
		return (0);
	return (sqrt(vec->x * vec->x + vec->y * vec->y));
}

float	vec2_dot(t_vec2 *vec1, t_vec2 *vec2)
{
	if (!vec1 || !vec2)
		return (0);
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y));
}

t_vec2	vec2_norm(t_vec2 *vec)
{
	float	mag;

	if (!vec)
		return ((t_vec2){0, 0});
	mag = vec2_mag(vec);
	return ((t_vec2){.x = (vec->x / mag),
		.y = (vec->y / mag)});
}

t_vec2	vec2_add(t_vec2 *vec1, t_vec2 *vec2)
{
	if (!vec1 || !vec2)
		return ((t_vec2){0, 0});
	return ((t_vec2){.x = vec1->x + vec2->x,
		.y = vec1->y + vec2->y});
}

t_vec2	vec2_euler(t_vec2 *vec, float angle)
{
	t_vec2	rotated;
	float	radians;

	if (!vec)
		return ((t_vec2){0, 0});
	radians = angle * (MY_PI / 180.0);
	rotated.x = vec->x * cos(radians) - vec->y * sin(radians);
	rotated.y = vec->x * sin(radians) + vec->y * cos(radians);
	return (rotated);
}
