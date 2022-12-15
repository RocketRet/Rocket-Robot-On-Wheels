#ifndef __MATHUTILS_H__
#define __MATHUTILS_H__

#include "types.h"

float vec2f_magnitude(Vec2f in);

void set_vec3f_components(Vec3f vec, f32 x, f32 y, f32 z);
void vec3f_rotate(Mtx3f mat, Vec3f in, Vec3f out);
void vec3f_transform(Mtx4f mat, Vec3f in, f32 w, Vec3f out);
float vec3f_safe_normalize(Vec3f in, Vec3f out);
float vec3f_dist(Vec3f a, Vec3f b);
float vec3f_xy_dist(Vec3f a, Vec3f b);
float vec3f_dist_sq(Vec3f a, Vec3f b);
void vec3f_scale(float scale, Vec3f in, Vec3f out);
void vec3f_cross_product(Vec3f a, Vec3f b, Vec3f out);
void vec3f_scale_add(float aScale, Vec3f a, float bScale, Vec3f b, Vec3f out);
void vec3f_lerp(float t, Vec3f a, Vec3f b, Vec3f out);
f32 vec3f_normalize(Vec3f vec);
void vec3f_transpose_rotate(Mtx3f mat, Vec3f in, Vec3f out);

void mtx3f_concat(Mtx3f a, Mtx3f b, Mtx3f out);
void mtx3f_transpose(Mtx3f in, Mtx3f out);
void mtx3f_rotate_axis(f32 angle, Vec3f arg1, Mtx3f out);
void mtx3f_axis_angle(Vec3f in, Mtx3f out);

void sincosf(float angle, float* sinout, float* cosout);

#endif
