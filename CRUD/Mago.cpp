#include "Mago.h"

Mago::Mago(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int mana): Jogador(username, nivel, vitalidade, mente, tenacidade, forca, destreza, 
     inteligencia, fe, arcano), mana(mana){
}

Mago::~Mago(){
}

int Mago::getClasse() const
{
    return MAGO;
}

int Mago::getMana() const
{
    return this->mana;
}

void Mago::setMana(int mana)
{
    this->mana = mana;
}

void Mago::imprime() const
{
    cout << "Mana: " << this->mana << endl;
}
