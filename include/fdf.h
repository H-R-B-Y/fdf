/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:02:38 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 16:02:38 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42.h"
# include "hb_math_ext.h"
# include <math.h>


// ██████   █████  ████████  █████ 
// ██   ██ ██   ██    ██    ██   ██
// ██   ██ ███████    ██    ███████
// ██   ██ ██   ██    ██    ██   ██
// ██████  ██   ██    ██    ██   ██

typedef struct s_point	t_point;

struct s_point
{
	t_vec3		origin;
	t_vec2		output;
	uint32_t	colour;
};

typedef struct s_line	t_line;

struct s_line
{
	t_point	*start;
	t_vec2	*startv;
	t_point	*end;
	t_vec2	*endv;
};

typedef struct s_map	t_map;

struct s_map
{
	t_list	*proto;
	t_vec2	size;
	t_point	***matrix;
	t_line	**lines;
};

typedef struct s_fdf	t_fdf;

struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*main_img;
	mlx_image_t		*pre_img; // Maybe useful to re-draw to a new image, then display when ready instead of deleting then redrawing.
	t_map			*map;
	struct s_proj	*projection;
	int				*needs_redraw;
};

// ██████   █████  ██████  ███████ ███████
// ██   ██ ██   ██ ██   ██ ██      ██     
// ██████  ███████ ██████  ███████ █████  
// ██      ██   ██ ██   ██      ██ ██     
// ██      ██   ██ ██   ██ ███████ ███████

void	destroy_map(t_map *map);

int		parse_map(char *path, t_map **output); // ?????????

// ██████  ██████   █████  ██     ██
// ██   ██ ██   ██ ██   ██ ██     ██
// ██   ██ ██████  ███████ ██  █  ██
// ██   ██ ██   ██ ██   ██ ██ ███ ██
// ██████  ██   ██ ██   ██  ███ ███ 

/*
After parsing the map into a point matrix, an array of lines can be created.
To draw, the projection pipeline can be used (linked list of operations) to rotate the
	point data and then converted into 2D points.
The lines can then be iterated through to draw them on the screen using their 2d vectors.
*/

typedef struct s_translation_frame	t_tframe;

enum e_fntype
{
	TRVEC3,
	TRVEC2,
	TRVEC3X,
	TRVEC2X
};

struct s_translation_frame
{
	enum e_fntype	type;
	union u_function
	{
		t_vec3	(*trvec3)(t_vec3 *);
		t_vec2	(*trvec2)(t_vec2 *);
		t_vec3	(*trvec3x)(t_vec3 *, void *);
		t_vec2	(*trvec2x)(t_vec2 *, void *);
	}			func;
	void		*param;
	int			param_freeable;
};

typedef struct s_proj	t_proj;

struct s_proj
{
	t_list	*translate_3D; // loop through these and apply to each vec3.
	t_vec2	(*convert)(t_vec3 *, void *); // convert to 2D
	t_list	*translate_2D; // loop through these and apply to each vec2.
	void	*param;
};

t_tframe	*create_tframe(enum e_fntype type,
				void *func, void *param, int freeable);
void	destroy_projection(t_proj *proj);
void	destroy_frame(t_tframe *frame);
int		append_frame(t_proj *proj, t_tframe *frame);

// For isometric
t_proj	*create_isometric(void);

// Should call a recursive subfunction to apply the stages to the point
// Finally attributes the result to the point.
void	project(t_map *map, t_proj *projection);

// Iterate through list of lines and draw them.
void	draw(t_line **lines, mlx_image_t *canvas);

#endif