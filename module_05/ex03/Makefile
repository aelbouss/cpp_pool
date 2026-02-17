CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

TARGET = Forms_Factory

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = $(wildcard *.hpp)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re : fclean all

.SECONDARY: $(OBJS)
.PHONY: clean re all fclean