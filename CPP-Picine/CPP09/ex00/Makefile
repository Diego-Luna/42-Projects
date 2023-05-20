# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:34:29 by dluna-lo          #+#    #+#              #
#    Updated: 2023/05/20 18:23:43 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = btc
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
AUTHOR  = dluna-lo

SRCS    = src/main.cpp src/BitcoinExchange.cpp
SRCDIR  = src/

RM 			= rm -f
OBJDIR  = obj/
OBJS    = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
