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

NAME 						= libftprintf.a

SRC_DIR 					= ./srcs/

SRC_BONUS_DIR 				= ./srcs_bonus/

OBJ_DIR						= ./srcs/objs/

OBJ_BONUS_DIR				= ./srcs_bonus/objs/

INC_DIR 					= ./includes/

INC_BONUS_DIR 				= ./srcs_bonus/include

LIB_DIR						= ./libft/

SRC 						= ft_printf ft_convert ft_check ft_putchar_p ft_putnbr_p \
								ft_put_memory_adress ft_putstr_p

SRCS 						= $(addprefix ${SRC_DIR}, $(addsuffix .c, ${SRC}))

OBJS 						= $(addprefix ${OBJ_DIR}, $(addsuffix .o, ${SRC}))

SRC_BONUS					= ft_printf ft_check ft_putchar_p ft_putnbr_p \
								ft_putstr_p ft_utils ft_flags ft_short ft_manage_p \
								ft_manage_u ft_manage_x ft_len

SRCS_BONUS					= $(addprefix ${SRC_BONUS_DIR}, $(addsuffix .c, ${SRC_BONUS}))

OBJS_BONUS					= $(addprefix ${OBJ_BONUS_DIR}, $(addsuffix .o, ${SRC_BONUS}))

HEAD						= ./includes/

HEAD_BONUS					= ./include/

LIB_NAME					= libft.a

CC							= cc
RM							= rm -f
CFLAGS						= -Wall -Wextra -Werror -fPIE -MD

${OBJ_DIR}%.o:				${SRC_DIR}%.c | ${OBJ_DIR}
							$(CC) $(CFLAGS) -c -I${INC_DIR} -I${LIB_DIR} $< -o $@

${OBJ_BONUS_DIR}%.o:		${SRC_BONUS_DIR}%.c | ${OBJ_BONUS_DIR}
							$(CC) $(CFLAGS) -c -I${INC_BONUS_DIR} -I${LIB_DIR} $< -o $@

${NAME}:					${OBJ_DIR} ${OBJS}
							cd ${LIB_DIR} && ${MAKE} && cp -v ${LIB_NAME} ../${NAME}
							ar rcs ${NAME} ${OBJS}

all:						${OBJ_DIR} ${NAME}

bonus:						${OBJ_BONUS_DIR} ${OBJS_BONUS}
							cd ${LIB_DIR} && ${MAKE} && cp -v ${LIB_NAME} ../${NAME}
							ar rcs ${NAME} ${OBJS_BONUS}

clean:
							${RM} ${NAME}
							${RM} ${OBJS}
							${RM} ${OBJS_BONUS}
							$(RM) $(OBJS:.o=.d)
							cd ${LIB_DIR} && ${MAKE} clean

fclean:						clean
							cd ${LIB_DIR} && ${MAKE} clean
							$(RM) $(OBJS:.o=.d)
							$(RM) $(OBJS_BONUS:.o=.d)


re:							fclean ${NAME}

.PHONY:						all clean fclean re bonus
