TARGET = Phonebook
CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra 
STD = -std=c++98

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADERS = Contact.hpp PhoneBook.hpp 

all : $(TARGET)

$(TARGET): $(OBJ)
	$(CPPC) $(CPPFLAGS) $(STD) $(OBJ) -o $(TARGET)

%.o : %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(STD) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
.SECONDARY : $(OBJ)


