/*
	Estudo - Algoritmo e Estruturas de Dados | 30/10/2020 | Tiago B. | tdsb.contato@gmail.com
*/

#include <stdio.h>
#define MAX 4

void pop(int *fila, int *ultimo);
void push(int *fila, int *ultimo, int valor);
void show(int *fila, int *ultimo);
void menu(int *fila, int *ultimo);

int main(void) {
	int fila[MAX];
	int ultimo = -1;	
	int *u = &ultimo, *f=&fila[0];	
	menu(f, u);	
}

void menu(int *fila, int *ultimo) {
	int opcao, valor;
	char comandos[] = "1 - Push na fila.\n2 - Pop na fila.\n3 - Exibir a fila.\n4 - Exibe os comandos.\nCtrl+c para sair\n\n";
	printf("%s", comandos);
	
	while(1){

		printf("\nComando -> ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("Valor: ");
				scanf("%d", &valor);
				push(fila, ultimo, valor);
				show(fila, ultimo);
				break;
			case 2:
				pop(fila, ultimo);
				show(fila, ultimo);
				break;

			case 3:
				show(fila, ultimo);
				break;
			case 4:
				printf("%s", comandos);
				break;	
			default:
				printf("Invalido.\n");
				break;
		}
	}
}

void pop(int *fila, int *ultimo) {
	if(*ultimo < 0) {
		printf("Fila vazia.\n");
		return;
	}
	
	for(int i=0; i<*ultimo; i++)  fila[i] = fila[i+1];//Remove o primeiro e realoca o restante
	*ultimo -= 1;
}

void push(int *fila, int *ultimo, int valor) {
	if(*ultimo+1 == MAX) {
		printf("Estouro da fila.\n");
		return;
	}
	*ultimo += 1;	
	fila[*ultimo] = valor;
}

void show(int *fila, int *ultimo) {
	printf("[");
	for(int i=0; i<MAX; i++) {
		if(i < *ultimo+1){
			printf(" %d", fila[i]);
		} else printf(" _");
	}
	printf(" ]\n");
}
