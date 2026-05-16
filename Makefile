NAME		=	ctrl-tui

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -g -I. -std=c++11 -O2
SRCS_DIR	=	sources
OBJS_DIR	=	objects
SRCS		=	$(SRCS_DIR)/main.cpp\
				$(SRCS_DIR)/frames/main_menu.cpp\
				$(SRCS_DIR)/classes/termManager.cpp\
				$(SRCS_DIR)/render/draw.cpp\
				$(SRCS_DIR)/render/render_thread.cpp\
				$(SRCS_DIR)/struct/render.cpp\
				$(SRCS_DIR)/struct/tui.cpp

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
