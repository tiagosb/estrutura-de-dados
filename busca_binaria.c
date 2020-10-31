/*
*
* Estudo - Algoritmos e Estruturas de Dados - Tiago B. - tdsb.contato@gmail.com
* 
* Implementa o algoritmo de busca binaria
*
*/

#include <stdio.h>

#define MAX 14

int busca(int * lista, int valor);

void teste(int * lista);

int main(void) 
{
   int lista[MAX] = {
      10,
      13,
      20,
      22,
      28,
      34,
      52,
      63,
      94,
      194,
      288,
      494,
      1299,
      4999
   };

   int * p_lista = & lista[0];

   teste(p_lista);
}

void teste(int * lista) 
{

   int valores[8] = {
      0,
      13,
      22,
      52,
      194,
      1299,
      4999,
      70000
   };
   int result;

   for (int i = 0; i < 9; i++) {
      printf("Buscando por %d: ", valores[i]);

      result = busca(lista, valores[i]);

      if (result >= 0) 
	printf("encontrado na posicao %d\n", result);

      else printf("Nao encontrado.\n");
   }
}

int busca(int * lista, int valor) 
{
   int meio;
   int inicio = 0;
   int fim = MAX;

   while (inicio <= fim) {
      meio = (int)(inicio + fim) / 2;

      if (lista[meio] == valor) 
	return meio;

      else if (lista[meio] < valor)
	inicio = meio + 1;

      else fim = meio - 1;
   }

   return -1;
}
