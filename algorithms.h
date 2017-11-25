#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stdbool.h>
#include <stdio.h>
#include "bmp.h"

bool horizontal_line(FILE *ptr, int32_t *width, int32_t *height, int *padding);
bool compare_triples(RGBTRIPLE *t1, RGBTRIPLE *t2);
#endif