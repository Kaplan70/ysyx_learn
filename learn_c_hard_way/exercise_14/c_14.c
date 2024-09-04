#include <stdio.h>
#include <ctype.h>

int printf_char(char *argv_char)
{
	int i = 0;
	for(i = 0; argv_char[i] != '\0'; i++) {
		char ch = argv_char[i];
		if(isalpha(ch) || isblank(ch)) printf("%c", ch);
	}
}

int printf_string(int argc, char *argv[])
{
	int i = 0;
	for(i = 1; i < argc; i++) {
		printf_char(argv[i]);
		printf("\n");
	}
	return 0;
}

int main(int argc, char *argv[])
{
	printf_string(argc, argv);
	return 0;
}
