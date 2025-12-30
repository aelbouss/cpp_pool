CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra -g
STD = -std=c++98

SRCS = main.cpp  Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp AAnimal.cpp Animal.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS =  Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp AAnimal.hpp Animal.hpp

TARGET = Abstract_Class
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