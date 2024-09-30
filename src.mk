SRC = \
	  bvh/clear_bvh.c \
	  bvh/clear_bvh_tree.c \
	  bvh/create_bvh_node.c \
	  bvh/get_bvh_depth.c \
	  bvh/get_split_pos_axis.c \
	  bvh/init_bvh.c \
	  bvh/init_bvh_mesh.c \
	  bvh/init_bvh_tree.c \
	  bvh/intersect_bvh.c \
	  bvh/intersect_bvh_mesh.c \
	  bvh/print_objs.c \
	  bvh/print_node.c \
	  bvh/swap_by_axis.c \
	  bvh/swap_by_axis_mesh.c \
	  bvh/update_node_aabb.c \
	  bvh/update_node_aabb_mesh.c \
	  \
	  bvh/bounding_box/create_empty_aabb.c \
	  bvh/bounding_box/get_aabb_from_bbox.c \
	  bvh/bounding_box/get_bbox_from_aabb.c \
	  bvh/bounding_box/get_caustic_aabb.c \
	  bvh/bounding_box/get_aabb_center.c \
	  bvh/bounding_box/get_cylinder_aabb.c \
	  bvh/bounding_box/get_objects_aabb.c \
	  bvh/bounding_box/get_paraboloid_aabb.c \
	  bvh/bounding_box/get_sphere_aabb.c \
	  bvh/bounding_box/is_point_inside_aabb.c \
	  bvh/bounding_box/get_cached_triangle_aabb.c \
	  bvh/bounding_box/get_mesh_aabb.c \
	  bvh/bounding_box/intersect_aabb.c \
	  bvh/bounding_box/print_aabb.c \
	  bvh/bounding_box/print_bounding_box.c \
	  bvh/bounding_box/update_caustic_aabb.c \
	  \
	  bvh/draw/draw_bounding_box.c \
	  bvh/draw/draw_bounding_boxes.c \
	  bvh/draw/draw_bvh.c \
	  bvh/draw/draw_bvh_at_depth.c \
	  bvh/draw/draw_bvh_from_depth.c \
	  bvh/draw/draw_lines.c \
	  bvh/draw/draw_mesh.c \
	  \
	  bvh/hooks/change_bvh_mode.c \
	  bvh/hooks/decrease_full_layer.c \
	  bvh/hooks/decrease_single_layer.c \
	  bvh/hooks/increase_full_layer.c \
	  bvh/hooks/increase_single_layer.c \
	  bvh/hooks/init_bvh_hooks.c \
	  \
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
	  caustic/init_caustic.c \
	  caustic/clear_caustic.c \
	  caustic/init_caustic_maps.c \
	  caustic/clear_caustic_maps.c \
	  caustic/get_photons.c \
	  caustic/trace_photon.c \
	  caustic/print_photon_map.c \
	  caustic/density_estimation.c \
	  \
	  caustic/hooks/init_caustic_hooks.c \
	  caustic/hooks/bandwith_incr.c \
	  caustic/hooks/bandwith_decr.c \
	  caustic/hooks/estimation_incr.c \
	  caustic/hooks/estimation_decr.c \
	  caustic/hooks/nearest_neighbour_incr.c \
	  caustic/hooks/nearest_neighbour_decr.c \
	  \
	  color/add_color.c \
	  color/add_scale_color.c \
	  color/get_normal_color.c \
	  color/get_depth_color.c \
	  color/interpolate_color.c \
	  color/get_uv_color.c \
	  color/multiply_color.c \
	  color/scale_color.c \
	  \
	  engine/clear_engine.c \
	  engine/clear_threads.c \
	  engine/engine_focus_in.c \
	  engine/engine_loop_hook.c \
	  engine/init_engine.c \
	  engine/init_threads.c \
	  engine/quit_engine.c \
	  engine/render_frame.c \
	  engine/routine.c \
	  \
	  engine/shading/get_ambiant_light.c \
	  engine/shading/get_caustics.c \
	  engine/shading/get_fresnel.c \
	  engine/shading/get_light.c \
	  engine/shading/get_pixel_color.c \
	  engine/shading/get_reflect.c \
	  engine/shading/get_reflection_ray.c \
	  engine/shading/get_refraction_ray.c \
	  engine/shading/get_refract.c \
	  engine/shading/phong_model.c \
	  \
	  kdtree/create_kdnode.c \
	  kdtree/init_kdtree.c \
	  kdtree/get_nearest_neighbour.c \
	  kdtree/get_knearest_neighbour.c \
	  kdtree/clear_kdtree.c \
	  kdtree/init_knn.c \
	  kdtree/empty_knn.c \
	  kdtree/set_knn_size.c \
	  kdtree/clear_knns.c \
	  kdtree/print_kdtree.c \
	  kdtree/print_knn.c \
	  kdtree/sort_photon_axis.c \
	  \
	  math/mat4/divide_line.c \
	  math/mat4/mat4_identity.c \
	  math/mat4/mat4_inverse.c \
	  math/mat4/mat4_multiply.c \
	  math/mat4/mat4_print.c \
	  math/mat4/mat4_scale.c \
	  math/mat4/mat4_view.c \
	  math/mat4/swap_lines.c \
	  \
	  math/vec2/vec2_create.c \
	  \
	  math/vec3/vec3_add.c \
	  math/vec3/vec3_create.c \
	  math/vec3/vec3_cross.c \
	  math/vec3/vec3_dot.c \
	  math/vec3/vec3_get_norm.c \
	  math/vec3/vec3_normalize.c \
	  math/vec3/vec3_print.c \
	  math/vec3/vec3_scale.c \
	  math/vec3/vec3_subtract.c \
	  math/vec3/vec3_random.c \
	  \
	  math/vec4/vec4_create.c \
	  math/vec4/vec4_mat4_mult.c \
	  math/vec4/vec4_divide_nw.c \
	  math/vec4/vec4_substract_vec3.c \
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
	  normal_map/apply_normal_map.c \
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
	  obj_3d/mtl_lines/parse_map_bump.c \
	  obj_3d/mtl_lines/parse_map_kd.c \
	  obj_3d/mtl_lines/parse_newmtl.c \
	  obj_3d/mtl_lines/parse_ni.c \
	  obj_3d/mtl_lines/parse_ns.c \
	  \
	  parsing/init_object.c \
	  parsing/parse_ambient_light.c \
	  parsing/parse_background_color.c \
	  parsing/parse_camera.c \
	  parsing/parse_caustic.c \
	  parsing/parse_checkerboard.c \
	  parsing/parse_color.c \
	  parsing/parse_cylinder.c \
	  parsing/parse_double.c \
	  parsing/parse_int.c \
	  parsing/parse_light.c \
	  parsing/parse_material.c \
	  parsing/parse_mesh.c \
	  parsing/parse_normal_map.c \
	  parsing/parse_normalized_vector3d.c \
	  parsing/parse_optional_data.c \
	  parsing/parse_paraboloid.c \
	  parsing/parse_plane.c \
	  parsing/parse_sphere.c \
	  parsing/parse_texture.c \
	  parsing/parse_triangle.c \
	  parsing/parse_uint8t.c \
	  parsing/parse_vector3d.c \
	  \
	  scene/clear_scene.c \
	  scene/init_scene.c \
	  scene/read_file.c \
	  \
	  texture/apply_checkerboard.c \
	  texture/clear_texture.c \
	  texture/clear_textures.c \
	  texture/get_texture_color.c \
	  texture/parse_texture_file.c \
	  texture/parse_texture_if_needed.c \
	  \
	  ray/get_inv_dir.c \
	  ray/trace_ray.c \
	  \
	  util/double_equals.c \
	  util/find_max.c \
	  util/find_mean.c \
	  util/find_min.c \
	  util/init_material.c \
	  util/get_axis.c \
	  util/get_biggest_distance.c \
	  util/get_closest_distance.c \
	  util/get_closest_distance_ptr.c \
	  util/get_hitpos.c \
	  util/get_theta_axis.c \
	  util/print_error.c \
	  util/set_texture_normal.c \
	  util/solve_plane_equation.c \
	  util/solve_quadratic_equation.c \
	  util/rand_range.c \
	  \
	  main.c \
