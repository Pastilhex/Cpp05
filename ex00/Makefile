NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
FLAGSCXX = -Wall -Werror -Wextra -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGSCXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGSCXX) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re