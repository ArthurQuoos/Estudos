# Abre o arquivo entrada.txt em modo de leitura ('r')
with open('entrada.txt', 'r', encoding='utf-8') as arquivo:
    conteudo = arquivo.read()

# Exibe o conteúdo do arquivo
print("Conteúdo do arquivo 'entrada.txt':")
print(conteudo)