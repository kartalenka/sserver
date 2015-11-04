#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("/home/kartalenka/linux/server")) != NULL)
	 {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL)
		 {
    		printf ("%s\n", ent->d_name);
  		}
  		closedir (dir);
	 }
	 else
	 {
  		/* could not open directory */
  		perror ("");
  		return EXIT_FAILURE;
	 }
}
