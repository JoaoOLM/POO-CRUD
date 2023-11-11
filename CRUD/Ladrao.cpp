#include "Ladrao.h"

Ladrao::Ladrao(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int furtividade) : Jogador(username, nivel, vitalidade, mente, tenacidade, forca, destreza, 
     inteligencia, fe, arcano), furtividade(furtividade){
    
}

Ladrao::~Ladrao(){
}

int Ladrao::getClasse() const
{
    return LADRAO;
}

int Ladrao::getFurtividade() const
{
    return this->furtividade;
}

void Ladrao::setFurtividade(int furt)
{
    this->furtividade = furt;
}

void Ladrao::imprime() const
{
    cout << "Furtividade: " << this->furtividade << endl;
}