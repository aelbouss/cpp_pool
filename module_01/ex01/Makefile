CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98


TARGET = MoreBrainzzz
SRCS =  main.cpp Zombie.cpp zombieHorde.cpp Zombie.hpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = Zombie.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf  $(TARGET)
re : fclean
	$(MAKE) all

.SECONDARY : $(OBJS)
.PHONY : clean fclean re all