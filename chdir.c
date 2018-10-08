#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void p_error(char* curr, char* changes)
{
	fprintf(stderr, "Cannot change dir: %s to %s \n %s", curr, changes, strerror(errno));
	exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
	errno = 0;
	if(argc==2)
	{
		if(chdir(argv[1]))
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			p_error(cwd, argv[1]);
		}
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("%s now\n", cwd);
	}
	return 0;
}