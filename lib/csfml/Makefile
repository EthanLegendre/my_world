SOURCEDIR=./

CC := clang

SRC = \
	src/init_project/window/init_window.c \
	src/init_project/setup.c \
	src/init_project/dispatch.c \
	src/init_project/context/create_destroy.c \
	src/init_project/context/background.c \
	src/init_project/context/setters.c \
	src/init_project/context/context_setters_extra.c \
	src/init_project/context/events.c \
	src/init_project/context/frame.c \
	src/init_project/context/run.c \
	src/textures/simple_textures.c \
	src/buttons/button_create.c \
	src/buttons/button_draw.c \
	src/buttons/button_event.c \
	src/buttons/button_setters.c \
	src/buttons/button_setters_extra.c \
	src/selector/selector.c \
	src/selector/selector_label.c \
	src/selector/selector_accessors.c \
	src/selector/selector_onchange.c \
	src/selector/selector_init.c \
	src/selector/selector_wrappers.c \
	src/selector/selector_helpers.c \
	src/menus/menu_core.c \
	src/menus/menu_state.c \
	src/menus/menu_pages.c \
	src/menus/menu_texts.c \
	src/menus/menu_background.c \
	src/menus/menu_draw.c \
	src/buttons/button_utils.c \
	src/sprite/sprite.c \
	src/textures/delete/delete.c \
	src/sound/parts/internal.c \
	src/sound/parts/get.c \
	src/sound/parts/load.c \
	src/sound/parts/load.c \
	src/sound/parts/play.c \
	src/sound/parts/stop.c \
	src/sound/parts/unload.c \
	src/sound/parts/cleanup.c \
	src/sound/parts/set_all_volume.c \
	src/anims/anim.c

SRC_TEST = /

OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
NAME = CSFML LIB
CFLAGS = -Wall -Wextra -Iincludes
BUILD_NAME = libmy.a
LIBS = libmy.a

all: libs $(OBJDIR) $(OBJ)
	@echo "==============================="
	@echo "\033[1;36m$(NAME) \033[0m"
	@echo "==============================="
	ar rs $(BUILD_NAME) $(OBJ)
	mkdir -p "../../includes/csfml_lib"
	cp includes/*  ../../includes/csfml_lib

libs:
	make -C ../my
	cp ../my/libmy.a ./
	cp ../my/my.h ./includes/my.h

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ../my clean
	rm -rf $(OBJDIR)/*.o $(OBJDIR)/*/*.o $(OBJDIR)/*/*/*.o
	rm -rf tests/*.o

fclean: clean
	rm -f my_ls
	make -C ../my fclean

tests_run: all
	$(CC) $(CFLAGS) -o unit_tests $(SRC_TEST) $(OBJ) $(BUILD_NAME) -L . -lmy --coverage -lcriterion

debug: fclean
	make -e CC="clang -g"

coding_style: fclean
	make -e CC=epiclang

re: fclean all

.PHONY: all re fclean clean coding_style debug tests_run libs