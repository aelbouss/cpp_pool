CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

TARGET = Polymorphism
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