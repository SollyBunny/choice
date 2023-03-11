#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// This is used instead of (s)rand because using srand(time(NULL)) will result in the same seed if in the same second
unsigned char randomchar() {
	int fd = open("/dev/random", O_RDONLY);
	unsigned char out;
	read(fd, &out, sizeof(out));
	close(fd);
	return out;
}

int main(int argc, char *argv[]) {
	// Make sure there are enough arguments
	if (argc <= 1)
		return 1;
	unsigned char index;
	if (argc == 2) // if there is only 2 arguments then no choice must be made
		index = 2;
	else
		index = (randomchar() % (argc - 1)) + 1; // this will only handle ~253 arguments, too bad!
	printf("%s\n", argv[index]);
	return index;
}
