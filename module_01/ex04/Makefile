CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98
TARGET = costume_sed

SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJS = $(SRCS:%.cpp=%.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(TARGET)
re : fclean
	$(MAKE) all

.SECONDARY : $(OBJS)
.PHONY : re clean fclean all
