#ifndef IMAGE_READER_H
# define IMAGE_READER_H

typedef struct	s_image
{
	unsigned char	*data;
	int				width;
	int				height;
	int				channels;
}				t_image;

#endif