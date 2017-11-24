#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 3){
		printf("Usage: ./rig width height\n");
		return 1;
	}

	printf("W: %s, H: %s\n", argv[1], argv[2]);
}