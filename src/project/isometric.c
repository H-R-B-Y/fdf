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
t_vec2	vec2_rotate_matrix(t_vec2 *vec, void *param);
t_vec3	vec3_default_translate(t_vec3 *vec, void *param);
t_vec2	vec2_default_translate(t_vec2 *vec, void *param);

t_vec2	iso_project(t_vec3 *vec, void *param)
{
	t_vec2	output;
	t_vec3	middle;
	t_mtrx3	rot;

	(void)param;
	rot = mtrx3_identity();
	rot.z.z = 0.0f;
	middle = vec3_mtrx3(vec, &rot);
	ft_bzero(&output, sizeof(t_vec2));
	output.x = middle.x;
	output.y = middle.y;
	return (output);
}

t_proj	*create_isometric(void)
{
	t_proj *output;
	t_mtrx3 *mtrx;

	output = zeroit(malloc(sizeof(t_proj)), sizeof(t_proj));
	// First steps of isometric projection are:
	// Rotate y axis by  β (45 Degrees)
	mtrx = malloc(sizeof(t_mtrx3));
	*mtrx = euler_to_mtrx3(0, 45, 0);
	append_frame(output, create_tframe(TRVEC3X, vec3_rotate_matrix, mtrx, 1));
	// Rotate x axis by α (ascsin(tan(30 degrees)))
	mtrx = malloc(sizeof(t_mtrx3));
	*mtrx = euler_to_mtrx3(asin(cos(30 * MY_PI / 180)), 0, 0);
	append_frame(output, create_tframe(TRVEC3X, vec3_rotate_matrix, mtrx, 1));
	// Then convert to vec2
	output->convert = iso_project;
	return (output);
}
