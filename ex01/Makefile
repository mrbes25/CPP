# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 22:03:15 by bschmid           #+#    #+#              #
#    Updated: 2025/06/24 10:33:37 by bschmid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= phonebook.cpp
OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f

all:		$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re