
/*
3) Explique o que são processos. Qual a diferença entre processos e threads?
Um processo é um programa em execução.
Uma thread (ou "linha de execução") é a menor unidade de execução dentro de um processo.
Um processo pode ter uma ou várias threads, elas compartilham dados entre si, ja os processos não


9) O que é condição de corrida? Como Evitar esse "efeito"?
 R: Condição de corrida (race condition) é uma situação em sistemas concorrentes onde o 
 comportamento do sistema depende da ordem ou temporização de eventos não controlados, 
 como a execução simultânea de múltiplos processos ou threads que acessam e modificam recursos compartilhados.
 Para evitar condições de corrida, podem ser adotadas várias estratégias, uma delas é o uso 
 de mecanismos de sincronização.


10) Sintetize as etapas principais para criação de uma memória compartilhada nos sistemas UNIX.
       R: 
       1. Criar (ou obter) um segmento de memória compartilhada
       Usa-se a chamada de sistema:
       shmget(key, tamanho, flags)
       key: identificador único (geralmente obtido com ftok()).
       tamanho: tamanho do segmento em bytes.
       flags: permissões + IPC_CREAT se quiser criar.
       Resultado: retorna um shmid (ID do segmento).

       2. Associar o segmento ao espaço de endereçamento do processo
       Usa-se:
       shmat(shmid, endereço, flags)
       Isso mapeia o segmento na memória do processo.
       Retorna um ponteiro (void*) para a área compartilhada.

       3. (Opcional) Sincronizar o acesso
       Memória compartilhada não oferece sincronização automática.
       Então normalmente é preciso usar:
       semáforos, mutexes (POSIX) ou outros métodos de IPC para evitar condições de corrida.

       4. Usar a memória
       Agora os processos podem ler e escrever diretamente na área apontada pelo ponteiro retornado por shmat().

       5. Desassociar o segmento
       Quando o processo termina de usar a memória:
       shmdt(ponteiro)
       Isso remove o mapeamento apenas daquele processo.

       6. Remover o segmento de memória (liberar)
       Depois que todos os processos terminaram:
       shmctl(shmid, IPC_RMID, NULL)
       Isso libera o segmento de memória compartilhada do sistema.

11) Sobre os métodos de sincronização, explique:

       a) O que são mutexes? Como são implementados?
               R: Um mutex (mutual exclusion lock) é um mecanismo de exclusão mútua usado para 
               garantir que apenas um processo ou thread por vez acesse uma seção crítica 
               (um trecho de código que manipula recursos compartilhados, como variáveis, memória ou arquivos).

       b) O que são semáforos? Como são implementados?
               R: Semáforos são variáveis ou tipos de dados abstratos usados para controlar o acesso 
               a recursos compartilhados em ambientes de multiprocessamento. Eles são implementados 
               como contadores inteiros que indicam o número de recursos disponíveis ou o número 
               de processos que podem acessar um recurso simultaneamente.
       c) Não sua opinião Mutex e semáforo binário são a mesma coisa?
               R: Não, mutex e semáforo binário não são a mesma coisa. Embora ambos sejam usados 
               para controle de acesso a recursos compartilhados, eles têm diferenças importantes. 
               Um mutex é usado para garantir exclusão mútua, permitindo que apenas um thread 
               acesse uma seção crítica por vez. Já um semáforo binário pode ser usado para 
               controlar o acesso a um recurso compartilhado, mas não necessariamente garante 
               exclusão mútua, pois pode permitir que múltiplos threads acessem o recurso 
               simultaneamente, dependendo do valor do semáforo.

               A diferença mais importante é o ownership:
               → Mutex tem dono: quem dá lock precisa dar unlock.
               → Semáforo não tem dono.

       d) Além desses dois métodos, qual seria uma outra alternativa para sincronização de processos?
              R Algoritmo de Peterson porém ele não é muito utilizado na prática, devido a limitações de escalabilidade 
              e desempenho em sistemas modernos. Outra alternativa mais prática seria o uso de monitores, barreiras 
              ou variáveis de condição.

12) Em sistemas operacionais o que são PIPEs. Cite as características principais de um PIPE, e explique o seu funcionamento.
       R: PIPEs são mecanismos de comunicação entre processos (IPC - Inter-Process Communication) 
       que permitem a transferência de dados de um processo para outro de forma unidirecional.
       
       Características principais:
       1. Unidirecionalidade: Os dados fluem em uma única direção, do processo de escrita para o processo de leitura.
       2. Bufferização: Os dados escritos em um PIPE são armazenados em um buffer temporário, permitindo que o processo de leitura
       leia os dados em um momento posterior.
       3. Comunicação entre processos relacionados: PIPEs são frequentemente usados para comunicação entre processos que
       têm uma relação de pai-filho.
       4. Simplicidade: PIPEs são fáceis de usar e implementar, tornando-os uma escolha popular para comunicação entre processos.

       Funcionamento:
       1. Criação do PIPE: Um PIPE é criado usando a chamada de sistema pipe(), que retorna dois descritores de arquivo: um para leitura e outro para escrita.
    R: PIPEs são mecanismos de comunicação entre processos (IPC - Inter-Process Communication) 
    que permitem a transferência de dados de um processo para outro de forma unidirecional.
           
    Características principais:
    1. Unidirecionalidade: Os dados fluem em uma única direção, do processo de escrita para o processo de leitura.
    2. Bufferização: Os dados escritos em um PIPE são armazenados em um buffer temporário, permitindo que o processo de leitura leia os dados em um momento posterior.
    3. Comunicação entre processos relacionados: PIPEs são frequentemente usados para comunicação entre processos que têm uma relação de pai-filho.
    4. Simplicidade: PIPEs são fáceis de usar e implementar, tornando-os uma escolha popular para comunicação entre processos.

    Funcionamento:
    1. Criação do PIPE: Um PIPE é criado usando a chamada de sistema pipe(), que retorna dois descritores de arquivo: um para leitura e outro para escrita.
    2. Escrita no PIPE: O processo de escrita escreve dados no descritor de arquivo de escrita do PIPE (write(fd[1], buf, nbytes)). Se o buffer do PIPE estiver cheio, a chamada de escrita pode bloquear até que haja espaço disponível, ou retornar EAGAIN se for não bloqueante.
    3. Leitura do PIPE: O processo de leitura lê dados do descritor de leitura (read(fd[0], buf, nbytes)). Se não houver dados e todas as extremidades de escrita estiverem fechadas, read() retorna 0 (EOF). Se não houver dados e ainda existirem escritores abertos, a leitura pode bloquear até que dados cheguem.
    4. Fechamento: Cada processo deve fechar a extremidade que não usa (por exemplo, o leitor fecha fd[1], o escritor fecha fd[0]). Fechar todas as extremidades de escrita sinaliza EOF para leitores.
    5. PIPEs nomeados (FIFOs): Ao contrário de PIPEs anônimos criados por pipe(), FIFOs (mkfifo()) existem no sistema de arquivos e permitem comunicação entre processos não relacionados.
    6. Limitações: PIPEs são unidirecionais, têm tamanho de buffer limitado e não preservam mensagens (são stream-oriented). Para comunicação mais complexa (multiplexação, mensagens, sincronização robusta) outros IPCs (sockets, message queues, shared memory + sincronização) podem ser mais adequados.

    13) Explique o que são deadlocks. Como você trataria um deadlock? A sua solução "compensa" computacionalmente falando?
    R: Deadlock é uma situação em sistemas concorrentes onde um conjunto de processos fica permanentemente bloqueado porque cada processo está esperando por um recurso que outro do conjunto detém. As quatro condições de Coffman necessárias para deadlock são: mutual exclusion, hold and wait, no preemption e circular wait.

    Tratamento:
    1. Prevenção: Eliminar ao menos uma das condições de Coffman (ex.: evitar hold-and-wait obrigando processos a requisitar todos os recursos de uma vez ou permitir preempção de recursos). Simples, mas reduz paralelismo e utilização de recursos.
    2. Evitação: Usar algoritmos como o Banker's algorithm que só concedem recursos se o sistema permanecer em estado seguro. Requer conhecimento prévio das necessidades máximas e tem overhead computacional.
    3. Detecção e recuperação: Permitir que deadlocks ocorram, detectá-los (algoritmos de detecção de ciclo ou análise de grafo de alocação) e recuperar matando processos, forçando rollback ou preempção de recursos. Recuperação pode ser complexa e envolver perda de trabalho.
    4. Ignorar: Em muitos sistemas práticos (p. ex. Unix), assume-se que deadlocks são raros e não se faz tratamento automático; operadores humanos resolvem quando ocorrem.

    Custo computacional:
    Nenhuma solução é "gratuitamente" compensadora; há trade-offs. Prevenção e evitação reduzem concorrência e aumentam latência; detecção exige análise periódica e custo de recuperação; nenhuma abordagem é universalmente ótima — a escolha depende do perfil de carga, criticidade de disponibilidade e custo aceitável de sobrecarga.

    14) Qual as principais vantagens de threads de usuário em relação a threads de núcleo? E as principais desvantagens?
    R:
    Vantagens:
    - Criação e troca de contexto rápidas (não requerem chamadas ao kernel).
    - Escalonamento e políticas podem ser implementadas na biblioteca do usuário, permitindo customização.
    - Menor overhead em sistemas com muitas threads leves.

    Desvantagens:
    - Uma chamada de sistema bloqueante bloqueia todo o processo (todas as ULTs) se o kernel não conhece as threads.
    - Não há paralelismo em multiprocessadores sem mapeamento para threads de kernel.
    - Depuração e integração com ferramentas do kernel podem ser mais difíceis.

    15) Qual as principais vantagens de threads de núcleo em relação a threads de usuário? E as principais desvantagens?
    R:
    Vantagens:
    - Suporte a paralelismo real em múltiplos núcleos (kernel agenda cada thread independentemente).
    - Chamadas de sistema bloqueantes afetam apenas a thread que bloqueou.
    - Melhor integração com o sistema operacional (sinais, depuração, prioridade real).

    Desvantagens:
    - Criação e troca de contexto mais pesadas (overhead de kernel).
    - Maior custo em escalabilidade para grande número de threads devido a chamadas ao kernel e sincronização interna.
    - Complexidade e overhead de gerenciamento pelo kernel.


*/

