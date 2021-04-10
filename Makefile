# ******************************** #
# Author: Brhaka                   #
#                                  #
#                                  #
#  github.com/brhaka/ImageToASCII  #
# ******************************** #

SRCS := ./image_to_ascii.c
NAME := ImageToASCII
USE_COLORS = 1

all:	LINUX MACOS WIN

$(NAME):	LINUX MACOS WIN

LINUX:
	gcc $(SRCS) -static -lm -D USE_COLORS=$(USE_COLORS) -o $(NAME)-Linux

MACOS:
	gcc $(SRCS) -lm -D USE_COLORS=$(USE_COLORS) -o $(NAME)-MacOS

WIN:
	i686-w64-mingw32-g++ $(SRCS) --static -D USE_COLORS=$(USE_COLORS) -o $(NAME)-Windows_x86_x64

clean:
	rm -f $(NAME)-Linux
	rm -f $(NAME)-MacOS
	rm -f $(NAME)-Windows_x86_x64.exe

re:		clean $(NAME)

.PHONY:	re clean WIN MACOS LINUX all
