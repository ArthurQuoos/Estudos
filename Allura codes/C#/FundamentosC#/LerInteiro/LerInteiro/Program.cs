namespace EntradasUteis
{
    using System;

    public static class EntradasUteis
    {
        public static int LerInteiro(string mensagem)
        {
            int numero;
            string entrada;

            do
            {
                Console.WriteLine(mensagem);
                entrada = Console.ReadLine();

                if (!int.TryParse(entrada, out numero))
                {
                    Console.WriteLine("Entrada inválida. Tente novamente.\n");
                }

            } while (!int.TryParse(entrada, out numero));

            return numero;
        }

        public static float LerFloat(string mensagem)
        {
            float numero;
            string entrada;

            do
            {
                Console.WriteLine(mensagem);
                entrada = Console.ReadLine();

                if (!float.TryParse(entrada, out numero))
                {
                    Console.WriteLine("Entrada inválida. Tente novamente.\n");
                }

            } while (!float.TryParse(entrada, out numero));

            return numero;
        }
    }
}
