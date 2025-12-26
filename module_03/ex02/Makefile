CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = main.cpp ClapTrap.cpp FragTrap.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

TARGET = FragTrap

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADER)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean : 
	rm -rf  $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.SECONDARY : $(OBJS)
.PHONY : all re clean fclean