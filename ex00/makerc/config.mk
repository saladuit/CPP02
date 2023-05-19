# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    config.mk                                       |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/07/16 21:50:54 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/10/27 11:29:59 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC				:=c++

#	Remove	command
RM				:=rm -rfv

#	Compiler flags
CFLAGS			=-Wall -Wextra -Werror -Wpedantic -std=c++98 $(if $(FSAN), -g -fsanitize=address)$(if $(DEBUG), -g)


SRCS			=Fixed.cpp
MAIN 			:=main.cpp

#	Directories
SRC_DIR			:=src
INCLUDE_DIR		:=include
BUILD_DIR		:=build
LIB_DIR			:=libs


# 	Objects
OBJS			=$(addprefix $(BUILD_DIR)/, $(SRCS:%.cpp=%.o))
MAIN_OBJ		=$(addprefix $(BUILD_DIR)/, $(MAIN:%.cpp=%.o))

HEADERS			=$(INCLUDE_DIR)/Fixed.hpp

INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(HEADERS))))

#	Flags
ifdef	DEBUG
	CFLAGS					+=-g
endif

ifdef	LOG
	CFLAGS					+=-D LOG=1
endif

ifdef	FSAN
	CFLAGS					+=-fsanitize=address,undefined
endif

ifdef	TEST
	LDFLAGS					+=-lcriterion
endif

ifdef	COV
	CFLAGS					+=--coverage
endif
