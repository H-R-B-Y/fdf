/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 18:12:39 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 18:12:39 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_vec3	vec3_rotate_matrix(t_vec3 *vec, void *param);

t_vec2	iso_project(t_vec3 *vec, void *param)
{

	t_vec3	middle;
	t_mtrx3	rot;

	(void)param;
	rot = mtrx3_identity();
	rot.z.z = 0.0f;
	middle = vec3_mtrx3(vec, &rot);
	return ((t_vec2){middle.x, middle.y});
}

// First steps of isometric projection are:
// Rotate y axis by α (ascsin(tan(30 degrees)))
// Rotate x axis by  β (45 Degrees)
// Then convert to vec2
t_proj	*create_isometric(void)
{
	t_proj	*output;
	t_mtrx3	*mtrx;

	output = zeroit(malloc(sizeof(t_proj)), sizeof(t_proj));
	mtrx = malloc(sizeof(t_mtrx3));
	*mtrx = euler_to_mtrx3(45, 35.264, 0);
	append_frame(output, create_tframe(TRVEC3X, vec3_rotate_matrix, mtrx, 1));
	// append_frame(output, create_tframe(TRVEC3, spherical_projection, 0, 0));
	// mtrx = malloc(sizeof(t_mtrx3));
	// *mtrx = euler_to_mtrx3(45, 0, 0);
	// append_frame(output, create_tframe(TRVEC3X, vec3_rotate_matrix, mtrx, 1));
	prepend_frame(output, create_tframe(TRVEC3, vec3_norm, 0, 0));
	output->convert = iso_project;
	return (output);
}
