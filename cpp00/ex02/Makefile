# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:12:09 by diodos-s          #+#    #+#              #
#    Updated: 2024/09/04 11:14:03 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = account
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all