def EscritaRegistrosFixosCamposVariados(registrosPersonagens, arquivoSaida="output.txt"):
    #descobrir o tamanho do maior registro contido no arquivoSaida
    maiorTamanho = len(max(registrosPersonagens,key=len))
    print(maiorTamanho)
    
    with open(arquivoSaida, mode = "w") as file:
        for registro in registrosPersonagens:
            #substituindo virgula (,) por pipe (|)
            novoRegistro = registro.replace(",","|")
            novoRegistro = novoRegistro.replace("\n","")
            
            #adicionar explicitamente espacos nao usados (caracter *)
            diff=maiorTamanho-len(novoRegistro)
            aux="*" * diff
            novoRegistro=novoRegistro + aux + "\n"
            
            #gravar os registros no novo arquivo output
            file.write(novoRegistro)

def compactacaoEspaco(registrosPersonagens):
    with open ("regCompactados.txt", mode="w") as file:
        for registro in registrosPersonagens:
            #pega o primeiro caracter de uma string e verifica se e !=
            if(registro[0] != "*"):
                file.write(registro)
                
            

def removeRegistrosPorRRN( registrosPersonagens,id):
    if(id>= len(registrosPersonagens)):
        print("Atencao: indice invalido")
    else:
        registro = registrosPersonagens[id]
        registro = "*|" + registro[2:]
        registrosPersonagens[id] = registro
        #gravando um novo arquivo com os dados removidos
        with open("depoisRemocao.txt", mode="w") as file:
            for registro in registrosPersonagens:
                file.write(registro)
                
if __name__ == "__main__":

    #abrindo  o arquivo fonte 
    f = open("personagens.csv", mode = "r", encoding = "utf-8")

    #Lendo  todos os registros e armazenando em uma lista (registrosPErsonagens)
    registrosPersonagens = f.readlines()

    #removendo cabecalho 
    registrosPersonagens.pop(0)

    #fechando o arquivo
    f.close()

    #testes de remocao de registros validos
    removeRegistrosPorRRN(registrosPersonagens,id = 3)

    #print(registrosPersonagens)


            
    compactacaoEspaco(registrosPersonagens)
    arquivoSaida = "RegistrosFixos.txt"
    EscritaRegistrosFixosCamposVariados(registrosPersonagens,arquivoSaida)