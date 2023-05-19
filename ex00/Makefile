# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/07/07 17:49:38 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/10/27 11:30:15 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include makerc/common.mk
include makerc/config.mk

NAME			:=ClapTrap.out

# **************************************************************************** #

all: $(NAME)
.PHONY: all

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(GREEN_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(BUILD_DIR)
.PHONY: clean

fclean: clean
	@$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

debug:
	@$(MAKE) DEBUG=1
.PHONY: debug

rebug: fclean debug
.PHONY: rebug

fsan:
	@$(MAKE) FSAN=1
.PHONY: fsan

resan: fclean fsan
.PHONY: resan

bonus: all
.PHONY: bonus

# **************************************************************************** #
