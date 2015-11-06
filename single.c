#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#ifdef HAVE_ST_BIRTHTIME
#define birthtime(x) x.st_birthtime
#else
#define birthtime(x) x.st_ctime
#endif

int main(int argc, char* argv[])
{
	DIR *dir;
	size_t i;
	
	struct dirent *ent;
	struct stat st;/*структура для мета информации о файлах*/
	if ((dir = opendir ("/home/kartalenka/linux/server")) != NULL)
	 {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL)
	        {
			stat(ent->d_name, &st);
    			printf ("%s\n", ent->d_name);
  			printf("%i\n", birthtime(st));
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
