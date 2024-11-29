#include <stdio.h>

int main()
{
	puts("[puts_STDOUT]");
	fflush(stdout);
	fputs("[fputs_STDOUT]", stdout);
	fflush(stdout);
	fputs("[fputs_STDERR]", stderr);
	fflush(stderr);
	printf("[printf_\\n_STDOUT]\n");
	printf("[printf_STDOUT]");

	return 0;
}
