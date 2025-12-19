CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADER = Fixed.hpp

TARGET = My_First_Orthodox_Canonical_Form

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