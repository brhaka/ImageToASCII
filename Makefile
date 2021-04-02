SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	$(NAME)

$(NAME):
	gcc $(SRCS) -static -lm -o $(NAME)

WIN:
	i686-w64-mingw32-g++ $(SRCS) --static -o $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(NAME).exe

re:		clean all

.PHONY:	re clean all WIN
