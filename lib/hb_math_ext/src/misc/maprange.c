/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maprange.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 20:11:21 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 20:11:21 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

float	maprange(t_vec2 *from, t_vec2 *too, float t)
{
	float	tn;

	tn = (t - from->x) / (from->y - from->x);
	return (too->x + tn * (too->y - too->x));
}
