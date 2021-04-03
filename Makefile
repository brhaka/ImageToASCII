SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	UNIX WIN

$(NAME):	UNIX WIN

UNIX:
	gcc $(SRCS) -static -lm -o $(NAME)

WIN:
	i686-w64-mingw32-g++ $(SRCS) --static -o $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(NAME).exe

re:		clean $(NAME)

.PHONY:	re clean UNIX WIN all
