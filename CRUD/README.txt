João Otávio Langer de Moraes - 811797
T4 - POO

Esse programa visa simular o funcionamento de um servidor de um jogo online.
Para a implementação desse programa foi feita uma classe "Servidor" na qual é feito o gerenciamento dos Jogadores presentes no jogo.
Os Jogadores podem ser de três tipos: Mago, Guerreiro e Ladrão. Cada um dos tipos possui um atributo diferente dos atributos padrão de 
todos os jogadores.

As classe dos tipos de jogadores possuem um método "imprime" necessário apenas para a impressão dos atributos específicos de cada 
Jogador. Por outro lado, na classe Jogador, existe um método "imprime" responsável pela impressão de todos os outros atributos.
Além disso, na classe Jogador, foi implementado um método de comparação entre os nomes de jogadores para realizar a ordenação dos mesmos.
Na classe "Servidor" foram implementados métodos de leitura, escrita, alteração de atributo, remoção de arquivo, e impressão. 
Por fim, na main os métodos da classe "Servidor" são chamados de acordo com o que é solicitado pelo usuário.

É possível executar o programa através do terminal com o seguinte comando "g++ -o main *.cpp" e depois "./main". Vale ressaltar que 
para executar o código é necessário possuir o compilador "GCC" em sua máquina. 
Para escolher a operação que será realizada basta digitar uma das letras que indica a ação desejada.
Ao final da execução, os jogadores adicionados ficarão salvos em um arquivo binário ("info.dat") para futuras consultas.
