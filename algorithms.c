#include "algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool horizontal_line(FILE *ptr, int32_t *width, int32_t *height) {
	int32_t desired_length = *width / 4;
	printf("%i\n", desired_length);
	// iterate over scanlines
	for (int i = 0; i < height; i++) {
		// iterate over pixels
		for (int j = 0; j < width; j++) {
			RGBTRIPLE triple;
			// randomize RGB values
			triple.blue = (rand() % 256);
			triple.green = (rand() % 256);
			triple.red = (rand() % 256);

			// write to outfile
			fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
		}

		// add padding
		for (int k = 0; k < padding; k++) {
			fputc(0x00, outptr);
		}
	}
	return false;
}