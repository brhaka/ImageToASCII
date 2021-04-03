SRCS := ./image_to_ascii.c
NAME := ImageToASCII
USE_COLORS = 1

all:	UNIX WIN

$(NAME):	UNIX WIN

UNIX:
	gcc $(SRCS) -static -lm -D USE_COLORS=$(USE_COLORS) -o $(NAME)

WIN:
	i686-w64-mingw32-g++ $(SRCS) --static -D USE_COLORS=$(USE_COLORS) -o $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(NAME).exe

re:		clean $(NAME)

.PHONY:	re clean WIN UNIX all
