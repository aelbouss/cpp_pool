CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
TARGET = violenece_

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp 
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf  $(TARGET)

re : fclean
	$(MAKE) all

.SECONDARY: $(OBJS)
.PHONY : re clean all fclean