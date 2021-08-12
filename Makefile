# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 15:18:43 by jvanden-          #+#    #+#              #
#    Updated: 2021/08/12 17:07:00 by jvanden-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCL		=	./inc/

CFLAGS		= -I $(INCL) $(FLAGS)

NAME_SERVER	=	server
NAME_CLIENT	=	client

### PATH ###

SRCS_PATH	=	src/

SRCS_SERVER	=	server_launcher.c

SRCS_CLIENT	=	client.c
				
SRCS_UTILS	=	ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_atoi.c \
				ft_is_only_number.c \
				ft_print_int.c \
				ft_straddc.c \
				ft_strdup.c

SRCS_SERVER2=	$(addprefix $(SRCS_PATH), $(SRCS_SERVER)) \
				$(addprefix $(SRCS_PATH)utils/, $(SRCS_UTILS))

SRCS_CLIENT2=	$(addprefix $(SRCS_PATH), $(SRCS_CLIENT)) \
				$(addprefix $(SRCS_PATH)utils/, $(SRCS_UTILS))

OBJ_SERVER	=	$(SRCS_SERVER2:.c=.o)
OBJ_CLIENT	=	$(SRCS_CLIENT2:.c=.o)

######### RULES #######

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER)
	@$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	@$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS)

clean:
	@/bin/rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@/bin/rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
	
.PHONY: all re clean fclean 