/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_vec22.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:02:38 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:02:38 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

t_vec2	vec2_smult(t_vec2 *vec, float scalar)
{
	return ((t_vec2){.x = vec->x * scalar, .y = vec->y * scalar});
}

t_vec2	vec2_mult(t_vec2 *vec1, t_vec2 *vec2)
{
	t_vec2	result;

	if (!vec1 || !vec2)
		return ((t_vec2){0, 0});
	result.x = vec1->x * vec2->x;
	result.y = vec1->y * vec2->y;
	return (result);
}

float	vec2_distance(t_vec2 *vec1, t_vec2 *vec2)
{
	t_vec2	difference;

	difference = vec2_smult(vec2, -1.0f);
	difference = vec2_add(vec1, &difference);
	return (vec2_mag(&difference));
}
