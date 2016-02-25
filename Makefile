# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 15:06:22 by tpayen            #+#    #+#              #
#    Updated: 2016/02/25 16:20:26 by tpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fdf
CC = clang
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src/
LIBFTDIR = libft/
OBJDIR = obj/

INCLUDES = -I $(LIBFTDIR) -I includes
LIBS = $(LIBFTDIR)libft.a

SRC_FILES = main.c	\

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
