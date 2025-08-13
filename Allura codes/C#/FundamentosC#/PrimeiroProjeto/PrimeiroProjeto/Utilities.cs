using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeiroProjeto.aa
{

    public class  UtilitiesConstrutor
    {
        int numero;
        
        public UtilitiesConstrutor(string mensagem)
        {
            Console.WriteLine("Esta é uma string: " + mensagem);
          
        }
        public UtilitiesConstrutor(bool mensagem)
        {
            Console.WriteLine("Esta é uma bool: " + mensagem);
        }
        public UtilitiesConstrutor(float mensagem)
        {
            Console.WriteLine("Esta é uma float: " + mensagem);
        }
        public UtilitiesConstrutor(string mensagem, string mensagem2)
        {
            Console.WriteLine("Estas são duas string: " + mensagem + ", " + mensagem2);

        }


    }


    public static class Utilities
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
