#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// This is used instead of (s)rand because using srand(time(NULL)) will result in the same seed if in the same second
int randomint() {
	int fd = open("/dev/urandom", O_RDONLY);
	int out;
	read(fd, &out, sizeof(int));
	if (out < 0) out = 0 - out;
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
		index = (randomint() % (argc - 1)) + 1;
	printf("%s\n", argv[index]);
	return index;
}
