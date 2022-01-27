# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelfa <oabdelfa@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 13:36:41 by oabdelfa          #+#    #+#              #
#    Updated: 2022/01/27 11:46:43 by oabdelfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = fdf

#srcs files
SRCS = srcs/main.c srcs/cases.c srcs/read_map.c srcs/write_map.c srcs/utils.c 

#libft name
LIBFT = libft

#MLX Library
MLX = minilibx-linux

#objs are the files from srcs with .c but .o instead
OBJS = $(subst .c,.o,$(SRCS))

#compiling flags
FLAGS = -Wall -Wextra -Werror

#linking to location of libft and .a -L library, -I is for reaching folders, 
#-l for files.c \\ NOTE: USE THIS TO COMPILE IN MAC OS, AND CHANGE THE INCLUDES
# LOCATION TO minilibx-linux
LINKS := -I libft/includes -L libft -I includes -L srcs -I /usr/local/include -L /usr/local/lib \
		-l mlx -l ft -framework OpenGL -framework Appkit

#NOTE: COMMENT OUT THE TOP LINK AND USE THIS LOWER ONE WHEN COMPILING IN LINUX
# LINKS := -I libft/includes -L libft -I minilibx-linux -L minilibx-linux -I includes -L srcs\
# 		-l mlx -l ft -lmlx -lX11 -lXext -lm

#compiling line
CC = gcc

#make first the make -C from LIBFT directory, -C to go into a root directory, 
#then MAKE the current make
#NOTE: ADD $(MAKE) -C $(MLX) UNDER LIBFT LINE WHEN COMPILING IN LINUX
all:
	$(MAKE) -C	$(LIBFT)
	$(MAKE) -C	$(MLX)	
	$(MAKE)		$(NAME)

#NAME calling .o files then compiles the .c files with the program name, applies 
#the flags then links from the library locations
#tip! need to compile first to create .o files then a compiler to run linking
$(NAME):
	$(CC) $(SRCS) $(LINKS) $(FLAGS) -o $(NAME)

#Make command to delete .o files
clean:
	rm -f $(OBJS)
	rm -f libft/*.o

#Make command to delete the libraries files
fclean: clean
	rm -f $(NAME)
	rm -f libft/*.a

#Make command to re-do everything from the beginning
re: fclean all
