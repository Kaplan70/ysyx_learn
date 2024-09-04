#include <stdio.h>

int main(int argc, char *argv[]){
	int i = 0;
	for(i = 1;i < argc;i++){
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	char *states[] = {"abc", "def", "gh", NULL};
	int num_states = 4;
	for(i = 0;i < num_states;i++){
		printf("states[%d] = %s\n", i, states[i]);
	}

	char *states_pay[4];

	int num_states_pay = 3;

	for(i = 0; i < num_states_pay; i++){
		states_pay[i] = argv[i + 1];
	}

	for(i = 0;i < num_states_pay;i++){
		printf("states_pay[%d] = %s\n", i, states_pay[i]);
	}
	return 0;
}
