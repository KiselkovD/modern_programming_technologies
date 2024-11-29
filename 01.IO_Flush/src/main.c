#include <stdio.h>

int main()
{
	puts("[puts_STDOUT]");
	fputs("[fputs_STDOUT]", stdout);
	fputs("[fputs_STDERR]", stderr);
	printf("[printf_STDOUT]");
	printf("[printf_\\n_STDOUT]\n");

	return 0;
}
