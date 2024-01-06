# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:44 by nrajabia          #+#    #+#              #
#    Updated: 2023/12/24 12:26:04 by nrajabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= miniRT
CC		:= cc
CFLAGS	:= -Ofast -Wextra -Wall -Werror -g3
LIBMLX	:= ./MLX42

HEADERS	:= -I ./includes -I $(LIBMLX)/include/MLX42
SRCSDIR	:= srcs
LIBDIR	:= libft
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lXext -lX11 -lm
SRCS	:= camera.c color.c cylinder_utils.c cylinder.c menu.c \
			free_scene.c init_objs.c intersection.c keyhook.c \
			light.c main_utils.c main.c mx_inverse.c mx_operators.c \
			mx_rotation.c mx_transformation.c mx_utils.c my_put_pixel.c \
			new_attributes.c parse_obj.c parse_utils.c parser.c plane.c \
			ray.c reflect.c render.c shadow.c sphere.c utils.c vector.c
LIBFT	:= ft_atof.c ft_error.c ft_free.c ft_isdigit.c ft_lstadd_front.c \
			ft_lstadd_light.c ft_lstnew.c ft_memset.c ft_split.c ft_strlen.c \
			ft_strncmp.c ft_swap.c get_next_line.c
OBJS	:= $(addprefix $(SRCSDIR)/, $(SRCS:.c=.o))
LIBOBJS	:= $(addprefix $(LIBDIR)/, $(LIBFT:.c=.o))

all: $(NAME)

libmlx:
	@if ! [ -d "./MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
		cd $(LIBMLX); cmake -B build ; cmake --build build -j4; \
	fi

$(SRCSDIR)/%.o: $(SRCSDIR)/%.c  | libmlx
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBDIR)/%.o: $(LIBDIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) $(LIBOBJS)
	@$(CC) $(OBJS) $(LIBOBJS) $(HEADERS) -o $(NAME) $(LIBS)
	@echo "Executable $(NAME) created successfully!"

clean:
	@rm -f $(OBJS) $(LIBOBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf ./MLX42

re: fclean all

.PHONY: all clean fclean re libmlx

