using PrimeiroProjeto.aa;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeiroProjeto
{
    internal partial class Program
    {
        Dictionary<string, List<int>> bandasRegistradas = new Dictionary<string, List<int>>();
        void ExibirMensagemDeBoasVindas()
        {
            string mensagemDeBoasVindas = "Bem-vindo ao ScreenSound";
            string nome = "Arthur";
            string sobrenome = "Quoos";
            Console.WriteLine("****************************************");
            Console.WriteLine(mensagemDeBoasVindas + " " + nome + " " + sobrenome);
            Console.WriteLine("****************************************\n");
        }

        void ExibirOpcoesDoMenu()
        {
            Console.WriteLine("1 - Registrar uma banda");
            Console.WriteLine("2 - Mostrar todas as bandas");
            Console.WriteLine("3 - Avaliar uma banda");
            Console.WriteLine("4 - Exibir a media de uma banda");
            Console.WriteLine("5 - Sair");
            Console.WriteLine("EXTRA: 6 - Pratica de exercicios");


            //Console.Write("\nDigite o número da opção desejada: ");
            int opcao = Utilities.LerInteiro("Digite o número da opção desejada: ");

            UtilitiesConstrutor utilitiesConstrutor = new UtilitiesConstrutor("abc", "cba");

            switch (opcao)
            {
                case 1:
                    Console.WriteLine("Opção 1 selecionada: Registrar uma banda");
                    RegistrarBanda();
                    break;
                case 2:
                    Console.WriteLine("Opção 2 selecionada: Mostrar todas as bandas");
                    MostrarListaDeBandas();
                    break;
                case 3:
                    Console.WriteLine("Opção 3 selecionada: Avaliar uma banda");
                    AvaliarUmaBanda();
                    break;
                case 4:
                    Console.WriteLine("Opção 4 selecionada: Exibir a média de uma banda");
                    // Lógica para exibir a média de uma banda
                    break;
                case 5:
                    Console.WriteLine("Saindo do programa...");
                    Environment.Exit(0);
                    break;
                case 6:
                    Console.WriteLine("Opção 6 selecionada: Pratica de exercicios");
                    Random random = new Random(); // Gerador de números aleatórios
                    List<int> numeros = new List<int>(); // Lista de inteiros

                    int quantidade = 10; // Quantidade de números que você quer gerar

                    for (int i = 0; i < quantidade; i++)
                    {
                        int numeroAleatorio = random.Next(1, 101); // Número entre 1 e 100
                        numeros.Add(numeroAleatorio);
                    }

                    for (int i = 0; i < numeros.Count; i++)
                    {
                        if (numeros[i] % 2 == 0) { Console.WriteLine($"Número {i + 1}: {numeros[i]}"); }
                    }

                    foreach (int numero in numeros)
                    {
                        if (numero % 2 == 0) { Console.WriteLine($"Número: {numero}"); }
                    }
                    break;
                default:
                    Console.WriteLine("Opção inválida. Tente novamente.");
                    ExibirOpcoesDoMenu();
                    break;
            }
        }

        void RegistrarBanda()
        {
            Console.Clear();
            ExibirTitulos("Registro de bandas!");
            Console.Write("Digite o nome de uma banda: ");
            string nomeDaBanda = Console.ReadLine()!;
            bandasRegistradas.Add(nomeDaBanda, new List<int>()); // Adiciona a banda com uma lista vazia de avaliações
            Console.WriteLine($"A banda {nomeDaBanda} foi registrada!");
            Thread.Sleep(1500); // Pausa para o usuário ler a mensagem
            Console.Clear();
            ExibirOpcoesDoMenu();
        }

        void MostrarListaDeBandas()
        {
            Console.Clear();
            ExibirTitulos("Exibindo bandas cadastradas!");
            /*for (int i = 0; i < ListaDasBandas.Count; i++)
            {
                Console.WriteLine($"{i + 1} - {ListaDasBandas[i]}");
            }*/
            int contador = 1;
            foreach (string banda in bandasRegistradas.Keys)
            {
                Console.WriteLine($"{contador} - {banda}");
                contador++;
            }
            Console.WriteLine("\nDigite uma tecla para voltar ao menu principal...");
            Console.ReadKey();
            Console.Clear();
            ExibirOpcoesDoMenu();
        }

        void AvaliarUmaBanda()
        {
            Console.Clear();
            ExibirTitulos("Avaliando uma banda!");
            Console.Write("Digite o nome da banda que deseja avaliar: ");
            string nomeDaBanda = Console.ReadLine()!;
            if (bandasRegistradas.ContainsKey(nomeDaBanda))
            {
                Console.Write($"Qual a nota de 0 a 10 que você dá para a banda {nomeDaBanda}? ");
                int nota = int.Parse(Console.ReadLine()!);
                bandasRegistradas[nomeDaBanda].Add(nota); // Adiciona a nota à lista de avaliações da banda
                Console.WriteLine($"\nA nota {nota} foi registrada para a banda {nomeDaBanda}!");
                Thread.Sleep(1500); // Pausa para o usuário ler a mensagem
                Console.Clear();
                ExibirOpcoesDoMenu();
            }
            else
            {
                Console.WriteLine($"A banda {nomeDaBanda} não foi encontrada!");
                Thread.Sleep(1500);
                Console.Clear();
                ExibirOpcoesDoMenu();

            }
        }

        void ExibirTitulos(string titulo)
        {
            Console.Clear();
            int quantidadeDeLetras = titulo.Length;
            string asteriscos = string.Empty.PadLeft(quantidadeDeLetras, '*');
            Console.WriteLine(asteriscos);
            Console.WriteLine(titulo);
            Console.WriteLine(asteriscos + "\n");
        }
    }
}
