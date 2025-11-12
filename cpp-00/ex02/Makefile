TARGET = bank
CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra 
STD = std = -std=c++98
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS: %.cpp=%.o)

all : $(TARGET)

TARGET : $(OBJS)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJS) -o $(TARGET)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) $(STD)  -c $< -o $@

clean : 
	rm - rf $(OBJS)
flcean : clean
	rm -rf  $(TARGET)
re : fclean
	$(MAKE) all

.SECONDARY : $(OBJS)
	
