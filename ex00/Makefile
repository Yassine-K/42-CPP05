NAME = Bureaucrat

SRC = Bureaucrat.cpp main.cpp

OBJ = ${SRC:.cpp=.o}

WWW = -Wall -Wextra -Werror

SUP = -std=c++98

%.o: %.cpp
	@c++ ${WWW} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@c++ $^ -o $@ ${SUP}

clean:
	@rm -rf ${OBJ}

fclean:
	@rm -rf ${OBJ} ${NAME}

re: fclean all

.PHONY: all clean fclean re