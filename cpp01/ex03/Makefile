# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 12:14:46 by diodos-s          #+#    #+#              #
#    Updated: 2024/09/09 12:15:18 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = UnnecessaryViolence
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