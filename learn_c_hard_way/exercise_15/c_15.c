#include <stdio.h>

int printf_argv(int argc, char *argv[])
{
	char **p = argv;

	int i;
	for(i = 1; i < argc; i++) {
		printf("%s\n", *(p + i));
	}
	return 0;
}

int main(int argc, char *argv[])
{
	printf_argv(argc, argv);
	return 0;
}
