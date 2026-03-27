import sys


#CONFIGURAÇÃO DE MODO DE EXECUÇÃO
#Se TESTE_MANUAL = True -> define os arquivos diretamente no código.
#Se TESTE_MANUAL = False -> usa sys.argv.

TESTE_MANUAL = False   #false = modo terminal / true = modo manual


#Leitura do arquivo de consulta
def ler_arquivo_consulta(nome):
    with open(nome, "r", encoding="utf-8") as arq:
        campo = arq.readline().strip()
        valor = arq.readline().strip()
    return campo, valor



#objeto para armazenar a musica
class Musica:
    def __init__(self, ano, duracao, titulo, artista, genero, idioma):
        self.ano = ano
        self.duracao = duracao
        self.titulo = titulo
        self.artista = artista
        self.genero = genero
        self.idioma = idioma

    def formato_saida(self):
        return f"{self.ano}|{self.duracao}|{self.titulo}|{self.artista}|{self.genero}|{self.idioma}"



#Ler o arquivo de dados
def ler_arquivo_dados(nome):
    musicas = []

    with open(nome, "r", encoding="utf-8") as arq:
        header = arq.readline()  #ignorado

        for linha in arq:
            linha = linha.strip()
            if not linha:
                continue

            partes = linha.split("|")
            if len(partes) != 6:
                continue

            m = Musica(*partes)
            musicas.append(m)

    return musicas



#Criar indice secundario
def criar_indice(musicas, campo):
    indice = {}

    for m in musicas:
        chave = getattr(m, campo)

        if chave not in indice:
            indice[chave] = []

        indice[chave].append(m)

    return indice



#Escrever arquivo de saida
def escrever_saida(nome_saida, resultados, campo, valor):
    with open(nome_saida, "w", encoding="utf-8") as arq:

        if not resultados:
            arq.write(f"Nenhum resultado encontrado para {campo} = {valor}\n")
            return

        for m in resultados:
            arq.write(m.formato_saida() + "\n")


#Main ------------------------------------

def main():

   
    # Configuração de modo de execução
    # True = modo manual (arquivos definidos no código)
    # False = modo Terminal (arquivos via sys.argv)
  
    if TESTE_MANUAL:
        #MODO MANUAL: definir arquivos diretamente no código
        arquivo_dados = "musicas.txt"
        arquivo_consulta = "entrada06Trabalho2.txt"
        arquivo_saida = "saida_teste.txt"
        print(">> Modo manual ativado. Arquivos definidos diretamente no código.")
    else:
        #MODO TERMINAL: leitura pelo terminal
        if len(sys.argv) != 4:
            print("Uso correto: python3 indice.py <arquivo_dados> <arquivo_consulta> <arquivo_saida>")
            return

        arquivo_dados = sys.argv[1]
        arquivo_consulta = sys.argv[2]
        arquivo_saida = sys.argv[3]

    #Fim da configuracao de modo

    #Ler consulta
    campo, valor = ler_arquivo_consulta(arquivo_consulta)

    campos_validos = {"ano", "titulo", "artista", "genero", "idioma"}

    if campo not in campos_validos:
        escrever_saida(arquivo_saida, [], campo, valor)
        return

    #Ler todas as músicas
    musicas = ler_arquivo_dados(arquivo_dados)

    #Criar índice secundário
    indice = criar_indice(musicas, campo)
    print(f"Índice criado para o campo '{campo}'.")
    #Buscar
    resultados = indice.get(valor, [])

    #Gravar saida
    escrever_saida(arquivo_saida, resultados, campo, valor)



if __name__ == "__main__":
    main()