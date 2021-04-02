/* ******************************** */
/* Author: Brhaka                   */
/*                                  */
/*                                  */
/*  github.com/brhaka/ImageToASCII  */
/* ******************************** */

#ifndef IMAGE_TO_ASCII_H
# define IMAGE_TO_ASCII_H

typedef struct	s_image
{
	unsigned char	*img;
	int				width;
	int				height;
	int				channels;
}				t_image;

#define COLOR_RED		"\x1B[31m"
#define COLOR_GREEN		"\x1B[32m"
#define COLOR_YELLOW	"\x1B[33m"
#define COLOR_BLUE		"\x1B[34m"
#define COLOR_MAGENTA	"\x1B[35m"
#define COLOR_CYAN		"\x1B[36m"
#define COLOR_WHITE		"\x1B[37m"
#define COLOR_BLACK		"\x1B[30m"
#define COLOR_RESET		"\x1B[0m"

#define ERROR_UNDEFINED COLOR_RED "\nAn error occurred.\n" COLOR_RESET
#define ERROR_INVALID_INPUT COLOR_RED "\nInvalid input\n" COLOR_RESET
#define ERROR_INVALID_PATH COLOR_RED "\nInvalid path.\n" COLOR_RESET
#define ERROR_OPEN_IMAGE COLOR_RED "\nCould not open specified image.\n" COLOR_RESET

#endif
