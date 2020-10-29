/*
	Estudo - Algoritmo e Estruturas de Dados | 29/10/2020 | Tiago B. | tdsb.contato@gmail.com
*/

#include <stdio.h>
#define MAX 4

void exibe(int *pilha, int *topo);
void push(int *pilha, int *topo, int valor);
void pop(int *pilha, int *topo);

int main(void) {
	
	int pilha[MAX], topo, opcao, valor;
	int *pilha_p = &pilha[0], *topo_p = &topo;
		
	topo = -1; //Define o topo como -1; pilha vazia
	printf("A pilha possui capacidade para %d inteiros.\n\n", MAX);
	printf("\n1 - Exibir pilha;\n2 - Inserir valor;\n3 - Remover;\n4 - Exibir os comandos;\nCtrl+c - para sair\n\n");
	while(1) {
		printf("\nComando -> ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				exibe(pilha_p, topo_p);
				break;
			case 2:
				printf("Valor a inserir: ");
				scanf("%d", &valor);
				push(pilha_p, topo_p, valor);
				exibe(pilha_p, topo_p);
				break;
			case 3:
				pop(pilha_p, topo_p);
				exibe(pilha_p, topo_p);
				break;
			case 4:
				printf("0 - Sair;\n1 - Exibir pilha;\n2 - Inserir valor;\n3 - Remover;\n4 - Exibir os comandos;\n\n");
				break;
			default:
				printf("Opcao invalida.\n");
				break;
		}
	}	
}

void exibe(int *pilha, int *topo) {
	printf("[");
	for(int i=0; i<MAX; i++){
		if(i <= *topo) {
	 		printf(" %d", pilha[i]);
		} else {
			printf(" _");
		}
	}
	printf(" ]\n");
};

void push(int *pilha, int *topo, int valor) {
	if(*topo+1 == MAX) {
		printf("Estouro da pilha.\n");
		return;
	}
	*topo += 1;
	pilha[*topo] = valor;
};

void pop(int *pilha, int *topo) {
	if(*topo < 0) {
		printf("Pilha vazia.\n");
		return;
	}
	pilha[*topo] = 0;
	*topo -= 1;
};
