TARGET = bank
CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra 
STD = -std=c++98

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:%.cpp=%.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)
	./$(TARGET) > out.log

%.o : %.cpp
	$(CPPC) $(CPPFLAGS) $(STD)  -c $< -o $@

clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf  $(TARGET)
re : fclean
	$(MAKE) all

.SECONDARY : $(OBJS)