/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preojection_defaults2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 16:01:17 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-15 16:01:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"


t_vec3 vec3_hadamard(t_vec3 *vec, void *param)
{
	t_vec3	out;

	out = vec3_mult(vec, param);
	return (out);
}
