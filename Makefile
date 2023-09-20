# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 18:12:45 by jnuncio-          #+#    #+#              #
#    Updated: 2023/09/19 23:20:21 by jnuncio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# HIGHLIGHTING COLOR

HL_GREEN = $(shell tput setab 2)
HL_CYAN = $(shell tput setab 6)

# FONT COLOR

RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
RESET = $(shell tput sgr0)

NAME = push_swap
BIN	= bin
INCFT = libft/include
LIBFT = libft/
LIBFT_BIN = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCFT) -Iinclude -g
LFLAGS = -L$(LIBFT) -lft #-fsanitize=address
RM = rm -rf
SRC = $(addprefix src/, main.c\
	lst_aux.c\
	checks.c\
	utils.c\
	moves1.c\
	moves2.c)
OBJ = $(SRC:src/%c=bin/%o)

all: $(LIBFT) $(BIN) $(NAME)

$(NAME): $(OBJ)
	@echo -n "Compiling push_swap... "
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) &&\
	echo "$(GREEN)OK!$(RESET)" || echo "$(RED)KO!$(RESET)"

$(BIN):
	@echo "------------------------------------------------------"
	@echo "$(HL_CYAN)push_swap:$(RESET)";
	@test -d $(BIN) || (mkdir -p $(BIN) &&\
	echo "$(GREEN)Created $(BIN) directory.$(RESET)") ||\
	echo "$(RED)Failed to create $(BIN) directory.$(RESET)"

$(LIBFT): $(LIBFT_BIN)
	@echo "------------------------------------------------------"
	@make -C libft --no-print-directory &&\
	echo -n "$(HL_CYAN)libft:$(RESET)" &&\
	echo "$(GREEN) OK!$(RESET)" ||\
	echo "$(RED) KO!$(RESET)"

$(BIN)/%o: src/%c
	@$(CC) -c $< $(CFLAGS) -o $@

clean: cleanlib hl_push_swap
	@if [ -n "$(wildcard bin/*.o)" ]; then \
		$(RM) $(OBJ); \
		echo "$(GREEN)deleted object files$(RESET)"; \
	elif [ ! -n "$(wildcard bin/*.o)" ] && ([ -e push_swap ]); then \
		echo "$(YELLOW)there are no object files$(RESET)"; \
	fi
	@test -d $(BIN) && $(RM) $(BIN) &&\
	echo "$(GREEN)deleted $(BIN) directory$(RESET)" || true
	
fclean: cleanlib fcleanlib clean hl_push_swap
	@test -e push_swap && $(RM) push_swap &&\
	echo "$(GREEN)deleted push_swap$(RESET)" || true

cleanlib: hl_libft
	@if [ -n "$(wildcard libft/bin/*.o)" ]; then \
		make clean -C libft --no-print-directory; \
		echo "$(GREEN)deleted object files$(RESET)"; \
	elif [ ! -n "$(wildcard libft/bin/*.o)" ] && [ -e libft/libft.a ]; then \
		echo "$(YELLOW)there are no object files$(RESET)"; \
	fi

fcleanlib: hl_libft
	@test -e libft/libft.a &&\
	make fclean -C libft --no-print-directory &&\
	echo "$(GREEN)deleted libft.a$(RESET)" || true

hl_push_swap:
	@echo "------------------------------------------------------"
	@if [ ! -n "$(wildcard bin/*.o)" ] && [ ! -e push_swap ]; then \
		echo "$(HL_CYAN)push_swap:$(RESET)$(YELLOW) nothing to clean$(RESET)"; \
	else \
		echo "$(HL_CYAN)push_swap:$(RESET)"; \
	fi

hl_libft:
	@if [ -n "$(wildcard libft/bin/*.o)" -o -e libft/libft.a ]; then \
		echo "$(HL_CYAN)libft:$(RESET)"; \
	else \
		echo "$(HL_CYAN)libft:$(RESET)$(YELLOW) nothing to clean$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean cleanlib fcleanlib re $(LIBFT_BIN)