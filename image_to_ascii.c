/* ******************************** */
/* Author: Brhaka                   */
/*                                  */
/*                                  */
/*  github.com/brhaka/ImageToASCII  */
/* ******************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "image_to_ascii.h"
#include "colors.h"
#include "errors.h"

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

	gray_image.img = (unsigned char *)malloc(gray_img_size);
	if (gray_image.img == NULL)
	{
		printf(ERROR_UNDEFINED);
		return (image);
	}

	for (unsigned char *p = image.img, *pg = gray_image.img; p != image.img + img_size; p += image.channels, pg += gray_image.channels)
	{
		*pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
		if (image.channels == 4)
		{
			*(pg + 1) = *(p + 3);
		}
	}
	stbi_image_free(image.img);

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
	if (new_image.img == NULL)
	{
		printf(ERROR_UNDEFINED);
		return (image);
	}

	stbir_resize_uint8(image.img, image.width, image.height, 0, new_image.img, new_image.width, new_image.height, 0, image.channels);

	stbi_image_free(image.img);

	return (new_image);
}

void	convert_to_ascii(t_image image)
{
	FILE	*fptr = NULL;
	int		char_index;
	char	map[11] = "@#%xo;:,. ";
	int		percentage;

	fptr = fopen("ascii.brk", "w");
	if (fptr != NULL)
	{
		for (int y = 0; y < image.height; y++)
		{
			for (int x = 0; x < image.width; x++)
			{
				char_index = (int)(*(image.img) / (255 / (sizeof(map) / sizeof(map[0]))));
				char_index > 9 ? char_index = 9 : 1;
				char_index < 0 ? char_index = 0 : 1;
				fprintf(fptr, "%c%c", map[char_index], map[char_index]);
				image.img++;
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

void	get_stored_image_path(char *image_path)
{
	FILE *fptr = NULL;

	fptr = fopen("path.brk", "r");
	if (fptr != NULL)
	{
		fscanf(fptr, "%s", image_path);
		fclose(fptr);
	}
}

void	store_image_path(char *image_path)
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

char	*handle_user_input(char *message, char *possible_inputs, int size, bool check_input)
{
	char	*input;
	bool	valid_input;

	input = (char *)malloc(size * sizeof(char));
	if (input == NULL)
	{
		printf(ERROR_UNDEFINED);
		return "";
	}

	printf("%s", message);
	fgets(input, 512, stdin);
	if (input[0] == '\n')
	{
		printf(ERROR_INVALID_INPUT);
		free(input);
		return (handle_user_input(message, possible_inputs, size, check_input));
	}
	strtok(input, "\n");

	if (check_input == true)
	{
		valid_input = false;
		for (int i = 0; input[i] && i < size; i++)
		{
			for (int j = 0; possible_inputs[j]; j++)
			{
				if (input[i] == possible_inputs[j])
				{
					valid_input = true;
				}
			}
		}
	}
	else
	{
		valid_input = true;
	}

	if (valid_input == true)
	{
		return (input);
	}
	else
	{
		printf(ERROR_INVALID_INPUT);
		free(input);
		return (handle_user_input(message, possible_inputs, size, check_input));
	}
}

char	*handle_int_user_input(char *message, int min, int max, int size)
{
	char	*input;
	int		input_int;
	char	possible_inputs[11] = "0123456789";

	input = handle_user_input(message, possible_inputs, size, true);
	input_int = atoi(input);
	if (input_int > max)
	{
		printf(ERROR_INVALID_INPUT);
		return (handle_int_user_input(message, min, max, size));
	}
	else if (input_int < min)
	{
		printf(ERROR_INVALID_INPUT);
		return (handle_int_user_input(message, min, max, size));
	}
	else
	{
		return (input);
	}
}

int		main(int argc, char *argv[])
{
	char	*image_path;
	char	*resize_factor;
	char	*store_path;
	char	*use_stored_path;
	bool	use_strd_path_allctd;
	bool	image_path_ready;
	t_image	image;

	use_strd_path_allctd = false;
	image_path_ready = false;

	if (argc == 2)
	{
		image_path = (char *)malloc(261 * sizeof(char));
		if (image_path == NULL)
		{
			printf(ERROR_UNDEFINED);
			return (0);
		}

		for (int i = 0; argv[1][i]; i++)
		{
			image_path[i] = argv[1][i];
			image_path[i + 1] = '\0';
		}

		image_path_ready = true;
	}
	else
	{
		image_path = (char *)malloc(261 * sizeof(char));
		if (image_path == NULL)
		{
			printf(ERROR_UNDEFINED);
			return (0);
		}
		image_path[0] = '\0';

		get_stored_image_path(image_path);

		if (image_path[0])
		{
			image_path_ready = true;

			char	possible_inputs[3] = "yn";
			use_stored_path = handle_user_input(COLOR_CYAN "Use stored path?" COLOR_RESET " [y/n]: " COLOR_YELLOW, possible_inputs, 1, true);
			use_strd_path_allctd = true;
		}

		if ((use_strd_path_allctd == true && use_stored_path[0] == 'n') || image_path_ready == false)
		{
			use_strd_path_allctd == true ? printf("\n\n") : 1;
			free(image_path);
			image_path = handle_user_input(COLOR_CYAN "Enter image path: " COLOR_YELLOW, "", 512, false);
			image_path_ready = true;
		}
	}

	if (image_path_ready == true)
	{
		printf(COLOR_CYAN "\n\nLoading image...\n" COLOR_RESET);
		printf(COLOR_RESET "\r[ %d%% ]", 0);
		fflush(stdout);
		image.img = stbi_load(image_path, &image.width, &image.height, &image.channels, 0);
		if (image.img != NULL)
		{
			printf(COLOR_RESET "\r[ %d%% ]", 100);
			printf(COLOR_GREEN "\nImage loaded with success.\n\n\n" COLOR_RESET);
			if (use_strd_path_allctd == false || (use_strd_path_allctd == true && use_stored_path[0] != 'y'))
			{
				char	possible_inputs[3] = "yn";
				store_path = handle_user_input(COLOR_CYAN "Store path?" COLOR_RESET " [y/n]: " COLOR_YELLOW, possible_inputs, 1, true);
				store_path[0] == 'y' ? store_image_path(image_path) : (void)1;
				printf("\n\n");
				free(store_path);
			}

			resize_factor = handle_int_user_input(COLOR_CYAN "Enter image resize factor:" COLOR_RESET " [1 - 50] " COLOR_YELLOW, 1, 50, 2);

			printf(COLOR_CYAN "\n\nPreparing image...\n" COLOR_RESET);
			printf(COLOR_RESET "\r[ %d%% ]", 0);
			fflush(stdout);
			image = resize_image(image, atoi(resize_factor));
			printf(COLOR_RESET "\r[ %d%% ]", 50);
			fflush(stdout);
			free(resize_factor);
			image = gray_image(image);
			printf(COLOR_RESET "\r[ %d%% ]", 100);
			printf(COLOR_GREEN "\nImage ready.\n\n" COLOR_RESET);

			printf(COLOR_CYAN "Converting image to ASCII...\n" COLOR_RESET);
			convert_to_ascii(image);
			printf(COLOR_GREEN "Image successfully converted to ASCII.\n\n" COLOR_RESET);
		}
		else
		{
			printf(ERROR_OPEN_IMAGE);
		}

		stbi_image_free(image.img);
	}
	else
	{
		printf(ERROR_INVALID_PATH);
	}

	use_strd_path_allctd == true ? free(use_stored_path) : (void)1;
	image_path_ready == true ? free(image_path) : (void)1;

	return (0);
}
