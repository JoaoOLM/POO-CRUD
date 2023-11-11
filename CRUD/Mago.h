#ifndef MAGO_H
#define MAGO_H

#include "Jogador.h"

using namespace std;

class Mago : public Jogador{
public:
    Mago(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int mana);
    virtual ~Mago();
    virtual int getClasse()const;
    int getMana()const;
    void setMana(int mana);
    virtual void imprime() const;
private:
    int mana;
};

#endif /* MAGO_H */