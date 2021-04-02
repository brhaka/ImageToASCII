SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	$(NAME)

$(NAME):
	gcc $(SRCS) -lm -o $(NAME)

WIN:
	i686-w64-mingw32-g++ $(SRCS) --static -o $(NAME)

clean:
	rm -f $(NAME)

re:		clean all

.PHONY:	re clean all WIN
