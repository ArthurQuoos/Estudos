namespace JogoDeAdivinhacao
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Seja Bemvindo ao GuessTheNumber!\nTente acertar qual é o numero secreto, você terá 5 tentativas:");
            int sortear = new Random().Next(1, 100);
            System.Diagnostics.Debug.WriteLine("O número sorteado é: " + sortear);
            for (int i = 0; i < 5; i++)
            {
                //Console.Write(sortear);

                string mensagem = Console.ReadLine();
                if(mensagem.All(char.IsDigit))
                {
                    Console.WriteLine("Por favor, insira um número válido.");
                    continue;
                }

                int tentativa = int.Parse(mensagem);
                
                if (tentativa == sortear)
                {
                    Console.WriteLine("Parabéns! Você acertou o número secreto!");
                    return;
                }
                else if (tentativa < sortear)
                {
                    Console.WriteLine("O número secreto é maior que a sua tentativa.");
                }
                else
                {
                    Console.WriteLine("O número secreto é menor que a sua tentativa.");
                }
                Console.WriteLine($"\nEssa foi a sua {i + 1} Tentativa!");

                

            }

        }
    }
}
