# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:22:36 by eminatch          #+#    #+#              #
#    Updated: 2022/11/15 20:29:09 by eminatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_PATH = src/
SRC = main.c \
		player.c \
		maps.c \
		graphics.c \
		init.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
LIBS = -L./Libs/LIBFT -lft -L./Libs/minilibx-linux -lmlx -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS = -I./includes  -I./Libs/minilibx-linux

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) --no-print-directory header
	@echo "Compiling LIBFT objects ⚡\n"
	@$(MAKE) --no-print-directory -C ./Libs/LIBFT
	@echo "\nCompiling Minilibx objects ⚡\n"
	@$(MAKE) --no-print-directory -C ./Libs/minilibx-linux
	@echo "\nCompiling So_long objects ⚡\n"
	@$(CC) $(CFLAGS) $(OBJS) ${LIBS} -o $(NAME)
	@echo "\nCompiled Minilibx-linux 🍀\n"
	@echo "\nCompiled SO_LONG 🍀\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) ${INCS} -o $@ -c $<

clean:
	@$(MAKE) --no-print-directory clean -C ./Libs/LIBFT
	@echo "\nCleaning Minilibx_linux objects 🧹\n"
	@$(MAKE) --no-print-directory clean -C ./Libs/minilibx-linux
	@echo "\nClean Minilibx_linux ✨\n"
	@echo "\nCleaning SO_LONG objects 🧹\n"
	@${RM} $(OBJ_PATH) ${DEPS}
	@echo "\nClean SO_LONG ✨\n"

fclean: clean
	@echo "\nFCleaning LIBFT 🧹\n"
	@$(MAKE) --no-print-directory fclean -C ./Libs/LIBFT
	@echo "\nFClean LIBFT 🧹\n"
	@echo "\nFCleaning SO_LONG 🧹\n"
	@${RM} $(NAME)
	@echo "\nFClean SO_LONG ✨\n"

re: fclean all

define HEADER
 ___    _____        _      _____  _   _  ___              __     ___           _  _   _  _____  _____  ___    _   _ 
(  _`\ (  _  )      ( )    (  _  )( ) ( )(  _`\           /  )   (  _`\ /'\_/`\(_)( ) ( )(  _  )(_   _)(  _`\ ( ) ( )
| (_(_)| ( ) |      | |    | ( ) || `\| || ( (_)        /' /'    | (_(_)|     || || `\| || (_) |  | |  | ( (_)| |_| |
`\__ \ | | | |      | |  _ | | | || , ` || |___       /' /'      |  _)_ | (_) || || , ` ||  _  |  | |  | |  _ |  _  |
( )_) || (_) |      | |_( )| (_) || |`\ || (_, )    /' /'        | (_( )| | | || || |`\ || | | |  | |  | (_( )| | | |
`\____)(_____)      (____/'(_____)(_) (_)(____/'   (_/'          (____/'(_) (_)(_)(_) (_)(_) (_)  (_)  (____/'(_) (_)
              ______                                                                                                 
             (______)                                                                                              
                              
endef
export HEADER

header :
	clear
	@echo "$$HEADER"

-include ${DEPS}

.SECONDARY : ${OBJ} ${OBJ_PATH} ${OBJS}

.PHONY : all clean fclean re
