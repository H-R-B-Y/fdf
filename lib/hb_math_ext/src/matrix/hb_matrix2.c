/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_matrix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:16:25 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:16:25 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

t_vec2	vec2_mtrx2(t_vec2 *vec, t_mtrx2 *mtrx)
{
	t_vec2	result;

	if (!vec || !mtrx)
		return ((t_vec2){0, 0});
	result.x = mtrx->x.x * vec->x + mtrx->x.y * vec->y;
	result.y = mtrx->y.x * vec->x + mtrx->y.y * vec->y;
	return (result);
}

t_mtrx2	mtrx2_mult(t_mtrx2 *m1, t_mtrx2 *m2)
{
	t_mtrx2	result;

	if (!m1 || !m2)
		return (mtrx2_identity());
	result.x.x = m1->x.x * m2->x.x + m1->x.y * m2->y.x;
	result.x.y = m1->x.x * m2->x.y + m1->x.y * m2->y.y;
	result.y.x = m1->y.x * m2->x.x + m1->y.y * m2->y.x;
	result.y.y = m1->y.x * m2->x.y + m1->y.y * m2->y.y;
	return (result);
}

t_mtrx2	euler_to_mtrx2(float euler)
{
	t_mtrx2	rot;
	float	cos_theta;
	float	sin_theta;

	cos_theta = cos(euler * MY_PI / 180);
	sin_theta = sin(euler * MY_PI / 180);
	rot.x.x = cos_theta;
	rot.x.y = -sin_theta;
	rot.y.x = sin_theta;
	rot.y.y = cos_theta;
	return (rot);
}

t_mtrx2	mtrx2_identity(void)
{
	return ((t_mtrx2){
		.x = (t_vec2){1, 0},
		.y = (t_vec2){0, 1}
	});
}

t_mtrx2	mtrx2_transpose(t_mtrx2 *mtrx)
{
	if (!mtrx)
		return (mtrx2_identity());
	return ((t_mtrx2){
		.x = (t_vec2){mtrx->x.x, mtrx->y.x},
		.y = (t_vec2){mtrx->x.y, mtrx->y.y}
	});
}
