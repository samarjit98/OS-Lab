#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
#define TOKEN_BUFFER 64

void samsh_loop();
char* samsh_readline();
char** samsh_tokenize(char* line);
void samsh_execute(char** args);

int main(int argc, char* argv[])
{
	samsh_loop();
	return EXIT_SUCCESS;
}

void samsh_loop()
{
	char* line;
	char** args;

	while(1)
	{
		printf("samshell~$> ");
		line = samsh_readline();
		args = samsh_tokenize(line);
		samsh_execute(args);
		free(line); free(args);
	}
}

char* samsh_readline()
{
	int pos=0;
	char* buffer = malloc((BUFFER_SIZE)*sizeof(char));
	int ch;
	int buffer_growth=BUFFER_SIZE;
	while(1)
	{
		ch=getchar();
		if(ch==EOF||ch=='\n')
		{
			buffer[pos]='\0';
			return buffer;
		}
		else
		{
			buffer[pos]=ch;
		}
		pos++;

		if(pos>=buffer_growth)
		{
			buffer_growth += BUFFER_SIZE;
			buffer=realloc(buffer, buffer_growth);
		}
	}
}

char** samsh_tokenize(char* line)
{
	int token_growth=TOKEN_BUFFER;
	int pos=0;
	char** tokens=malloc((TOKEN_BUFFER)*sizeof(char*));
	char* next_token;
	next_token=strtok(line, " \t\n\r\a");
	while(next_token!=NULL)
	{
		tokens[pos]=next_token;
		pos++;
		if(pos>=TOKEN_BUFFER)
		{
			token_growth+=TOKEN_BUFFER;
			tokens=realloc(tokens, token_growth);
		}
		next_token=strtok(NULL, " \t\n\r\a");
	}
	tokens[pos]=NULL;
	return tokens;
}

void samsh_execute(char** args)
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execvp(args[0], args);
	}
	else
	{
		wait(NULL);
	}
}