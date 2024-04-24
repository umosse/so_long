# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 13:53:27 by umosse            #+#    #+#              #
#    Updated: 2024/04/23 16:57:21 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
NAME_BONUS = 
SRCS = so_long.c movement.c map.c draw.c
SRCS_BONUS = 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) minilibx Libft/libft.a Printf/printf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm Libft/libft.a Printf/libftprintf.a

minilibx:
	make -C minilibx-linux

bonus: $(OBJS_BONUS) Libft/libft.a Printf/printf.a
	cc $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) Libft/libft.a Printf/libftprintf.a

Libft/libft.a:
	make -C Libft

Printf/printf.a:
	make -C Printf

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	cd Libft && make clean
	cd Printf && make clean

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	cd Libft && make fclean
	cd Printf && make fclean

re: fclean all

.PHONY : all clean fclean re
