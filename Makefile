SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	$(NAME)

$(NAME):
	gcc $(SRCS) -lm -o $(NAME)

clean:
	rm -f $(NAME)

re:		clean all

.PHONY:	re clean all
