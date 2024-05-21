LIBS_DIR = lib

INCLUDES_DIR = include

SRC_DIR = src

BUILD_DIR = .build

LIBFT_DIR = $(LIBS_DIR)/libft

LIBFT = libft.a

LIBFT_DEBUG = libft_debug.a

MLX_DIR = $(LIBS_DIR)/minilibx-linux

MLX = libmlx.a

CFLAGS = -Wall -Wextra -Werror \
		 -MD -MP \
		 -I $(INCLUDES_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDES_DIR) \
		 -I $(MLX_DIR) \

LDFLAGS = -lX11 -lm -lz -lXext

OPTIMIZE_FLAGS = -O3

DEBUG_FLAGS = -g3

include src.mk

NAME = miniRT

NAME_DEBUG = $(NAME)_debug

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

OBJ_DEBUG = $(addprefix $(BUILD_DIR)/, $(SRC:.c=_debug.o))

DEPS = $(OBJ:.o=.d)

DEPS_DEBUG = $(OBJ_DEBUG:.o=.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(LDFLAGS)

-include $(DEPS)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(OPTIMIZE_FLAGS) -c $< -o $@


$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT)

$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

.PHONY: debug
debug: $(NAME_DEBUG)

$(NAME_DEBUG): $(OBJ_DEBUG)
	$(CC) -o $(NAME_DEBUG) $(OBJ_DEBUG) $(LIBFT_DIR)/$(LIBFT_DEBUG) $(MLX_DIR)/$(MLX) $(LDFLAGS)

-include $(DEPS_DEBUG)
$(BUILD_DIR)/%_debug.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT_DEBUG) $(MLX_DIR)/$(MLX)
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT_DEBUG): FORCE
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT_DEBUG)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME) $(NAME_DEBUG)

.PHONY: clean
clean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -r $(BUILD_DIR)

.PHONY: re
re: fclean
	$(MAKE) all

.PHONY: bonus
bonus: $(NAME)

.PHONY: FORCE
FORCE:
