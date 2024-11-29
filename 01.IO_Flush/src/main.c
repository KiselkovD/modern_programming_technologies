#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*OutputFunction)(const char *);

void my_puts(const char *str)
{
	puts(str);
}

void my_fputs_stdout(const char *str)
{
	fputs(str, stdout);
}

void my_fputs_stderr(const char *str)
{
	fputs(str, stderr);
}

void my_printf(const char *str)
{
	printf("%s", str); // Added %s to format the string correctly
}

int main(int argc, char *argv[])
{
	// Function names
	const char *functionNames[] = {
			"puts(    )",
			"fputs(out)",
			"fputs(err)",
			"printf(  )"};

	// Array of function pointers
	OutputFunction functions[] = {
			my_puts,
			my_fputs_stdout,
			my_fputs_stderr,
			my_printf};

	// Default values
	int outputFunction = 0; // 0 for puts, 1 for fputs(stdout), 2 for fputs(stderr), 3 for printf
	int useNewline = 0;			// 0 for no newline, 1 for newline
	int useFlush = 0;				// 0 for no flush, 1 for flush

	// Check if enough arguments are provided
	if (argc != 4)
	{
		printf("ERROR\nuse arg like this:\nmain <outputFunction(0-3)> <Newline(0-1)> <useFlush(0-1)>\n");
		return 1;
	}

	outputFunction = atoi(argv[1]); // Choose output function
	useNewline = atoi(argv[2]);			// Newline flag
	useFlush = atoi(argv[3]);				// Flush flag

	// Create a buffer large enough to hold the function name and a potential newline
	char str[20];
	strcpy(str, functionNames[outputFunction]); // Copy the selected function name

	// Append newline if needed
	if (useNewline)
	{
		strcat(str, "\n"); // Append newline string
	}

	// Use the selected function
	functions[outputFunction](str);

	// Use flush if required
	if (useFlush)
	{
		if (outputFunction == 2)
			fflush(stderr);
		else
			fflush(stdout);
	}

	return 0;
}