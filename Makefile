##
## EPITECH PROJECT, 2025
## my_radar
## File description:
## my_radar
##

CC = epiclang
CFLAGS = -I include -I lib/csfml/includes

SRC_LIB = lib/my/array/get_len_array_int.c \
	lib/my/array/mem_alloc_2d_array_int.c \
	lib/my/array/my_sor_int_array.c \
	lib/my/array/get_len_array_str.c \
	lib/my/array/mem_alloc_2d_array_str.c \
	lib/my/convert/convert_exadecimal.c \
	lib/my/convert/convert_str_to_int.c \
	lib/my/convert/convert_octal.c \
	lib/my/file/create_path.c  \
	lib/my/file/get_content_file.c  \
	lib/my/file/get_file_size.c \
	lib/my/float/my_put_float.c \
	lib/my/int/get_int_len.c \
	lib/my/int/my_is_negative.c \
	lib/my/int/my_swap.c \
	lib/my/int/my_get_number.c \
	lib/my/int/my_put_number.c \
	lib/my/long/my_put_long.c \
	lib/my/str/check_char_in_str.c \
	lib/my/str/my_strdup.c \
	lib/my/str/my_str_len.c \
	lib/my/str/my_putchar.c \
	lib/my/str/my_str_in_str.c \
	lib/my/str/my_str_low_case.c \
	lib/my/str/my_put_str.c \
	lib/my/str/my_str_is_alpha.c \
	lib/my/str/my_str_ncat.c \
	lib/my/str/my_revstr.c \
	lib/my/str/my_str_is_lower.c \
	lib/my/str/my_str_up_case.c \
	lib/my/str/my_str_cat.c \
	lib/my/str/my_str_is_num.c \
	lib/my/str/my_strcmp.c \
	lib/my/str/my_str_is_upper.c \
	lib/my/str/my_strncmp.c \
	lib/my/char/my_char_is_alpha.c \
	lib/my/str/my_str_to_word_array_by_chars.c \
	lib/my/str/my_str_to_word_array.c \
	lib/my/file/get_content_proc.c \
	lib/my/time/get_time_by_sec.c \
	lib/my/str/convert_int_to_str.c \
	lib/my/str/convert_str_to_int.c \
	lib/my/array/free_word_array.c \
	lib/my/convert/convert_kb_to_mb.c

SRC = src/init/init.c \
	src/end/game_end.c \
	src/loop/loop.c \
	src/loop/frame/frame.c \
	src/loop/draw/draw.c \
	src/loop/input/key_events.c \
	src/loop/frame/manage_camera.c \
	src/map/gen_map/noise.c \
	src/map/edit_map/change_color_line_by_z.c \
	src/map/edit_map/create_2d_map_empty.c \
	src/map/edit_map/create_line_by_two_points.c \
	src/map/edit_map/draw_edit_map.c \
	src/map/edit_map/manage_edit_mode.c \
	src/map/edit_map/manage_select_point.c \
	src/map/edit_map/project_iso_point.c \
	src/map/edit_map/update_edit_map.c\
	src/map/rendus_map/create_convex_array_empty.c \
	src/map/rendus_map/draw_rendus_map.c \
	src/map/rendus_map/fit_convex_by_map.c \
	src/map/rendus_map/manage_rendus_mode.c

SRC_CSFML = \
	lib/csfml/src/init_project/window/init_window.c \
	lib/csfml/src/init_project/setup.c \
	lib/csfml/src/init_project/dispatch.c \
	lib/csfml/src/init_project/context/create_destroy.c \
	lib/csfml/src/init_project/context/background.c \
	lib/csfml/src/init_project/context/setters.c \
	lib/csfml/src/init_project/context/context_setters_extra.c \
	lib/csfml/src/init_project/context/events.c \
	lib/csfml/src/init_project/context/frame.c \
	lib/csfml/src/init_project/context/run.c \
	lib/csfml/src/textures/simple_textures.c \
	lib/csfml/src/sound/parts/internal.c \
	lib/csfml/src/sound/parts/get.c \
	lib/csfml/src/sound/parts/load.c \
	lib/csfml/src/sound/parts/play.c \
	lib/csfml/src/sound/parts/stop.c \
	lib/csfml/src/sound/parts/unload.c \
	lib/csfml/src/sound/parts/cleanup.c \
	lib/csfml/src/sound/parts/set_all_volume.c

SRC += $(SRC_CSFML)

OBJ_LIB = $(SRC_LIB:.c=.o)
OBJ = $(SRC:.c=.o)

NAME_LIB = libbig.a
NAME = my_world

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB) src/main.c
	ar rc $(NAME_LIB) $(OBJ_LIB)
	mv $(NAME_LIB) lib
	$(CC) $(OBJ) src/main.c -I include -I lib/csfml/includes -Llib -lbig -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
	rm -f $(OBJ)
	rm -f $(OBJ_LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

codingstyle:
	cc = epiclang
codingstyle: re