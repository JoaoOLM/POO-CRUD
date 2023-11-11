#include "Guerreiro.h"

Guerreiro::Guerreiro(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano, int armadura) : Jogador(username, nivel, vitalidade, mente, tenacidade, forca, destreza, 
     inteligencia, fe, arcano), armadura(armadura){
    
}

Guerreiro::~Guerreiro(){
}

int Guerreiro::getClasse() const
{
    return GUERREIRO;
}

int Guerreiro::getArmadura() const
{
    return this->armadura;
}

void Guerreiro::setArmadura(int armor)
{
    this->armadura = armor;
}

void Guerreiro::imprime() const
{
    cout << "Armadura: " << this->armadura << endl;
}
