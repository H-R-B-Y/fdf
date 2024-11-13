/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_matrix22.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:24:56 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:24:56 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hb_math_ext.h"

t_mtrx2	scaling_matrix_2d(float scale_x, float scale_y)
{
	return ((t_mtrx2){
		.x = {scale_x, 0},
		.y = {0, scale_y}
	});
}
