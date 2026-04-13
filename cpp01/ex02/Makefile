# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 20:38:33 by mrapp-he          #+#    #+#              #
#    Updated: 2026/04/11 12:05:17 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain
SRCS = src/main.cpp
OBJ_DIR = build
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
CPP = c++
CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $(NAME)
	@echo "Executable created!"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "Build directory deleted!"; \
	else \
		echo "No build directory to delete!"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@echo "Executable deleted!"

re: fclean
	@echo "Recreating build directory..."
	@echo "Remaking executables..."
	@make --no-print-directory

run: re
	@./$(NAME)

val: re
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run val