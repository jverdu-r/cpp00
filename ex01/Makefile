# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:52:39 by jverdu-r          #+#    #+#              #
#    Updated: 2024/05/16 16:34:49 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address -g3

TARGET = phonebook

SRC = src/phonebook.cpp src/contact.cpp main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf $(TARGET)
