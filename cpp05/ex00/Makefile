# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 09:42:42 by diodos-s          #+#    #+#              #
#    Updated: 2024/10/07 16:46:41 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Bureaucrat.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = a.out
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