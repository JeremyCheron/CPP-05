# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 09:03:52 by jcheron           #+#    #+#              #
#    Updated: 2025/03/24 09:48:04 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98 -g
SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Bureaucrat.cpp $(SRC_DIR)/Form.cpp $(SRC_DIR)/ShrubberyCreationForm.cpp $(SRC_DIR)/RobotomyRequestForm.cpp $(SRC_DIR)/PresidentialPardonForm.cpp $(SRC_DIR)/Intern.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/Bureaucrat.o $(OBJ_DIR)/Form.o $(OBJ_DIR)/ShrubberyCreationForm.o $(OBJ_DIR)/RobotomyRequestForm.o $(OBJ_DIR)/PresidentialPardonForm.o $(OBJ_DIR)/Intern.o

NAME = ex03

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
