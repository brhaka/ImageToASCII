SRCS = ./image_to_ascii.c
NAME = ImageToASCII

all:	UNIX

$(NAME):	UNIX

UNIX:
	gcc $(SRCS) -lm -D OS=0 -o $(NAME)

unix:	UNIX

WIN:
	gcc $(SRCS) -lm -D OS=1 -o $(NAME)

win:	WIN

clean:
	rm -f $(NAME)

re:		clean all

.PHONY:	re clean all UNIX unix WIN win
