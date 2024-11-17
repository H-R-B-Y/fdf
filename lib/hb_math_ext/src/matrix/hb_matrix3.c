/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_matrix3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:26:23 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:26:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

t_vec3	vec3_mtrx3(t_vec3 *vec, t_mtrx3 *mtrx)
{
	t_vec3	result;

	if (!vec || !mtrx)
		return ((t_vec3){0, 0, 0});
	result.x = mtrx->x.x * vec->x + mtrx->x.y * vec->y + mtrx->x.z * vec->z;
	result.y = mtrx->y.x * vec->x + mtrx->y.y * vec->y + mtrx->y.z * vec->z;
	result.z = mtrx->z.x * vec->x + mtrx->z.y * vec->y + mtrx->z.z * vec->z;
	return (result);
}

t_mtrx3	mtrx_mult(t_mtrx3 *m1, t_mtrx3 *m2)
{
	t_mtrx3	result;

	if (!m1 || !m2)
		return (mtrx3_identity());
	result.x = vec3_mult(&m1->x, &m2->x);
	result.y = vec3_mult(&m1->y, &m2->y);
	result.z = vec3_mult(&m1->z, &m2->z);
	return (result);
}

t_mtrx3	euler_to_mtrx3(float x, float y, float z)
{
	t_mtrx3	rot;
	t_vec3	angles;

	angles.x = x * MY_PI / 180.0;
	angles.y = y * MY_PI / 180.0;
	angles.z = z * MY_PI / 180.0;
	rot.x.x = cos(angles.y) * cos(angles.z);
	rot.x.y = cos(angles.y) * sin(angles.z);
	rot.x.z = -sin(angles.y);
	rot.y.x = sin(angles.x) * sin(angles.y)
		* cos(angles.z) - cos(angles.x) * sin(angles.z);
	rot.y.y = sin(angles.x) * sin(angles.y)
		* sin(angles.z) + cos(angles.x) * cos(angles.z);
	rot.y.z = sin(angles.x) * cos(angles.y);
	rot.z.x = cos(angles.x) * sin(angles.y)
		* cos(angles.z) + sin(angles.x) * sin(angles.z);
	rot.z.y = cos(angles.x) * sin(angles.y)
		* sin(angles.z) - sin(angles.x) * cos(angles.z);
	rot.z.z = cos(angles.x) * cos(angles.y);
	return (rot);
}

t_mtrx3	mtrx3_identity(void)
{
	return ((t_mtrx3){
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	});
}

t_mtrx3	mtrx3_transpose(t_mtrx3 *mtrx)
{
	if (!mtrx)
		return (mtrx3_identity());
	return ((t_mtrx3){
		{mtrx->x.x, mtrx->y.x, mtrx->z.x},
		{mtrx->x.y, mtrx->y.y, mtrx->z.y},
		{mtrx->x.z, mtrx->y.z, mtrx->z.z}
	});
}
