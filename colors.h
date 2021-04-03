/* ******************************** */
/* Author: Brhaka                   */
/*                                  */
/*                                  */
/*  github.com/brhaka/ImageToASCII  */
/* ******************************** */

#ifndef COLORS_H
# define COLORS_H

# ifndef USE_COLORS
#  define USE_COLORS 1
# endif

# if USE_COLORS == 1

#  define COLOR_RED		"\x1B[31m"
#  define COLOR_GREEN	"\x1B[32m"
#  define COLOR_YELLOW	"\x1B[33m"
#  define COLOR_BLUE	"\x1B[34m"
#  define COLOR_MAGENTA	"\x1B[35m"
#  define COLOR_CYAN	"\x1B[36m"
#  define COLOR_WHITE	"\x1B[37m"
#  define COLOR_BLACK	"\x1B[30m"
#  define COLOR_RESET	"\x1B[0m"

# else

#  define COLOR_RED		""
#  define COLOR_GREEN	""
#  define COLOR_YELLOW	""
#  define COLOR_BLUE	""
#  define COLOR_MAGENTA	""
#  define COLOR_CYAN	""
#  define COLOR_WHITE	""
#  define COLOR_BLACK	""
#  define COLOR_RESET	""

# endif

#endif
