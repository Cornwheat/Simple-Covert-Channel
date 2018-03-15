#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    char* path = argv[1];
    FILE* inputFile;

    inputFile = fopen(path,"r");

    if (access(path, F_OK) != 0)
    {
        if (errno == ENOENT)
		printf("%s does not exist\n", path);
	else if (errno == EACCES)
		printf("%s is not accessible\n", path);
    }

    char character = '\0';
    int mode = 0; 
    while ((character = fgetc(inputFile)) != EOF)
    {
        mode = character + 256;
        chmod(path,mode);
        sleep(2);
    }    

    chmod(path,0);
    sleep(2);
    chmod(path,0777);
    return 0;
}