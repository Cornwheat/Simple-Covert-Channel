#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;

    struct stat fileStatus;
    if(stat(argv[1],&fileStatus) < 0)    
        return 1;
 
    do
    {
	struct stat fileStatus;
        if(stat(argv[1],&fileStatus) < 0)    
            return 1;

        printf( (fileStatus.st_mode & S_IWUSR) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IXUSR) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IRGRP) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IWGRP) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IXGRP) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IROTH) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IWOTH) ? "1" : "0");
        printf( (fileStatus.st_mode & S_IXOTH) ? "1" : "0");
        printf("\t");

        char character = '\0';

        if (fileStatus.st_mode & S_IWUSR)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IXUSR)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IRGRP)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IWGRP)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IXGRP)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IROTH)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IWOTH)
        {
           ++character;
        }
        character = (character << 1);
        if (fileStatus.st_mode & S_IXOTH)
        {
           ++character;
        }

        printf("%c",character);
        printf("\n");
        sleep(2);
	if (character == '\0')
	{
	    return 0;
	}
    } while(fileStatus.st_mode & S_IRUSR);

    return 0;
}