#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("please input one prement.\n");
		return 0;
	}
	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		switch(letter) {
			case 'A':
				argv[1][i] = 'a';
				printf("argv[1][%d] = %c\n", i, argv[1][i]);
				break;
			case 'B':
				argv[1][i] = 'b';
				printf("argv[1][%d] = %c\n", i, argv[1][i]);
				break;
			case 'C':
				argv[1][i] = 'c';
				printf("argv[1][%d] = %c\n", i, argv[1][i]);
				break;
		}
	}
	printf("argv[1] = %s\n", argv[1]);
	char j = '\0';
	printf("j as %%c = %c; j as %%d = %d\n", j, j);
	return 0;
}
