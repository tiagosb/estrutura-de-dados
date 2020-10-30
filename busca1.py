# -*-encoding:utf-8-*-
# --------------------------------------------------------------------------------------
#
# Estudo - Algoritmos e Estruturas de Dados - Tiago B. - 30/10/2020
# Exemplos baseados no livro: Estruturas de Dados e Seus Algoritmos 3 edição, pág 22
#
# A função busca1 faz duas verificações a cada execução: i < len(lista) e lista[i] == alvo;
# A função busca2 faz apenas uma verificação por execução: lista[i] == alvo
#
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
    if not i == len(lista) - 1:
        return i  # Item encontrado; retorna o indice
    return None


for i in range(1000000):
    lista.append(random.randint(10, 100000))

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
print("Diferenca  -> {}\n".format(tempo1 - tempo2))

if tempo1 > tempo2:
    print("A segunda funcao foi mais rapida que a primeira.")
else:
    print("A primeira funcao foi mais rapida que a primeira.")
