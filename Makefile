# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 15:06:22 by tpayen            #+#    #+#              #
#    Updated: 2016/03/02 16:39:36 by tpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fdf
CC = clang
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src/
LIBFTDIR = libft/
OBJDIR = obj/

INCLUDES = -I$(LIBFTDIR)/includes -Iincludes
LIBS = $(LIBFTDIR)libft.a

SRC_FILES = main.c	\
			init_env.c	\
			get_map.c	\
			draw_map.c	\
			draw_line.c	\
			ft_err_filename.c	\
			key_hook.c	\
			mouse_hook.c	\
			loop_hook.c	\
			ft_px_img.c	\
			expose_hook.c	\

DIRS = $(OBJDIR)

SRC_OBJ = $(SRC_FILES:%.c=$(OBJDIR)%.o)

all: directories $(EXEC)

$(EXEC): $(SRC_OBJ)
	@($(MAKE) -C $(LIBFTDIR))
	$(CC) -o $@ $^ $(LIBS) -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: directories re clean fclean

re: fclean all

clean:
	rm -rf $(OBJDIR)
	@($(MAKE) -C $(LIBFTDIR) $@)
	
fclean: clean
	rm -rf $(EXEC)
	@($(MAKE) -C $(LIBFTDIR) $@)

directories: $(DIRS)

$(DIRS):
	mkdir $@
