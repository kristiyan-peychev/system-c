#include <unistd.h>
main()
{
	char *args[] = {"/usr/bin/terminal", (char *) 0 };

	execv("/usr/bin/terminal", args);
}

