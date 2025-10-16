CPPC = C++;
CPPFLAGS = -Wall -Werror -Wextra
STD = -std=c++98
TARGET = megaphone

CPPSRCS = megaphone.cpp
OBJS = $(CPPSRCS= %.cpp=%.o)

all : $(TARGET)

target: $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)
%.o: %.cpp
	$(CPPC) $(CPPFLAGS) $(STD) $^ -o $@
clean: 
	rm -rf $(OBJS)
fclean: $(clean)
	rm -rf $(TARGET)
re: $(fclean)
	$(MAKE) all
.SECONDARY : $(OBJS)
