import time
import random

# Função de busca linear
def busca_linear(vetor, elemento):
    inicio_tempo = time.time()
    for i in range(len(vetor)):
        if vetor[i] == elemento:
            fim_tempo = time.time()
            return i, fim_tempo - inicio_tempo
    fim_tempo = time.time()
    return -1, fim_tempo - inicio_tempo

# Função de busca ordenada (linear em vetor ordenado)
def busca_ordenada(vetor, elemento):
    inicio_tempo = time.time()
    for i in range(len(vetor)):
        if vetor[i] == elemento:
            fim_tempo = time.time()
            return i, fim_tempo - inicio_tempo
    fim_tempo = time.time()
    return -1, fim_tempo - inicio_tempo

# Função de busca binária
def busca_binaria(vetor, elemento):
    inicio_tempo = time.time()
    inicio, fim = 0, len(vetor) - 1
    while inicio <= fim:
        meio = (inicio + fim) // 2
        if vetor[meio] == elemento:
            fim_tempo = time.time()
            return meio, fim_tempo - inicio_tempo
        elif vetor[meio] < elemento:
            inicio = meio + 1
        else:
            fim = meio - 1
    fim_tempo = time.time()
    return -1, fim_tempo - inicio_tempo

# Função principal
def main():
    # Gerar vetor aleatório com 10 números únicos entre 1 e 100
    vetor_aleatorio = random.sample(range(1, 100), 10)
    vetor_ordenado = sorted(vetor_aleatorio)

    # Exibir os vetores
    print("Vetor aleatório:", vetor_aleatorio)
    print("Vetor ordenado :", vetor_ordenado)

    # Solicitar ao usuário o número a ser buscado
    while True:
        try:
            elemento = int(input("\nDigite o número a ser buscado: "))
            break
        except ValueError:
            print("Entrada inválida! Por favor, digite um número inteiro.")

    # Realizar as buscas
    indice_linear, tempo_linear = busca_linear(vetor_aleatorio, elemento)
    indice_ordenada, tempo_ordenada = busca_ordenada(vetor_ordenado, elemento)
    indice_binaria, tempo_binaria = busca_binaria(vetor_ordenado, elemento)

    # Exibir os resultados
    print(f"\n🔍 Resultados da busca pelo elemento {elemento}:\n")

    if indice_linear == -1:
        print("Elemento não encontrado em nenhuma das buscas.")
    else:
        print(f"Busca Linear   → Índice: {indice_linear} | Tempo: {tempo_linear:.6f} segundos")
        print(f"Busca Ordenada → Índice: {indice_ordenada} | Tempo: {tempo_ordenada:.6f} segundos")
        print(f"Busca Binária  → Índice: {indice_binaria} | Tempo: {tempo_binaria:.6f} segundos")

# Ponto de entrada do programa
if __name__ == "__main__":
    main()
