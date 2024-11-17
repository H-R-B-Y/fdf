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

__uint32_t	colour_rgba(__uint8_t red,
	__uint8_t green,
	__uint8_t blue,
	__uint8_t alpha)
{
	__uint32_t	out;

	out = 0;
	out += (red << 24);
	out += (green << 16);
	out += (blue << 8);
	out += (alpha);
	return (out);
}

__uint32_t	lerp_colour(__uint32_t from, __uint32_t too, float t)
{
	__uint8_t	r;
	__uint8_t	g;
	__uint8_t	b;
	__uint8_t	a;

	r = (__uint8_t)lerp((float)rgba_get_red(from),
			(float)rgba_get_red(too), t);
	g = (__uint8_t)lerp((float)rgba_get_green(from),
			(float)rgba_get_green(too), t);
	b = (__uint8_t)lerp((float)rgba_get_blue(from),
			(float)rgba_get_blue(too), t);
	a = (__uint8_t)lerp((float)rgba_get_alph(from),
			(float)rgba_get_alph(too), t);
	return (colour_rgba(r, g, b, a));
}

__uint32_t	parse_rgba_str(const char *rgba)
{
	__uint32_t	result;
	int			i;
	char		c;

	if (rgba == 0 || rgba[0] != '0' || rgba[1] != 'x')
		return (0);
	result = 0;
	i = 2;
	while (rgba[i] != '\0')
	{
		result <<= 4;
		c = rgba[i];
		if (c >= '0' && c <= '9')
			result |= (c - '0');
		else if (c >= 'A' && c <= 'F')
			result |= (c - 'A' + 10);
		else if (c >= 'a' && c <= 'f')
			result |= (c - 'a' + 10);
		else
			return (0);
		i++;
	}
	return (result);
}
