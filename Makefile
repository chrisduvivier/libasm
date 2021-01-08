# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduvivie <cduvivie@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 00:06:04 by cduvivie          #+#    #+#              #
#    Updated: 2021/01/07 10:42:22 by cduvivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -no-pie

NASM		=	nasm
FLAGS		=	-f elf64

SRCS		=	ft_strcmp.s \
				ft_strcpy.s \
				ft_strlen.s \
				ft_write.s \

OBJS    	=	$(SRCS:.s=.o)

all :			${NAME}

${NAME} :		${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

%.o:			%.s
				$(NASM) ${FLAGS} $< -o $@

main :
				$(CC) $(CFLAGS) main.c libasm.a

clean :			
				rm -rf ${OBJS}

fclean :		clean
				rm -rf ${NAME}

re :            fclean all

.PHONY:         all main clean fclean re