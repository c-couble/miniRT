SRC = \
	  camera/setup_camera.c \
	  \
	  engine/clear_engine.c \
	  engine/get_ambiant_light.c \
	  engine/get_light.c \
	  engine/get_pixel_color.c \
	  engine/get_reflect.c \
	  engine/get_refract.c \
	  engine/init_engine.c \
	  engine/phong_model.c \
	  engine/render_frame.c \
	  engine/run_loop.c \
	  \
	  mlx_wrapper/clear_mlx_struct.c \
	  mlx_wrapper/init_mlx_struct.c \
	  \
	  object/intersect.c \
	  object/intersect_cylinder.c \
	  object/intersect_paraboloid.c \
	  object/intersect_plane.c \
	  object/intersect_sphere.c \
	  object/intersect_triangle.c \
	  \
	  mat4/divide_line.c \
	  mat4/mat4_identity.c \
	  mat4/mat4_inverse.c \
	  mat4/mat4_multiply.c \
	  mat4/mat4_print.c \
	  mat4/swap_lines.c \
	  \
	  parsing/init_object.c \
	  parsing/parse_ambient_light.c \
	  parsing/parse_camera.c \
	  parsing/parse_color.c \
	  parsing/parse_cylinder.c \
	  parsing/parse_double.c \
	  parsing/parse_light.c \
	  parsing/parse_material.c \
	  parsing/parse_normalized_vector3d.c \
	  parsing/parse_paraboloid.c \
	  parsing/parse_plane.c \
	  parsing/parse_sphere.c \
	  parsing/parse_triangle.c \
	  parsing/parse_vector3d.c \
	  \
	  scene/clear_scene.c \
	  scene/init_scene.c \
	  \
	  ray/trace_ray.c \
	  \
	  util/add_color.c \
	  util/add_scale_color.c \
	  util/get_closest_distance.c \
	  util/get_hitpos.c \
	  util/get_normal_color.c \
	  util/get_reflection_ray.c \
	  util/multiply_color.c \
	  util/print_error.c \
	  util/scale_color.c \
	  util/solve_plane_equation.c \
	  util/solve_quadratic_equation.c \
	  \
	  vec3/vec3_add.c \
	  vec3/vec3_create.c \
	  vec3/vec3_cross_product.c \
	  vec3/vec3_dot_product.c \
	  vec3/vec3_get_norm.c \
	  vec3/vec3_normalize.c \
	  vec3/vec3_scale.c \
	  vec3/vec3_subtract.c \
	  \
	  vec4/vec4_create.c \
	  vec4/vec4_mat4_mult.c \
	  \
	  main.c \
