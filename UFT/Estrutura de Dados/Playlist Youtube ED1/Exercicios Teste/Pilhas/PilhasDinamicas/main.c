#include <stdio.h>
#include "Stack.h"

int main(void){

	Stack * s = Stack_create();

	printf("Criando pilha e empilhando elementos...\n");
	for(int i = 1; i <= 5; i++){
		int v = i * 10;
		printf("Push %d\n", v);
		Stack_push(s, v);
		Stack_print(s);
	}

	printf("\nPeek (topo): %d\n", Stack_peek(s));

	printf("\nFazendo um pop...\n");
	printf("Pop retornou: %d\n", Stack_pop(s));
	Stack_print(s);

	printf("\nEsvaziando a pilha com pops:\n");
	while(!Stack_is_empty(s)){
		printf("Pop: %d\n", Stack_pop(s));
	}

	Stack_print(s);

	Stack_destroy(&s);
	if (s == NULL) printf("Pilha destruída com sucesso.\n");

	return 0;
}

