using System.Diagnostics;
using System.Security.AccessControl;
using PrimeiroProjeto.aa;
using System.Threading;


namespace PrimeiroProjeto
{
    internal partial class Program
    {
        static void Main(string[] args)
        {
            //List<string> ListaDasBandas = new List<string> {"Twenty one Pilots","Red Hot Chili Peppers", "alt-J" };
            //bandasRegistradas.Add("Twenty one Pilots", new List<int> { 10, 5, 7 }); ;
            //bandasRegistradas.Add("Red Hot Chili Peppers", new List<int>()); 
            
            
            Thread t1 = new Thread(Contar_1Milhao_1.IniciarContagem);
            Thread t2 = new Thread(Contar_1Milhao_2.IniciarContagem);




            Stopwatch sw = new Stopwatch();
            sw.Start();

            t1.Start(); // Inicia a Thread 1
            t2.Start(); // Inicia a Thread 2

            // Espera as duas terminarem
            t1.Join();
            t2.Join();

            
            /*
            Stopwatch sw = new Stopwatch();
            sw.Start();


            Contar_1Milhao_1.IniciarContagem();
            Contar_1Milhao_2.IniciarContagem();
            */


            sw.Stop();
            Console.WriteLine("Tempo do script: " + sw.ElapsedMilliseconds + "ms");

            //Program Program = new Program();
            //Program.ExibirMensagemDeBoasVindas();


        }






    }
}
