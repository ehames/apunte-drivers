#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h> /* flags de apertura */

int main(int argc, char **argv)
{
	pid_t fork_id = -1;
	int fid = 0;
	assert(argc==2 && argv[1]);
	fid = open(argv[1], O_RDONLY, 0);
	if (fid < 0) {
		perror("open");
		exit(1);
	}

	if ((fork_id = fork()) < 0) {
		perror("fork()");
		exit(1);
	}

	if (fork_id != 0) {  /* soy el padre */
		sleep(2);
		close(fid);
	} else {  /* soy el hijo */
		sleep(1);
		close(fid);
	}

	return 0;
}
