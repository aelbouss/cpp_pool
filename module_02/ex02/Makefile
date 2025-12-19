CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = Fixed.cpp arithmetics.cpp comparison.cpp increments_decrements.cpp  main.cpp overloaded_functions.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADER = Fixed.hpp

TARGET = More_fixed_point

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