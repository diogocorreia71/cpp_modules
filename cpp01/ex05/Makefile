# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:15:06 by diodos-s          #+#    #+#              #
#    Updated: 2024/09/09 14:15:22 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Harl.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = Harl_2.0
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