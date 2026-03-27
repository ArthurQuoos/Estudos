import sys
import os

# Mude para False quando for entregar
TESTE_MANUAL = True

def localizar_arquivo(nome_arquivo):
    """Tenta localizar o arquivo em cwd, no diretório do script ou como caminho informado."""
    cwd_path = os.path.join(os.getcwd(), nome_arquivo)
    script_dir = os.path.dirname(os.path.abspath(__file__))
    script_path = os.path.join(script_dir, nome_arquivo)

    if os.path.isfile(cwd_path):
        return cwd_path
    if os.path.isfile(script_path):
        return script_path
    if os.path.isfile(nome_arquivo):
        return nome_arquivo

    raise FileNotFoundError(f"Arquivo '{nome_arquivo}' não encontrado.\n- cwd: {cwd_path}\n- script_dir: {script_path}\n- original: {nome_arquivo}")

# ---------------------------------------------
# Leitura do arquivo de consulta
# ---------------------------------------------
def ler_arquivo_consulta(caminho):
    with open(caminho, "r", encoding="utf-8") as arq:
        linha1 = arq.readline()
        linha2 = arq.readline()

        if not linha1:
            raise ValueError("Arquivo de consulta vazio (linha 1 faltando).")
        if not linha2:
            raise ValueError("Arquivo de consulta inválido (linha 2 faltando).")

        campo = linha1.strip().lstrip("\ufeff")  # remover BOM se houver
        valor = linha2.strip()
    return campo, valor


# ---------------------------------------------
# Objeto simples para armazenar uma música
# ---------------------------------------------
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


# ---------------------------------------------
# Leitura do arquivo de dados (base)
# ---------------------------------------------
def ler_arquivo_dados(caminho, debug=False):
    musicas = []

    with open(caminho, "r", encoding="utf-8") as arq:
        header = arq.readline()  # ignorado (mas poderia ser usado para QTDE)

        for i, linha in enumerate(arq, start=2):
            linha = linha.rstrip("\n\r")
            if not linha.strip():
                continue

            partes = linha.split("|")

            # se tiver mais de 6 partes, juntar o que sobrou no último campo
            if len(partes) > 6:
                partes = partes[:5] + ["|".join(partes[5:])]
            if len(partes) < 6:
                if debug:
                    print(f"[AVISO] linha {i} ignorada: esperava 6 campos mas encontrou {len(partes)} -> {linha}")
                continue

            partes = [p.strip() for p in partes]  # limpa espaços laterais
            m = Musica(*partes)
            musicas.append(m)

    return musicas


# ---------------------------------------------
# Criar índice secundário
# ---------------------------------------------
def criar_indice(musicas, campo):
    indice = {}
    for m in musicas:
        chave = getattr(m, campo)
        if chave not in indice:
            indice[chave] = []
        indice[chave].append(m)
    return indice


# ---------------------------------------------
# Escrever arquivo de saída
# ---------------------------------------------
def escrever_saida(nome_saida, resultados, campo, valor, erro_msg=None):
    with open(nome_saida, "w", encoding="utf-8") as arq:
        if erro_msg:
            arq.write(erro_msg + "\n")
            return
        if not resultados:
            arq.write(f"Nenhum resultado encontrado para {campo} = {valor}\n")
            return
        for m in resultados:
            arq.write(m.formato_saida() + "\n")


# ---------------------------------------------
# PROGRAMA PRINCIPAL
# ---------------------------------------------
def main():
    if TESTE_MANUAL:
        arquivo_dados = "musicas1.txt"
        arquivo_consulta = "teste.txt"
        arquivo_saida = "saida_teste.txt"
        print(">> Modo manual ativado.")
        print("cwd:", os.getcwd())
        print("script dir:", os.path.dirname(os.path.abspath(__file__)))
        print("arquivos no cwd:", os.listdir(os.getcwd()))
    else:
        if len(sys.argv) != 4:
            print("Uso: python3 indice.py <arquivo_dados> <arquivo_consulta> <arquivo_saida>")
            return
        arquivo_dados = sys.argv[1]
        arquivo_consulta = sys.argv[2]
        arquivo_saida = sys.argv[3]

    # localizar caminhos reais (oepracional)
    try:
        caminho_dados = localizar_arquivo(arquivo_dados)
        caminho_consulta = localizar_arquivo(arquivo_consulta)
    except FileNotFoundError as e:
        print("ERRO:", e)
        escrever_saida(arquivo_saida, [], "", "", erro_msg="Erro: arquivo de entrada não encontrado.")
        return

    # ler consulta
    try:
        campo, valor = ler_arquivo_consulta(caminho_consulta)
    except Exception as e:
        print("Erro ao ler arquivo de consulta:", e)
        escrever_saida(arquivo_saida, [], "", "", erro_msg=f"Erro ao ler consulta: {e}")
        return

    campos_validos = {"ano", "titulo", "artista", "genero", "idioma"}
    if campo not in campos_validos:
        escrever_saida(arquivo_saida, [], campo, valor, erro_msg="Erro: campo de índice inválido.")
        return

    # ler músicas
    musicas = ler_arquivo_dados(caminho_dados, debug=True)

    # criar índice e buscar
    indice = criar_indice(musicas, campo)
    resultados = indice.get(valor, [])

    # gravar saída
    escrever_saida(arquivo_saida, resultados, campo, valor)
    print(f"Concluído. Resultado salvo em: {os.path.abspath(arquivo_saida)}")

if __name__ == "__main__":
    main()
