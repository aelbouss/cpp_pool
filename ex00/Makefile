CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98 
TARGET = megaphone

CPPSRCS = megaphone.cpp
OBJS = $(CPPSRCS:%.cpp=%.o)

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: $(fclean)
	$(MAKE) all

.PHONY : all clean fclean re
.SECONDARY : $(OBJS)

