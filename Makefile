# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:18:05 by tmaillar          #+#    #+#              #
#    Updated: 2023/05/15 08:42:07 by tmaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRC_DIR 	= ./srcs/

INC_DIR 	= ./includes/

LIB_DIR		= ./libft/

SRC 		= ft_printf ft_convert ft_check ft_putchar_p ft_putnbr_p ft_put_memory_adress ft_putstr_p

SRCS 		= $(addprefix ${SRC_DIR}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/

OBJS 		= ${SRCS:.c=.o}

LIB_NAME	= libft.a

CC	= cc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
		${CC} ${CFLAGS} -c -I${INC_DIR} -I${LIB_DIR}  $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		cd ${LIB_DIR} && ${MAKE} && cp -v ${LIB_NAME} ../${NAME}
		ar rcs ${NAME} ${OBJS}

all :	${NAME}

clean :
		${RM} ${OBJS}
		cd ${LIB_DIR} && ${MAKE} clean

fclean : clean
		${RM} ${NAME}
		cd ${LIB_DIR} && ${MAKE} clean


re :		fclean ${NAME}

.PHONY :	all clean fclean re
