#include <stdio.h>
#include <stdlib.h>

#include "image_reader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

t_image		gray_image(t_image image)
{
	t_image gray_image = image;

	size_t img_size = image.width * image.height * image.channels;
	gray_image.channels = image.channels == 4 ? 2 : 1;
	size_t gray_img_size = image.width * image.height * gray_image.channels;

	gray_image.img = malloc(gray_img_size);
	if (gray_image.img == NULL)
	{
		printf("Unable to allocate memory for gray image.\n");
		return (image);
	}

	for (unsigned char *p = image.img, *pg = gray_image.img; p != image.img + img_size; p += image.channels, pg += gray_image.channels) // P = pixel, PG = pixel gray
	{
		*pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3); // P = red, P + 1 = green, P + 2 = blue
		if (image.channels == 4)
		{
			*(pg + 1) = *(p + 3);
		}
	}

	return (gray_image);
}

int			main(int argc, char *argv[])
{
	char	image_path[261]; // 260 (max path size) + 1 (\0)
	t_image image;

	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i++)
		{
			image_path[i] = argv[1][i];
			image_path[i + 1] = '\0';
		}
	}
	else
	{
		printf("Enter image path:");
		fgets(image_path, 260, stdin);
	}


	if (image_path[0])
	{
		strtok(image_path, "\n"); // Removes \n from user input (enter)

		image.img = stbi_load(image_path, &image.width, &image.height, &image.channels, 0);
		if (image.img != NULL)
		{
			printf("Image loaded with success.\n");
			image = gray_image(image);
			stbi_write_jpg("gray.jpg", image.width, image.height, image.channels, image.img, 100);
		}
		else
		{
			printf("Could not open specified image.\n");
		}

		stbi_image_free(image.img);
	}
	else
	{
		printf("Invalid path.\n");
		return (0);
	}

	return (0);
}