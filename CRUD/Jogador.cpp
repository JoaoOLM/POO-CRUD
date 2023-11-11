#include "Jogador.h"


Jogador::Jogador(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano) : username(username), nivel(nivel), vitalidade(vitalidade), mente(mente), 
     tenacidade(tenacidade), forca(forca), destreza(destreza), inteligencia(inteligencia), fe(fe), arcano(arcano){
}

Jogador::~Jogador(){
}

string Jogador::getUsername() const{
    return this->username;
}

void Jogador::setUsername(string nome)
{
    this->username = nome;
}

int Jogador::getNivel() const
{
    return this->nivel;
}

void Jogador::setNivel(int lvl)
{
    this->nivel = lvl;
}

int Jogador::getVitalidade() const
{
    return this->vitalidade;
}

void Jogador::setVitalidade(int vit)
{
    this->vitalidade = vit;
}

int Jogador::getMente() const
{
    return this->mente;
}

void Jogador::setMente(int mind)
{
    this->mente = mind;
}

int Jogador::getTenacidade() const
{
    return this->tenacidade;
}

void Jogador::setTenacidade(int tct)
{
    this->tenacidade = tct;
}

int Jogador::getForca() const
{
    return this->forca;   
}

void Jogador::setForca(int strg)
{
    this->forca = strg;
}

int Jogador::getDestreza() const
{
    return this->destreza;
}

void Jogador::setDestreza(int dex)
{
    this->destreza = dex;
}

int Jogador::getInteligencia() const
{
    return this->inteligencia;
}

void Jogador::setInteligencia(int intel)
{
    this->inteligencia = inteligencia;
}

int Jogador::getFe() const
{
    return this->fe;
}

void Jogador::setFe(int fe)
{
    this->fe = fe;
}

int Jogador::getArcano() const
{
    return this->arcano;
}

void Jogador::setArcano(int arc)
{
    this->arcano = arc;
}

void Jogador::imprime() const
{
    string tipo;
    cout << "Username: " << this->username << endl;
    cout << "Nível: " << this->nivel << endl;
    switch (getClasse()){
        case MAGO: {
            tipo = "Mago";
            break;
        }
        case GUERREIRO: {
            tipo = "Guerreiro";
            break;
        }
        case LADRAO: {
            tipo = "Ladrão";
            break;
        }
    }
    cout << "Classe: " << tipo << endl;
    cout << "Vitalidade : " << this->vitalidade << endl;
    cout << "Mente: " << this->mente << endl;
    cout << "Tenacidade: " << this->tenacidade << endl;
    cout << "Força: " << this->forca << endl;
    cout << "Destreza: " << this->destreza << endl;
    cout << "Inteligência: " << this->inteligencia << endl;
    cout << "Fé: " << this->fe << endl;
    cout << "Arcano: " << this->arcano << endl;
    this->imprime();
    cout << endl;

}

bool Jogador::comparaNome(Jogador* j1, Jogador* j2)
{
    return j1->username < j2->username;
}
