# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 13:36:41 by oabdelfa          #+#    #+#              #
#    Updated: 2022/01/23 10:38:33 by oabdelfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
#srcs file
SRCS = main.c cases.c read_map.c write_map.c utils.c 
#libft name
LIBFT = libft
#objs are the files from srcs with .c but .o instead
OBJS = $(subst .c,.o,$(SRCS))
#compiling flags
FLAGS = -Wall -Wextra -Werror

#linking to location of libft and .a -L library, -I is for reaching folders, 
#-l for files.c
# LINKS := -I libft/includes -L libft -I /usr/local/include -L /usr/local/lib \
# 		-l mlx -l ft -framework OpenGL -framework Appkit
LINKS := -I libft/includes -L libft -I mlx/includes -L mlx\
		-l mlx -l ft -lmlx -lX11 -lXext -lm

CC = gcc
#make first the make -C from LIBFT directory, -C to go into a root directory, 
#then MAKE the current make
all:
	$(MAKE) -C	$(LIBFT)
	$(MAKE)		$(NAME)
#NAME calling .o files then compiles the .c files with the program name, applies 
#the flags then links from the library locations
#tip! need to compile first to create .o files then a compiler to run linking
$(NAME):
	$(CC) $(SRCS) $(LINKS) $(FLAGS) -o $(NAME)
clean:
	rm -f $(OBJS)
	rm -f libft/*.o
fclean: clean
	rm -f $(NAME)
	rm -f libft/*.a
re: fclean all
