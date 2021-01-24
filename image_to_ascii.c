#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "image_to_ascii.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

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

	for (unsigned char *p = image.img, *pg = gray_image.img; p != image.img + img_size; p += image.channels, pg += gray_image.channels)
	{
		*pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3);
		if (image.channels == 4)
		{
			*(pg + 1) = *(p + 3);
		}
	}

	return (gray_image);
}

t_image		resize_image(t_image image, int resize_factor)
{
	t_image	new_image;

	resize_factor <= 0 ? resize_factor = 1 : 1;
	new_image.width = (image.width / resize_factor);
	new_image.height = (image.height / resize_factor);
	new_image.channels = image.channels;
	new_image.img = (unsigned char *)malloc((new_image.width * new_image.height * new_image.channels) * sizeof(unsigned char));
	stbir_resize_uint8(image.img, image.width, image.height, 0, new_image.img, new_image.width, new_image.height, 0, image.channels);
	return (new_image);
}

void		convert_to_ascii(t_image image)
{
	FILE	*fptr = NULL;
	int		char_index;
	char	map[10] = "@#%xo;:,. ";
	int		percentage;

	fptr = fopen("ascii.txt", "w");
	if (fptr != NULL)
	{
		for (int y = 0; y < image.height; y++)
		{
			for (int x = 0; x < image.width; x++)
			{
				char_index = (int)(*(image.img) / (255 / 10));
				char_index > 9 ? char_index = 9 : 1;
				char_index < 0 ? char_index = 0 : 1;
				fprintf(fptr, "%c", map[char_index]);
				image.img++;
			}
			fprintf(fptr, "%c", '\n');
			percentage = round((y + 1) / (image.height / 100));
			percentage < 0 ? percentage = 0 : 1;
			percentage > 100 ? percentage = 100 : 1;
			printf("\r[ %d%% ]", percentage);
			fflush(stdout);
		}
		printf("\n");
		fclose(fptr);
	}
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

char		*handle_user_input(char *message, char *possible_inputs, int size)
{
	char	*input;
	bool	valid_input;

	input = (char *)malloc(size * sizeof(char));

	printf("%s", message);
	fgets(input, size, stdin);

	valid_input = false;
	for (int i = 0; input[i]; i++)
	{
		for (int j = 0; possible_inputs[j]; j++)
		{
			if (input[i] == possible_inputs[j])
			{
				valid_input = true;
			}
		}
	}

	if (valid_input == true)
	{
		strtok(input, "\n");
		return (input);
	}
	else
	{
		printf("Invalid input.\n");
		return (handle_user_input(message, possible_inputs, size));
	}
}

char		*handle_int_user_input(char *message, int min, int max, int size)
{
	char *input;

	input = handle_user_input(message, (char[10]){'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, size);
	if (atoi(input) > max)
	{
		printf("Invalid input.\n");
		return (handle_int_user_input(message, min, max, size));
	}
	else if (atoi(input) < min)
	{
		printf("Invalid input.\n");
		return (handle_int_user_input(message, min, max, size));
	}
	else
	{
		return (input);
	}
}

int			main(int argc, char *argv[])
{
	char	*image_path;
	char	*use_stored_path;
	char	*resize_factor;
	t_image image;

	resize_factor = (char *)malloc(12 * sizeof(char));
	use_stored_path = (char *)malloc(3 * sizeof(char));
	image_path = (char *)malloc(261 * sizeof(char));
	image_path[0] = '\0';

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
		get_stored_image_path(image_path);

		if (image_path[0])
		{
			use_stored_path = handle_user_input("Use stored path? [y/n]: ", (char[2]){'y', 'n'}, 3);
		}

		if (use_stored_path[0] == 'n' || !image_path[0])
		{
			printf("Enter image path: ");
			fgets(image_path, 261, stdin);
			strtok(image_path, "\n");
		}
	}

	if (image_path[0])
	{
		image.img = stbi_load(image_path, &image.width, &image.height, &image.channels, 0);
		if (image.img != NULL)
		{
			printf("\nImage loaded with success.\n\n");
			store_image_path(image_path);

			resize_factor = handle_int_user_input("Enter image resize factor: [1 - 10] ", 1, 10, 12);

			printf("\n\nPreparing image...\n");
			image = resize_image(image, atoi(resize_factor));
			image = gray_image(image);
			printf("Image ready.\n\n");

			printf("Converting image to ASCII...\n");
			convert_to_ascii(image);
			printf("Image successfully converted to ASCII.\n\n");
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