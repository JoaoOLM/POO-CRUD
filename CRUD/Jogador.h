#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum TIPO { MAGO, GUERREIRO, LADRAO };

class Jogador {
public:
    Jogador(string username, int nivel, int vitalidade, int mente, int tenacidade, int forca, int destreza, 
     int inteligencia, int fe, int arcano);
    virtual ~Jogador();
    string getUsername()const;
    void setUsername(string nome);
    int getNivel()const;
    void setNivel(int lvl);
    int getVitalidade()const;
    void setVitalidade(int vit);
    int getMente()const;
    void setMente(int mind);
    int getTenacidade()const;
    void setTenacidade(int tct);
    int getForca()const;
    void setForca(int strg);
    int getDestreza()const;
    void setDestreza(int dex);
    int getInteligencia()const;
    void setInteligencia(int intel);
    int getFe()const;
    void setFe(int fe);
    int getArcano()const;
    void setArcano(int arc);
    virtual void imprime()const;
    virtual int getClasse() const = 0; // Método Abstrato

    static bool comparaNome(Jogador* j1, Jogador* j2);
private:
    string username;
    int nivel;
    int vitalidade;
    int mente;
    int tenacidade;
    int forca;
    int destreza;
    int inteligencia;
    int fe;
    int arcano;
};

#endif /* JOGADOR_H */