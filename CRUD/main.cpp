#include "Servidor.h"
#include "Mago.h"
#include "Guerreiro.h"
#include "Ladrao.h"

#include <stdio.h>

using namespace std;

int main() {

    char op;
    int pos;
    string atributos;
    string nome;
    
    Servidor servidor("info.dat");
    do {
        op = toupper(Servidor::opcao());
        switch (op) {
            case 'I': { 
                servidor.imprime();
                break;
            }
            case 'C': {
                cout << "Nome: ";
                cin >> nome;
                servidor.imprime(nome);
                break;
            }
            case 'O': {
                servidor.imprime(true);
                break;
            }
            case 'M': {
                servidor.adiciona(MAGO);
                break;
            }
            case 'G': {
                servidor.adiciona(GUERREIRO);
                break;
            }
            case 'L': {
                servidor.adiciona(LADRAO);
                break;
            }
            case 'S': {
                cout << "Nome: ";
                cin >> nome;
                bool ok = servidor.atualiza(nome);
                cout << "Atualização " << (ok ? "ok" : "não ok") << endl;
                break;
            }
            case 'E': {
                servidor.exclui("info.dat");
                break;
            }
            case 'R': {
                cout << "Nome: ";
                cin >> nome;
                bool ok = servidor.remove(nome);
                cout << "Remoção " << (ok ? "ok" : "não ok") << endl;
                break;
            }
            case 'F': {
                break;
            }
            default: {
                cout << "Insira um código válido" << endl;
            }
        }
        cout << endl;
    } while (op != 'F');

    return 0;
}