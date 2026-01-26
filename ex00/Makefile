GREEN = \033[3;32m
YELLOW = \033[3;33m
MAGENTA = \033[3;35m
CYAN = \033[3;36m
NC = \033[0m

CPP = c++ 

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRC = megaphone.cpp

# OBJECTDIR := object_files
# OBJ = $(addprefix $(OBJECTDIR)/, $(SRC:.c=.o))

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(MAGENTA)Building $(NAME)...$(NC)"
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(MAGENTA)Build complete.$(NC)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS)  -c $< -o $@



clean:
	rm -rf $(OBJ)
	@echo "$(CYAN)Clean is done.$(NC)"


fclean: 
	rm -rf $(OBJ)
	rm -rf $(NAME)
	@echo "$(CYAN)fClean is done.$(NC)"

re: fclean all


.PHONY: all clean fclean re