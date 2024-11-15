/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 19:01:11 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 19:01:11 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_vec2	_do_2d(t_vec2 *v, t_list *op)
{
	t_vec2	vec = {0};
	t_tframe *operation;

	if (!op)
		return (*v);
	vec = *v;
	while (op)
	{
		operation = op->content;
		if (operation->type == TRVEC2)
			vec = operation->func.trvec2(&vec);
		else if (operation->type == TRVEC2X)
			vec = operation->func.trvec2x(&vec, operation->param);
		op = op->next;
	}
	return (vec);
}

t_vec3	_do_3d(t_vec3 *v, t_list *op)
{
	t_vec3	vec = {0};
	t_tframe *operation;

	if (!op)
		return (*v);
	vec = *v;
	while (op)
	{
		operation = op->content;
		if (operation->type == TRVEC3)
			vec = operation->func.trvec3(&vec);
		else if (operation->type == TRVEC3X)
			vec = operation->func.trvec3x(&vec, operation->param);
		op = op->next;
	}
	return (vec);
}

void	project(t_map *map, t_proj *projection)
{
	t_vec2	iter;
	t_vec3	temp3d;
	t_vec2	temp2d;

	iter = (t_vec2){0, 0};
	while (iter.y < map->size.y)
	{
		iter.x = 0;
		while (iter.x < map->size.x)
		{
			temp3d = _do_3d(&map->matrix[(int)iter.y][(int)iter.x]
				->origin, projection->translate_3D);
			temp2d = projection->convert(&temp3d, projection->param);
			map->matrix[(int)iter.y][(int)iter.x]->pre_translate = temp2d;
			map->matrix[(int)iter.y][(int)iter.x]
				->output = _do_2d(&temp2d, projection->translate_2D);
			iter.x++;
		}
		iter.y++;
	}
}

void	translate(t_map *map, t_proj *projection)
{
		t_vec2	iter;

	iter = (t_vec2){0, 0};
	while (iter.y < map->size.y)
	{
		iter.x = 0;
		while (iter.x < map->size.x)
		{
			map->matrix[(int)iter.y][(int)iter.x]
				->output = _do_2d(&(map->matrix[(int)iter.y][(int)iter.x]
						->pre_translate), projection->translate_2D);
			iter.x++;
		}
		iter.y++;
	}
}
