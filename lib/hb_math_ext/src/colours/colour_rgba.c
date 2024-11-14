/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 20:23:14 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 20:23:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hb_math_ext.h"

__uint32_t	colour_rgba(__uint8_t red, __uint8_t green, __uint8_t blue, __uint8_t alpha)
{
	__uint32_t out;

	out = 0;
	out += (red << 24);
	out += (green << 16);
	out += (blue << 8);
	out += (alpha);
	return (out);
}
