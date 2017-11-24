#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// ensure proper usage
	if (argc != 4){
		printf("Usage: ./rig width height outfile\n");
		return 1;
	}

	printf("W: %s, H: %s\n", argv[1], argv[2]);

	// remember width and height
	int32_t width = atoi(argv[1]);
	int32_t height = atoi(argv[2]);

	// check for conversion errors and invalid entry
	if ((width == 0) || (height == 0)) {
		printf("Invalid entry\n");
		return 2;
	}

	// remember outfile
	char *outfile = argv[3];

	// calculate padding
	int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

	// create BITMAPINFOHEADER
	BITMAPINFOHEADER bih;
	bih.size = 40;
	bih.width = width;
	bih.height = height - (2 * height);
	bih.planes = 1;
	bih.bitCount = 24;
	bih.compression = 0;
	bih.sizeImage = (width * sizeof(RGBTRIPLE) + padding) * height;
	bih.clrUsed = 0;
	bih.clrImportant = 0;
	bih.xPelsPerMeter = 2834;
	bih.yPelsPerMeter = 2834;

	// create BITMAPFILEHEADER
	BITMAPFILEHEADER bfh;
	bfh.type = 0x4d42;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offBits = 54;
	bfh.size = bih.sizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
}