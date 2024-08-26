SRC = \
	  camera/color_pixels.c \
	  camera/create_camera_vectors.c \
	  camera/move_camera.c \
	  camera/setup_camera.c \
	  \
	  camera/init_camera_hooks.c \
	  camera/hooks/camera_mouse_hook.c \
	  camera/hooks/lock_camera.c \
	  camera/hooks/move_backwards.c \
	  camera/hooks/move_down.c \
	  camera/hooks/move_forward.c \
	  camera/hooks/move_left.c \
	  camera/hooks/move_right.c \
	  camera/hooks/move_up.c \
	  camera/hooks/reset_roll_angle.c \
	  camera/hooks/roll_left.c \
	  camera/hooks/roll_right.c \
	  camera/hooks/speed_down.c \
	  camera/hooks/speed_up.c \
	  \
	  engine/clear_engine.c \
	  engine/engine_escape.c \
	  engine/engine_focus_in.c \
	  engine/engine_loop_hook.c \
	  engine/init_engine.c \
	  engine/render_frame.c \
	  \
	  engine/shading/get_ambiant_light.c \
	  engine/shading/get_fresnel.c \
	  engine/shading/get_light.c \
	  engine/shading/get_pixel_color.c \
	  engine/shading/get_reflect.c \
	  engine/shading/get_reflection_ray.c \
	  engine/shading/get_refraction_ray.c \
	  engine/shading/get_refract.c \
	  engine/shading/phong_model.c \
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
	  quaternion/quaternion_inv.c \
	  quaternion/quaternion_mult.c \
	  quaternion/quaternion_rotate.c \
	  \
	  ray/trace_ray.c \
	  \
	  util/add_color.c \
	  util/add_scale_color.c \
	  util/double_equals.c \
	  util/get_closest_distance.c \
	  util/get_closest_distance_ptr.c \
	  util/get_hitpos.c \
	  util/get_normal_color.c \
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
