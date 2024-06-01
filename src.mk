SRC = \
	  engine/init_engine.c \
	  engine/clear_engine.c \
	  engine/render_frame.c \
	  engine/run_loop.c \
	  \
	  mlx_wrapper/clear_mlx_struct.c \
	  mlx_wrapper/init_mlx_struct.c \
	  \
	  parsing/parse_ambient_light.c \
	  parsing/parse_camera.c \
	  parsing/parse_color.c \
	  parsing/parse_cylinder.c \
	  parsing/parse_light.c \
	  parsing/parse_double.c \
	  parsing/parse_normalized_vector3d.c \
	  parsing/parse_vector3d.c \
	  parsing/parse_plane.c \
	  parsing/parse_sphere.c \
	  parsing/init_object.c \
	  \
	  scene/init_scene.c \
	  scene/clear_scene.c \
	  \
	  ray/trace_ray.c \
	  \
	  util/print_error.c \
	  \
	  vector/vector_addition.c \
	  vector/vector_multiply.c \
	  vector/yaw_pitch_to_vector.c \
	  \
	  main.c \
