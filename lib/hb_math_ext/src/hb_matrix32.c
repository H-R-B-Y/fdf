/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hb_matrix32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 17:58:02 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 17:58:02 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hb_math_ext.h"

t_mtrx3	scaling_matrix_3d(float scale_x, float scale_y, float scale_z)
{
	return((t_mtrx3){
		{scale_x, 0, 0},
		{0, scale_y, 0},
		{0, 0, scale_z}
	});
}
