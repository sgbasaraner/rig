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
	int16_t width = atoi(argv[1]);
	int16_t height = atoi(argv[2]);

	// check for conversion errors and invalid entry
	if ((width == 0) || (height == 0)) {
		printf("Invalid entry\n");
		return 2;
	}

	// remember outfile
	char *outfile = argv[3];
}