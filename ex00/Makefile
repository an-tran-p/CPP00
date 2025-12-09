# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 11:16:10 by atran             #+#    #+#              #
#    Updated: 2025/12/09 11:32:08 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp /

OBJS = $(SRCS:%.cpp=%.o)

C++ = c++

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(OBJS): %.o: %.cpp
	$(C++) $(FLAGS) -cpp $< -o $@

$(NAME) : $(OBJS)
	c++ $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re