#ifndef LADRAO_H
#define LADRAO_H

#include "Jogador.h"

using namespace std;

class Ladrao : public Jogador{
public:
    Ladrao(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int furtividade);
    virtual ~Ladrao();
    virtual int getClasse()const;
    int getFurtividade()const;
    void setFurtividade(int furt);
    virtual void imprime() const;
private:
    int furtividade;
};

#endif /* LADRAO_H */