# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:12:45 by rwegat            #+#    #+#              #
#    Updated: 2023/11/27 15:25:46 by rwegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

CFILES = get_next_line.c get_next_line_utils.c
OFILES = $(CFILES: .c=.o)

all: $(NAME)
$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re