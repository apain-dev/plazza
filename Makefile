##
## EPITECH PROJECT, 2018
## cpp_rush2
## File description:
## Makefile
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRCS		=	src/plazza_manager.cpp  \
                src/parser.cpp          \
                src/slave_manager.cpp   \
                src/slave.cpp           \
                src/main.cpp

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	plazza

LDFLAGS    =   -lpthread

CPPFLAGS	+=  -std=c++11 -W -Wall -Wextra -Iinc/

CC		=	g++

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean debug re

.cpp.o:
		@g++ $(CPPFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[ OK ]" $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) "[ XX ]" $(TEAL) $< $(DEFAULT)
