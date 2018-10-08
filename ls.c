#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	struct dirent** contents;
	int cnt;

	if(argc==1)
	{
		cnt = scandir("./", &contents, NULL, alphasort);
	}
	else cnt = scandir(argv[1], &contents, NULL, alphasort);

	for(int i=0; i<cnt; i++)
	{
		printf("%s\n", contents[i]->d_name);
	}

	system("ls");
	return 0;
}