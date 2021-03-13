/* »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» */
/* Author: Brhaka                   */
/*                                  */
/* Project: ImageToASCII            */
/*                                  */
/* File: image_to_ascii.h           */
/*                                  */
/*                                  */
/*  github.com/brhaka/ImageToASCII  */
/* «««««««««««««««««««««««««««««««« */

#ifndef IMAGE_TO_ASCII_H
# define IMAGE_TO_ASCII_H

typedef struct	s_image
{
	unsigned char	*data;
	int				width;
	int				height;
	int				channels;
}				t_image;

#endif
