SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	$(NAME)

$(NAME):
	gcc $(SRCS) -lm -D OS=0 -o $(NAME)

WIN:
	gcc $(SRCS) -lm -D OS=1 -o $(NAME)

clean:
	rm -f $(NAME)

re:		clean all

.PHONY:	re clean all WIN
