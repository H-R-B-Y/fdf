/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:11:38 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 16:11:38 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HB_MATH_EXT_H
# define HB_MATH_EXT_H

# include <math.h>

# define MY_PI 3.14159265358979323846


// ██    ██ ███████  ██████ ██████  
// ██    ██ ██      ██           ██ 
// ██    ██ █████   ██       █████  
//  ██  ██  ██      ██      ██      
//   ████   ███████  ██████ ███████ 

typedef struct s_vec2	t_vec2;

struct s_vec2
{
	float	x;
	float	y;
};

float	vec2_mag(t_vec2 *vec);
float	vec2_dot(t_vec2 *vec1, t_vec2 *vec2);
t_vec2	vec2_norm(t_vec2 *vec);
t_vec2	vec2_add(t_vec2 *vec1, t_vec2 *vec2);
t_vec2	vec2_euler(t_vec2 *vec, float angle);
t_vec2	vec2_smult(t_vec2 *vec, float scalar);
t_vec2	vec2_mult(t_vec2 *vec1, t_vec2 *vec2);

// ██    ██ ███████  ██████ ██████  
// ██    ██ ██      ██           ██ 
// ██    ██ █████   ██       █████  
//  ██  ██  ██      ██           ██ 
//   ████   ███████  ██████ ██████  

typedef struct s_vec3	t_vec3;

struct s_vec3
{
	float	x;
	float	y;
	float	z;
};

float	vec3_mag(t_vec3 *vec);
float	vec3_dot(t_vec3 *vec1, t_vec3 *vec2);
t_vec3	vec3_norm(t_vec3 *vec);
t_vec3	vec3_add(t_vec3 *vec1, t_vec3 *vec2);
t_vec3	vec3_smult(t_vec3 *vec, float scalar);
t_vec3	vec3_mult(t_vec3 *vec1, t_vec3 *vec2);

// ███    ███ ████████ ██████  ██   ██ 
// ████  ████    ██    ██   ██  ██ ██  
// ██ ████ ██    ██    ██████    ███   
// ██  ██  ██    ██    ██   ██  ██ ██  
// ██      ██    ██    ██   ██ ██   ██ 

typedef struct s_mtrx2	t_mtrx2;

struct s_mtrx2
{
	t_vec2	x;
	t_vec2	y;
};

t_vec2	vec2_mtrx2(t_vec2 *vec, t_mtrx2 *mtrx);
t_mtrx2	mtrx2_mult(t_mtrx2 *m1, t_mtrx2 *m2);
t_mtrx2	euler_to_mtrx2(float euler);
t_mtrx2	mtrx2_identity(void);
t_mtrx2	mtrx2_transpose(t_mtrx2 *mtrx);
t_mtrx2	scaling_matrix_2d(float scale_x, float scale_y);

typedef struct s_mtrx3	t_mtrx3;

struct s_mtrx3
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;
};

t_vec3	vec3_mtrx3(t_vec3 *vec, t_mtrx3 *mtrx);
t_mtrx3	mtrx_mult(t_mtrx3 *m1, t_mtrx3 *m2);
t_mtrx3	euler_to_mtrx3(float x, float y, float z);
t_mtrx3	mtrx3_identity(void);
t_mtrx3	mtrx3_transpose(t_mtrx3 *mtrx);
t_mtrx3	scaling_matrix_3d(float scale_x, float scale_y, float scale_z);

#endif