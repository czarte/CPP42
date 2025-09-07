SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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
		$(RM) shrubery

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re