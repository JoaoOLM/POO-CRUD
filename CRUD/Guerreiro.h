#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "Jogador.h"

using namespace std;

class Guerreiro : public Jogador{
public:
    Guerreiro(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int armadura);
    virtual ~Guerreiro();
    virtual int getClasse()const;
    int getArmadura()const;
    void setArmadura(int armor);
    virtual void imprime() const;
private:
    int armadura;
};

#endif /* GUERREIRO_H */