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

#include "../include/hb_math_ext.h"

t_vec3	vec3_mtrx3(t_vec3 *vec, t_mtrx3 *mtrx)
{
	t_vec3 result;

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

	rot.x.x = cos(y) * cos(z);
	rot.x.y = cos(y) * sin(z);
	rot.x.z = -sin(y);
	rot.y.x = sin(x) * sin(y) * cos(z)
		- cos(x) * sin(z);
	rot.y.y = sin(x) * sin(y) * sin(z)
		+ cos(x) * cos(z);
	rot.y.z = sin(x) * cos(y);
	rot.z.x = cos(x) * sin(y) * cos(z)
		+ sin(x) * sin(z);
	rot.z.y = cos(x) * sin(y) * sin(z)
		- sin(x) * cos(z);
	rot.z.z = cos(x) * cos(y);
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
