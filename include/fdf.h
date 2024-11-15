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

/**
 * @brief A point description.
 * @param origin The original 3D point.
 * @param pre_translate The 2D point before translation.
 * @param output The final 2D point.
 * @param colour The colour of the point.
 */
typedef struct s_point	t_point;

struct s_point
{
	t_vec3		origin;
	t_vec2		pre_translate;
	t_vec2		output;
	uint32_t	colour;
};

/**
 * @brief A line description.
 * @param start The start point.
 * @param startv The start point in 2D.
 * @param end The end point.
 * @param endv The end point in 2D.
 */
typedef struct s_line	t_line;

struct s_line
{
	t_point	*start;
	t_vec2	*startv;
	t_point	*end;
	t_vec2	*endv;
};

/**
 * @brief A map description.
 * @param proto The original map data.
 * @param size The size of the map.
 * @param matrix The 3D point matrix.
 * @param lines The array of lines.
 * @param ln_count The number of lines.
 */
typedef struct s_map	t_map;

struct s_map
{
	t_list	*proto;
	t_vec2	size;
	t_point	***matrix;
	t_line	**lines;
	size_t	ln_count;
};

/**
 * @brief The main fdf structure.
 * @param mlx the mlx instance.
 * @param main_img The main image.
 * @param pre_img The pre image.
 * @param map The map data.
 * @param projection The projection pipeline.
 * @param index The current line index.
 * @param needs_translate If the map needs translation.
 * @param needs_project If the map needs projection.
 * @param needs_draw If the map needs drawing.
 * @param default_colour The default colour.
 * @param thickness The line thickness.
 * @param drawsteps The number of steps to draw per frame.
 */
typedef struct s_fdf	t_fdf;

struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*main_img;
	mlx_image_t		*pre_img; // Maybe useful to re-draw to a new image, then display when ready instead of deleting then redrawing.
	t_map			*map;
	struct s_proj	*projection;
	size_t			index;
	int				needs_translate;
	int				needs_project;
	int				needs_draw;
	uint32_t		default_colour;
	float			thickness;
	int				drawsteps;
};

// ██████   █████  ██████  ███████ ███████
// ██   ██ ██   ██ ██   ██ ██      ██     
// ██████  ███████ ██████  ███████ █████  
// ██      ██   ██ ██   ██      ██ ██     
// ██      ██   ██ ██   ██ ███████ ███████

/**
 * @brief Destory map data.
 * @param map The map data.
 */
void	destroy_map(t_map **map);

/**
 * @brief Parse map data int output.
 * @brief path The path to the map file.
 * @brief output The output map data.
 * @return 0 on success, an integer to describe the error.
 */
int		parse_map(char *path, t_map **output);

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

/**
 * @brief A trnaslation frame.
 * @param type The type of translation.
 * @param func The translation function.
 * @param param The parameter for the translation.
 * @param param_freeable If the parameter should be freed.
 */
typedef struct s_translation_frame	t_tframe;

/**
 * @brief Translation types
 * @param TRVEC3 Translate a 3D vector.
 * @param TRVEC2 Translate a 2D vector.
 * @param TRVEC3X Translate a 3D vector with a parameter.
 * @param TRVEC2X Translate a 2D vector with a parameter.
 */
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

/**
 * @brief A projection pipeline.
 * @param translate_3D The 3D translation frames.
 * @param convert The 3D to 2D conversion function.
 * @param translate_2D The 2D translation frames.
 * @param param The parameter for the conversion function.
 */
typedef struct s_proj	t_proj;

struct s_proj
{
	t_list	*translate_3D; // loop through these and apply to each vec3.
	t_vec2	(*convert)(t_vec3 *, void *); // convert to 2D
	t_list	*translate_2D; // loop through these and apply to each vec2.
	void	*param;
	int		param_freeable;
};

/**
 * @brief Create a translation frame.
 * @param type The type of translation.
 * @param func The translation function.
 * @param param The parameter for the translation.
 * @param freeable If the parameter should be freed.
 * @return The translation frame.
 */
t_tframe	*create_tframe(enum e_fntype type,
				void *func, void *param, int freeable);

/**
 * @brief Destroy a projection pipeline.
 * @param proj The projection pipeline.
 */
void	destroy_projection(t_proj **proj);

/**
 * @brief Append a translation frame to the pipeline.
 * @param proj The projection pipeline.
 * @param frame The translation frame.
 * 
 * This function will look at the translation type
 * 	and append it to the correct list.
 */
int		append_frame(t_proj *proj, t_tframe *frame);

/**
 * @brief Prepend a translation frame to the pipeline.
 * @param proj The projection pipeline.
 * @param frame The translation frame.
 * 
 * This function will look at the translation type
 * 	and append it to the correct list.
 */
int		prepend_frame(t_proj *proj, t_tframe *frame);

/*
These are used as default translation frames for the projection pipeline.
They act as prototypes for the actual translation frames.
*/
t_vec3	vec3_rotate_matrix(t_vec3 *vec, void *param);
t_vec2	vec2_rotate_matrix(t_vec2 *vec, void *param);
t_vec3	vec3_default_translate(t_vec3 *vec, void *param);
t_vec2	vec2_default_translate(t_vec2 *vec, void *param);
t_vec3	vec3_change_scale(t_vec3 *vec, void *param);
t_vec3 vec3_hadamard(t_vec3 *vec, void *param);



/**
 * @brief Create the default isometric projection pipeline.
 */
t_proj	*create_isometric(void);

/**
 * @brief Runs the projection pipeline on the map data.
 * @param map The map data.
 * @param projection The projection pipeline.
 */
void	project(t_map *map, t_proj *projection);

/**
 * @brief Translate the map data using the projection pipeline.
 * @param map The map data.
 * @param projection The projection pipeline.
 * 
 * As opposed to the project function, this function 
 * 	only runs the 2d translation frames.
 */
void	translate(t_map *map, t_proj *projection);

/**
 * @brief Draw the line data.
 * @param fdf The fdf data.
 * 
 * If drawsteps is set this will draw to the pre-img in
 * 	steps of "drawsteps" lines per frame.
 * else it will draw all the lines at once.
 */
void	draw_loop(t_fdf *fdf);

/**
 * @brief Draw a line.
 * 
 * NOTE this should be re-written at some point, 
 * 	as a reference to the default colour should be passed on some level.
 */
void	draw_line(t_line *ln,
		mlx_image_t *img,
		float thickness);

#endif