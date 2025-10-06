# Abre (ou cria) o arquivo entrada.txt em modo de escrita ('w')
with open('entrada.txt', 'w', encoding='utf-8') as arquivo:
    arquivo.write("Olá, mundo!\n")
    arquivo.write("Este é um exemplo de escrita em arquivo.\n")

print("Arquivo 'entrada.txt' criado com sucesso!")