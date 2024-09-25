SRC = \
	  camera/color_pixels.c \
	  camera/create_camera_vectors.c \
	  camera/move_camera.c \
	  camera/setup_camera.c \
	  \
	  camera/init_camera_hooks.c \
	  camera/hooks/camera_mouse_hook.c \
	  camera/hooks/change_render_mode.c \
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
	  engine/engine_focus_in.c \
	  engine/engine_loop_hook.c \
	  engine/init_engine.c \
	  engine/quit_engine.c \
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
	  math/mat4/divide_line.c \
	  math/mat4/mat4_identity.c \
	  math/mat4/mat4_inverse.c \
	  math/mat4/mat4_multiply.c \
	  math/mat4/mat4_print.c \
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
	  math/quaternion/quaternion_inv.c \
	  math/quaternion/quaternion_mult.c \
	  math/quaternion/quaternion_rotate.c \
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
	  object/intersect_cached_triangle.c \
	  object/intersect_cylinder.c \
	  object/intersect_mesh.c \
	  object/intersect_paraboloid.c \
	  object/intersect_plane.c \
	  object/intersect_sphere.c \
	  object/intersect_triangle.c \
	  \
	  obj_3d/build_obj_cache.c \
	  obj_3d/clear_obj_3d.c \
	  obj_3d/clear_objs_3d.c \
	  obj_3d/clear_mtl.c \
	  obj_3d/clear_mtls.c \
	  obj_3d/parse_mtl_file.c \
	  obj_3d/parse_obj_mtl_if_needed.c \
	  obj_3d/parse_obj_file.c \
	  obj_3d/parse_obj_if_needed.c \
	  \
	  obj_3d/lines/parse_mtllib.c \
	  obj_3d/lines/parse_f.c \
	  obj_3d/lines/parse_vp.c \
	  obj_3d/lines/parse_vt.c \
	  obj_3d/lines/parse_v.c \
	  obj_3d/lines/parse_vn.c \
	  obj_3d/lines/parse_usemtl.c \
	  \
	  obj_3d/mtl_lines/parse_kd.c \
	  obj_3d/mtl_lines/parse_ks.c \
	  obj_3d/mtl_lines/parse_map_kd.c \
	  obj_3d/mtl_lines/parse_newmtl.c \
	  obj_3d/mtl_lines/parse_ni.c \
	  obj_3d/mtl_lines/parse_ns.c \
	  \
	  parsing/init_object.c \
	  parsing/parse_ambient_light.c \
	  parsing/parse_camera.c \
	  parsing/parse_color.c \
	  parsing/parse_cylinder.c \
	  parsing/parse_double.c \
	  parsing/parse_int.c \
	  parsing/parse_light.c \
	  parsing/parse_material.c \
	  parsing/parse_mesh.c \
	  parsing/parse_normalized_vector3d.c \
	  parsing/parse_optional_data.c \
	  parsing/parse_paraboloid.c \
	  parsing/parse_plane.c \
	  parsing/parse_sphere.c \
	  parsing/parse_texture.c \
	  parsing/parse_triangle.c \
	  parsing/parse_vector3d.c \
	  \
	  scene/clear_scene.c \
	  scene/init_scene.c \
	  \
	  texture/clear_texture.c \
	  texture/clear_textures.c \
	  texture/get_texture_color.c \
	  texture/parse_texture_file.c \
	  texture/parse_texture_if_needed.c \
	  \
	  ray/trace_ray.c \
	  \
	  util/add_color.c \
	  util/add_scale_color.c \
	  util/double_equals.c \
	  util/init_material.c \
	  util/get_biggest_distance.c \
	  util/get_closest_distance.c \
	  util/get_closest_distance_ptr.c \
	  util/get_hitpos.c \
	  util/get_normal_color.c \
	  util/get_theta_axis.c \
	  util/get_uv_color.c \
	  util/multiply_color.c \
	  util/print_error.c \
	  util/scale_color.c \
	  util/solve_plane_equation.c \
	  util/solve_quadratic_equation.c \
	  \
	  main.c \
