using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimeiroProjeto
{
    public static class Contar_1Milhao_1
    {
        private static long _resultado;
        public static long resultado
        {
            get { return _resultado; }
            set { _resultado = value; }
        }
        public static void IniciarContagem()
        {
            for(long i = 1; i <= 10; i++)
            {
                resultado++;
                Thread.Sleep(500);
                Console.WriteLine($"Contagem 1: {resultado}");
            }
        }
    }

    public static class Contar_1Milhao_2
    {
        private static long _resultado;
        public static long resultado
        {
            get { return _resultado; }
            set { _resultado = value; }
        }
        public static void IniciarContagem()
        {
            for (long i = 1; i <= 10; i++)
            {

                Thread.Sleep(500); // Simula um atraso de 1 segundo
                resultado++;
                Console.WriteLine($"Contagem 2: {resultado}");
            }
        }
    }

}
