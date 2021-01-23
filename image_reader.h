#ifndef IMAGE_READER_H
# define IMAGE_READER_H

typedef struct	s_pixel
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}				t_pixel;

typedef struct	s_image
{
	unsigned char	*img;
	int				width;
	int				height;
	int				channels;
}				t_image;

#endif