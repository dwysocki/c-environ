#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include "linkedlist.h"

char *
dircount(void)
{
    int i;
    char *count = (char *) malloc(1024*sizeof(char));
    DIR *dirp;

    for(i = -2, dirp = opendir("."); readdir(dirp); i++);

    sprintf(count, "%d", i);

    return count;
}

char *
charcount(int argc, char* argv[])
{
    int c, i;
    char *count = (char *) malloc(1024*sizeof(char));

    for(c = i = 0; i < argc; i++)
	c += strlen(argv[i]);

    sprintf(count, "%d", c);

    return count;
}

Node *
populate(int argc, char* argv[])
{
    char hostname[1024], uid[1024], cwd[1024];
    time_t t = time(0);
    Node *root = NULL;

    gethostname(hostname, 1024);
    sprintf(uid, "%d", getuid());
    getcwd(cwd, 1024);

    root = addnew(root, "progname", argv[0]);
    root = addnew(root, "user", getlogin());
    root = addnew(root, "host", hostname);
    root = addnew(root, "uid", uid);
    root = addnew(root, "tty", ttyname(0));
    root = addnew(root, "date", strtok(ctime(&t), "\n"));
    root = addnew(root, "cwd", cwd);
    root = addnew(root, "files", dircount());
    root = addnew(root, "term", getenv("TERM"));
    root = addnew(root, "args", charcount(argc, argv));

    return root;
}

void
repl(Node *root)
{
    char input[1024], command[1024];
    printf("Commands:\n"
	   "    display - display all entries\n"
	   "    quit    - exit program\n"
	   "    <key>   - look up <key> in list\n");
    /* DL's gonna love this */
    while(INT_MAX) {
	fputs("$ ", stdout);
	fflush(stdout);
	
	if (!fgets(input, sizeof(input), stdin))
	    break;

	if (input[0] == '\n') continue;

	strcpy(command, strtok(input, "\n"));
	/*    printf("%d\n", strlen(input));
	      return; */
	if (strcmp("quit", command) == 0) {
	    printf("Goodbye.\n");
	    return;
	}
	else if (strcmp("display", command) == 0)
	    displayall(root);
	else
	    query(root, command);
    }
}




int
main(int argc, char* argv[])
{
    Node *root = populate(argc, argv);
    repl(root);
}
