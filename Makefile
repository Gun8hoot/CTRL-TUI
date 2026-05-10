NAME		=	ctrl-tui

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -g -I. -std=c++11
SRCS_DIR	=	sources
OBJS_DIR	=	objects
SRCS		=	$(SRCS_DIR)/main.cpp\
				$(SRCS_DIR)/classes/termManager.cpp\
				$(SRCS_DIR)/drawing/draw.cpp

OBJS		=	$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@printf "[+] Compiling $<\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

re:	fclean all

clean:
	@printf "[!] Removing '$(OBJS)'\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "[!] Removing '$(NAME)'\n"
	@rm -f $(NAME)

.PHONY: all fclean re clean
