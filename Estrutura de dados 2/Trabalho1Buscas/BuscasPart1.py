import time

def busca_linear(lista, tamanho, alvo):
    for i in range(tamanho):
        if lista[i] == alvo:
            return i
    return -1


def busca_ordenada(lista, tamanho, alvo):
    for i in range(tamanho):
        if lista[i] == alvo:
            return i
        elif lista[i] > alvo:  # como está ordenado, pode parar antes
            break
    return -1


def busca_binaria(lista, tamanho, alvo):
    inicio, fim = 0, tamanho - 1
    while inicio <= fim:
        meio = (inicio + fim) // 2
        if lista[meio] == alvo:
            return meio
        elif lista[meio] < alvo:
            inicio = meio + 1
        else:
            fim = meio - 1
    return -1


def main():
    lista_desordenada = [1, 25, 3, 30, 41, 27, 17, 4, 2, 5]
    lista_ordenada = [1, 2, 4, 5, 17, 25, 27, 30, 31, 41]
    elemento_procurado = 41

    # Busca Linear
    inicio_tempo = time.perf_counter()
    indice_linear = busca_linear(lista_desordenada, len(lista_desordenada), elemento_procurado)
    tempo_linear = time.perf_counter() - inicio_tempo

    # Busca Ordenada
    inicio_tempo = time.perf_counter()
    indice_ordenada = busca_ordenada(lista_ordenada, len(lista_ordenada), elemento_procurado)
    tempo_ordenada = time.perf_counter() - inicio_tempo

    # Busca Binária
    inicio_tempo = time.perf_counter()
    indice_binaria = busca_binaria(lista_ordenada, len(lista_ordenada), elemento_procurado)
    tempo_binaria = time.perf_counter() - inicio_tempo

    # Resultados
    print(f"Índice de busca linear: {indice_linear} | Tempo: {tempo_linear:.8f} segundos")
    print(f"Índice de busca ordenada: {indice_ordenada} | Tempo: {tempo_ordenada:.8f} segundos")
    print(f"Índice de busca binária: {indice_binaria} | Tempo: {tempo_binaria:.8f} segundos")


if __name__ == "__main__":
    main()
