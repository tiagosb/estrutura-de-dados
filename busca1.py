# -*-encoding:utf-8-*-
# --------------------------------------------------------------------------------------
#
# Estudo - Algoritmos e Estruturas de Dados - Tiago B. - 30/10/2020
# Exemplos baseados no livro: Estruturas de Dados e Seus Algoritmos 3 edição, pág 22
#
# A função busca1 faz duas verificações a cada execução: i < len(lista) e lista[i] == alvo;
# A função busca2 faz apenas uma verificação por execução: lista[i] == alvo
# A função busca3 busca na lista ordenada
# ---------------------------------------------------------------------------------------
import time
import random

lista = []


def busca1(alvo):
    i = 0
    while i < len(lista):
        if lista[i] == alvo:
            return i  # Item encontrado; retorna o indice
        else:
            i += 1
    return None  # Item não encontrado


def busca2(alvo):
    lista.append(alvo)  # Adiciona o valor buscado como ultimo elemento da lista
    i = 0
    while not lista[i] == alvo:
        i += 1
    lista.pop() #Remove o elemento que havia sido adicionado
    if not i == len(lista) - 1:
        return i  # Item encontrado; retorna o indice
    return None

def busca3(alvo):
	lista.sort()
	lista.append(alvo) #Adiciona o alvo no final da lista
	i = 0
	while lista[i] < alvo:
		i += 1
	if i == len(lista)-1 or not lista[i] == alvo:
		lista.pop()
		return None
	lista.pop()
	return i



for i in range(10000):
    lista.append(random.randint(10, 1000))

n = random.choice(lista)


print(
    "A lista possui {} elementos nao ordenados.\nBuscando por {}...\n".format(
        len(lista), n
    )
)
start1 = time.time()
busca1(n)
tempo1 = time.time() - start1
print("Busca1     -> {}".format(tempo1))

start2 = time.time()
busca2(n)
tempo2 = time.time() - start2
print("Busca2     -> {}".format(tempo2))

start3 = time.time()
busca3(n)
tempo3 = time.time() - start3
print("Busca3     -> {}".format(tempo3))
