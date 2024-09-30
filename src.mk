SRC = \
	  camera/color_pixels.c \
	  camera/create_camera_vectors.c \
	  camera/setup_camera.c \
	  \
	  engine/clear_engine.c \
	  engine/init_engine.c \
	  engine/quit_engine.c \
	  engine/render_frame.c \
	  \
	  engine/shading/get_ambiant_light.c \
	  engine/shading/get_light.c \
	  engine/shading/get_pixel_color.c \
	  engine/shading/phong_model.c \
	  \
	  math/mat4/divide_line.c \
	  math/mat4/mat4_identity.c \
	  math/mat4/mat4_inverse.c \
	  math/mat4/mat4_multiply.c \
	  math/mat4/swap_lines.c \
	  \
	  math/vec3/vec3_add.c \
	  math/vec3/vec3_create.c \
	  math/vec3/vec3_cross.c \
	  math/vec3/vec3_dot.c \
	  math/vec3/vec3_get_norm.c \
	  math/vec3/vec3_normalize.c \
	  math/vec3/vec3_scale.c \
	  math/vec3/vec3_subtract.c \
	  \
	  math/vec4/vec4_create.c \
	  math/vec4/vec4_mat4_mult.c \
	  \
	  mlx_wrapper/hooks/destroy_hook.c \
	  mlx_wrapper/hooks/focus_in_hook.c \
	  mlx_wrapper/hooks/focus_out_hook.c \
	  mlx_wrapper/hooks/key_down_hook.c \
	  mlx_wrapper/hooks/key_up_hook.c \
	  mlx_wrapper/hooks/loop_hook.c \
	  mlx_wrapper/hooks/mouse_down_hook.c \
	  mlx_wrapper/hooks/mouse_up_hook.c \
	  mlx_wrapper/hooks/mouse_motion_hook.c \
	  \
	  mlx_wrapper/clear_mlx_struct.c \
	  mlx_wrapper/create_mlx_hook.c \
	  mlx_wrapper/init_mlx_struct.c \
	  \
	  object/intersect.c \
	  object/intersect_cylinder.c \
	  object/intersect_plane.c \
	  object/intersect_sphere.c \
	  \
	  parsing/init_object.c \
	  parsing/parse_ambient_light.c \
	  parsing/parse_camera.c \
	  parsing/parse_color.c \
	  parsing/parse_cylinder.c \
	  parsing/parse_double.c \
	  parsing/parse_int.c \
	  parsing/parse_light.c \
	  parsing/parse_normalized_vector3d.c \
	  parsing/parse_plane.c \
	  parsing/parse_sphere.c \
	  parsing/parse_vector3d.c \
	  \
	  scene/clear_scene.c \
	  scene/init_scene.c \
	  \
	  ray/trace_ray.c \
	  \
	  util/add_color.c \
	  util/add_scale_color.c \
	  util/get_biggest_distance.c \
	  util/double_equals.c \
	  util/get_closest_distance.c \
	  util/get_closest_distance_ptr.c \
	  util/get_hitpos.c \
	  util/multiply_color.c \
	  util/print_error.c \
	  util/scale_color.c \
	  util/solve_plane_equation.c \
	  util/solve_quadratic_equation.c \
	  \
	  main.c \
