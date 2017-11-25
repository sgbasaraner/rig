#include "algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool compare_triples(RGBTRIPLE *t1, RGBTRIPLE *t2) {
	if ((t1 -> blue == t2 -> blue) && (t1 -> green == t2 -> green) && (t1 -> red == t2 -> red)) {
		return true;
	} else {
		return false;
	}
}

bool horizontal_line(FILE *ptr, int32_t *width, int32_t *height, int *padding) {
	int32_t desired_length = *width / 4;
	int32_t tmp = 0;
	printf("%i\n", desired_length);
	// iterate over scanlines
	for (int i = 0; i < *height; i++) {
		// iterate over pixels
		for (int j = 0; j < *width - 1; j++) {
			RGBTRIPLE triple1;
			RGBTRIPLE triple2;

			// read RGB triple
			fread(&triple1, sizeof(RGBTRIPLE), 1, ptr);
			fread(&triple2, sizeof(RGBTRIPLE), 1, ptr);

			if (compare_triples(&triple1, &triple2)) {
				tmp++;
			}

			// check if the condition is met
			if (tmp >= desired_length) {
				return true;
			}
		}

		// add padding
		fseek(ptr, *padding, SEEK_CUR); 

		// reset tmp to count again
		tmp = 0;
	}
	return false;
}