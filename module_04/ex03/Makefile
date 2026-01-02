CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = AMateria.hpp Character.hpp Ice.hpp Cure.hpp IMateriaSource.hpp ICharacter.hpp  MateriaSource.hpp 

TARGET = Role_Playing_Game
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(STD)  -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.SECONDARY : $(OBJS)
.PHONY : all re clean fclean