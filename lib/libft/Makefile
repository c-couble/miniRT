NAME = libft.a

NAME_DEBUG = libft_debug.a

INCLUDE_DIR = include

SRC_DIR = src

BUILD_DIR = .build

-include src.mk

CFLAGS = -Wall -Wextra -Werror \
		 -MD -MP \
		 -I $(INCLUDE_DIR)

DEBUG_FLAGS = -g3

OPTIMIZE_FLAGS = -O3

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

OBJ_DEBUG = $(addprefix $(BUILD_DIR)/, $(SRC:.c=_debug.o))

DEPS_DEBUG = $(OBJ_DEBUG:.o=.d)

.PHONY: all
all: $(NAME)

.PHONY: re
re: fclean
	$(MAKE) $(NAME)


$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

-include $(DEPS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(OPTIMIZE_FLAGS) -c $< -o $@

$(NAME_DEBUG): $(OBJ_DEBUG)
	ar crs $(NAME_DEBUG) $(OBJ_DEBUG)

-include $(DEPS_DEBUG)

$(BUILD_DIR)/%_debug.o : $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

.PHONY: debug
debug: $(NAME_DEBUG)

.PHONY: fclean
fclean: clean
	rm -f $(NAME) $(NAME_DEBUG)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

