SRC = Bureaucrat.cpp main.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -v $(CPPFLAGS) $(OBJ) -v -o $(NAME)

#%.o: %.cpp
#		$(CC) -c -o $< $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re