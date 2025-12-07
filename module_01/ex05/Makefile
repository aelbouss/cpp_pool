CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
HEADER = $(wildcard *.hpp)
TARGET = Harl

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp $(HEADER)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean :
	rm -rf  $(OBJS)

fclean : clean
	rm -rf  $(TARGET)

re : fclean
	$(MAKE) all

.SECONDARY: $(OBJS) 
.PHONY: re all clean fclean