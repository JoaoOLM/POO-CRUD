#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "Jogador.h"

#include <algorithm>
#include <fstream>

using namespace std;

class Servidor {
public:
    Servidor(string fileName);
    virtual ~Servidor();
    bool adiciona(int tipo);
    void imprime(bool sorted = false);
    void imprime(string username);
    bool remove(string username);
    void exclui(string fileName);
    bool atualiza(string username);
    static char opcao();
private:
    void grava();
    void recupera();
    int indice(string username);

    string fileName;
    vector<Jogador *> jogadores;
};

#endif /* SEVIDOR_H */