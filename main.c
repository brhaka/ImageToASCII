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

void		get_stored_image_path(char image_path[])
{
	FILE	*fptr = NULL;

	fptr = fopen("path.brk", "r");
	if (fptr != NULL)
	{
		fscanf(fptr, "%s", image_path);
		fclose(fptr);
	}
}

void		store_image_path(char image_path[])
{
	FILE *fptr = NULL;

	fptr = fopen("path.brk", "w");
	if (fptr != NULL)
	{
		for (int i = 0; image_path[i]; i++)
		{
			fprintf(fptr, "%c", image_path[i]);
		}
		fprintf(fptr, "%c", '\n');
		fclose(fptr);
	}
}

int			main(int argc, char *argv[])
{
	char	*image_path;
	char	*use_stored_path;
	t_image image;

	use_stored_path = (char *)malloc(3 * sizeof(char));
	image_path = (char *)malloc(261 * sizeof(char)); // 260 (max path size) + 1 (\0)
	image_path[0] = '\0';
	get_stored_image_path(image_path);

	if (image_path[0])
	{
		printf("Use stored path? [y/n]: ");
		fgets(use_stored_path, 3, stdin);
	}

	if (use_stored_path[0] == 'n' || !image_path[0])
	{
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
			printf("Enter image path: ");
			fgets(image_path, 261, stdin);
			strtok(image_path, "\n"); // Removes \n from user input (enter)
		}
	}

	if (image_path[0])
	{
		image.img = stbi_load(image_path, &image.width, &image.height, &image.channels, 0);
		if (image.img != NULL)
		{
			printf("\nImage loaded with success.\n\n");
			store_image_path(image_path);

			printf("Updating image channels...\n");
			image = gray_image(image);
			printf("Image channels updated.\n\n");

			printf("Saving image...\n");
			stbi_write_jpg("gray.jpg", image.width, image.height, image.channels, image.img, 100);
			printf("Image saved.\n\n");
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