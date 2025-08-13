namespace Praticas
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");

            Dictionary<string, List<double>> Alunos = new Dictionary<string, List<double>>
                {
                { "João", new List<double> { 7.5, 8.0, 6.5 } },
                { "Maria", new List<double> { 9.0, 8.5, 7.0 } },
                { "Pedro", new List<double> { 6.0, 5.5, 7.0 } }
            };

            /*foreach (var aluno in Alunos)
            {
                double media = aluno.Value.Average();
                Console.WriteLine($"Aluno: {aluno.Key}, Média: {media:F2}");
            }*/

            foreach (var aluno in Alunos)
            {
                double media = 0;
                for (int i = 0; i < aluno.Value.Count; i++)
                {
                    media += aluno.Value[i];
                    Console.WriteLine($"Nota {i + 1} de {aluno.Key}: {aluno.Value[i]}");

                }
                Console.WriteLine($"Média de {aluno.Key}: {media / aluno.Value.Count:F2}");
            }

            // Ex2 ============================================================================================
            /*
            Dictionary<string, int> Estoque = new Dictionary<string, int>
            {
                { "Maçã", 10 },
                { "Banana", 5 },
                { "Laranja", 8 }
            };

            Console.WriteLine("\nProdutos em estoque:");
            foreach (var produto in Estoque)
            {
                Console.WriteLine($"{produto.Key}");
            }
            Console.WriteLine("\nDigite o nome do produto para verificar a quantidade em estoque:");
            string produtoConsulta = Console.ReadLine();


            bool encontrado = false;

            foreach (var item in Estoque)
            {
                if (item.Key == produtoConsulta)
                {
                    Console.WriteLine($"Quantidade em estoque de '{produtoConsulta}': {item.Value}");
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                Console.WriteLine("Produto não encontrado.");
            }

            /*if(Estoque.TryGetValue(produtoConsulta, out int quantidade))
                {
                    Console.WriteLine($"Quantidade de {produtoConsulta} em estoque: {quantidade}");
                }
                else
                {
                    Console.WriteLine($"Produto {produtoConsulta} não encontrado no estoque.");
                }*/

            // Ex3 ============================================================================================

            Dictionary<string, string> usuarios = new Dictionary<string, string>
            {
            { "user1", "senha123" },
            { "user2", "abc456" },
            };

            string nomeUsuario = "user1";
            string senha = "senha123";

            if (usuarios.ContainsKey(nomeUsuario) && usuarios[nomeUsuario] == senha)
                Console.WriteLine("Login bem-sucedido!");
            else
                Console.WriteLine("Nome de usuário ou senha incorretos.");


            //Ex4 ============================================================================================
            /*
            Dictionary<string, string> perguntasERespostas = new Dictionary<string, string>
            {
                { "Qual é a capital do Brasil?", "Brasília" },
                { "Quanto é 7 vezes 8?", "56" },
                { "Quem escreveu 'Romeu e Julieta'?", "William Shakespeare" },
                // Adicione mais perguntas e respostas conforme necessário
            };

            int pontuacao = 0;

            foreach (var pergunta in perguntasERespostas)
            {
                Console.WriteLine(pergunta.Key);
                Console.Write("Sua resposta: ");
                string respostaUsuario = Console.ReadLine();

                if (respostaUsuario.ToLower() == pergunta.Value.ToLower())
                {
                    Console.WriteLine("Correto!\n");
                    pontuacao++;
                }
                else
                {
                    Console.WriteLine($"Incorreto. A resposta correta é: {pergunta.Value}\n");
                }
            }

            Console.WriteLine($"Pontuação final: {pontuacao} de {perguntasERespostas.Count}");
            */
            // Ex5 ============================================================================================

            Dictionary<string, List<int>> vendasCarros = new Dictionary<string, List<int>> {
            { "Bugatti Veyron", new List<int> { 10, 15, 12, 8, 5 } },
            { "Koenigsegg Agera RS", new List<int> { 2, 3, 5, 6, 7 } },
            { "Lamborghini Aventador", new List<int> { 20, 18, 22, 24, 16 } },
            { "Pagani Huayra", new List<int> { 4, 5, 6, 5, 4 } },
            { "Ferrari LaFerrari", new List<int> { 7, 6, 5, 8, 10 } }
};
            Console.WriteLine("Carros e suas vendas mensais:");
            foreach (var carro in vendasCarros)
            {
                Console.WriteLine($"{carro.Key}");
            }
            Console.WriteLine("\nDigite o nome do carro para verificar as vendas mensais:");
            string carroConsulta = Console.ReadLine();

            if (vendasCarros.TryGetValue(carroConsulta, out List<int> vendas))
            {
                Console.WriteLine($"Vendas mensais de {carroConsulta}: {string.Join(", ", vendas)}");
                double mediaVendas = vendas.Average();
                Console.WriteLine($"Média de vendas mensais de {carroConsulta}: {mediaVendas:F2}");
            }
            else
            {
                Console.WriteLine($"Carro {carroConsulta} não encontrado.");


            }
        }
    } 
}
