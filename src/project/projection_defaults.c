/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_defaults.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 18:24:21 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 18:24:21 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

// t_vec3	vec3_rotate_matrix(t_vec3 *vec, void *param);
// t_vec2	vec2_rotate_matrix(t_vec2 *vec, void *param);
// t_vec3	vec3_default_translate(t_vec3 *vec, void *param);
// t_vec2	vec2_default_translate(t_vec2 *vec, void *param);
// t_vec3	vec3_change_scale(t_vec3 *vec, void *param);

t_vec3	vec3_change_scale(t_vec3 *vec, void *param)
{
	float	scale;
	t_vec3	val;
	
	scale = *((float *)param);
	val = vec3_smult(vec, scale);
	return (val);
}

t_vec3	vec3_rotate_matrix(t_vec3 *vec, void *param)
{
	t_mtrx3	*rot;
	t_vec3	val;

	rot = param;
	val = vec3_mtrx3(vec, rot);
	return (val);
}

t_vec2	vec2_rotate_matrix(t_vec2 *vec, void *param)
{
	t_mtrx2	*rot;

	rot = param;
	return (vec2_mtrx2(vec, rot));
}

t_vec3	vec3_default_translate(t_vec3 *vec, void *param)
{
	t_vec3	*vec2;

	vec2 = param;
	return (vec3_add(vec, vec2));
}

t_vec2	vec2_default_translate(t_vec2 *vec, void *param)
{
	t_vec2	*vec2;

	vec2 = param;
	return (vec2_add(vec, vec2));
}
