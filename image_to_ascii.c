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

	gray_image.data = malloc(gray_img_size);
	if (gray_image.data == NULL)
	{
		printf("\n--An error occurred--\n\n");
		return (image);
	}

	for (unsigned char *p = image.data, *pg = gray_image.data; p != image.data + img_size; p += image.channels, pg += gray_image.channels)
	{
		*pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
		if (image.channels == 4)
		{
			*(pg + 1) = *(p + 3);
		}
	}
	stbi_image_free(image.data);
	return (gray_image);
}

t_image		resize_image(t_image image, int resize_factor)
{
	t_image	new_image;

	resize_factor <= 0 ? resize_factor = 1 : 1;
	new_image.width = (image.width / resize_factor);
	new_image.height = (image.height / resize_factor);
	new_image.channels = image.channels;
	new_image.data = (unsigned char *)malloc((new_image.width * new_image.height * new_image.channels) * sizeof(unsigned char));

	if (new_image.data == NULL)
	{
		printf("\n--An error occurred--\n\n");
		return (image);
	}

	stbir_resize_uint8(image.data, image.width, image.height, 0, new_image.data, new_image.width, new_image.height, 0, image.channels);

	stbi_image_free(image.data);
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
				char_index = (int)(*(image.data) / (255 / 10));
				char_index > 9 ? char_index = 9 : 1;
				char_index < 0 ? char_index = 0 : 1;
				fprintf(fptr, "%c", map[char_index]);
				image.data++;
			}
			fprintf(fptr, "%c", '\n');
			percentage = round((y + 1) / (image.height / 100.0));
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

	if (input == NULL)
	{
		printf("\n--An error occurred--\n\n");
		return "";
	}

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
		printf("\n--Invalid input--\n\n");
		free(input);
		return (handle_user_input(message, possible_inputs, size));
	}
}

char		*handle_int_user_input(char *message, int min, int max, int size)
{
	char	*input;
	int		input_int;

	input = handle_user_input(message, (char[11]){'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}, size);
	input_int = atoi(input);
	if (input_int > max)
	{
		printf("\n--Invalid input--\n\n");
		return (handle_int_user_input(message, min, max, size));
	}
	else if (input_int < min)
	{
		printf("\n--Invalid input--\n\n");
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
	char	*resize_factor;
	char	*use_stored_path;
	char	*store_path;
	t_image image;

	image_path = (char *)malloc(261 * sizeof(char));
	if (image_path == NULL)
	{
		printf("\n--An error occurred--\n\n");
		return (0);
	}
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
			use_stored_path = handle_user_input("Use stored path? [y/n]: ", (char[3]){'y', 'n', '\0'}, 3);
		}

		if (use_stored_path[0] == 'n' || !image_path[0])
		{
			printf("\n\nEnter image path: ");
			fgets(image_path, 261, stdin);
			strtok(image_path, "\n");
		}
	}

	if (image_path[0])
	{
		image.data = stbi_load(image_path, &image.width, &image.height, &image.channels, 0);
		if (image.data != NULL)
		{
			printf("\n\nImage loaded with success.\n\n\n");
			if (use_stored_path[0] == 'n')
			{
				store_path = handle_user_input("Store path? [y/n]: ", (char[3]){'y', 'n', '\0'}, 3);
				store_path[0] == 'y' ? store_image_path(image_path) : 1;
				printf("\n\n");
				free(store_path);
			}

			resize_factor = handle_int_user_input("Enter image resize factor: [1 - 10] ", 1, 10, 12);

			printf("\n\nPreparing image...\n");
			image = resize_image(image, atoi(resize_factor));
			free(resize_factor);
			image = gray_image(image);
			printf("Image ready.\n\n");

			printf("Converting image to ASCII...\n");
			convert_to_ascii(image);
			printf("Image successfully converted to ASCII.\n\n");
		}
		else
		{
			printf("\n--Could not open specified image--\n\n");
		}

		stbi_image_free(image.data);
	}
	else
	{
		printf("\n--Invalid path--\n\n");
	}

	free(use_stored_path);
	free(image_path);
	return (0);
}