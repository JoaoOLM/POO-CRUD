#include "Servidor.h"
#include "Mago.h"
#include "Guerreiro.h"
#include "Ladrao.h"

using namespace std;

Servidor::Servidor(string fileName) : fileName(fileName) {
    recupera();
}

Servidor::~Servidor() {}

void Servidor::grava() {

    string nome;
    int tipo, tam, nivel, vitalidade, mente, tenacidade, forca, destreza, inteligencia, fe, arcano, mana, armadura, furtividade;
    Mago *m1;
    Guerreiro *g1;
    Ladrao *l1;

    ofstream saida(fileName, ios::binary);

    for (long unsigned int i = 0; i < jogadores.size(); i++)  {

        // Escrevendo o tipo de jogador (Mago, Guerreiro, Ladrão)
        tipo = jogadores[i]->getClasse();
        saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        // Escrevendo o Nível
        nivel = jogadores[i]->getNivel();
        saida.write(reinterpret_cast<char *>(&nivel), sizeof(nivel));

        // Escrevendo o Nome
        nome = jogadores[i]->getUsername();
        tam = nome.size();

        // Escrevendo o tamanho da string (nome)
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));

        // Escrevendo os caracteres da string (nome)
        saida.write(reinterpret_cast<char *>(&nome[0]), tam);

        // Escrevendo a vitalidade
        vitalidade = jogadores[i]->getVitalidade();
        saida.write(reinterpret_cast<char *>(&vitalidade), sizeof(vitalidade));

        // Escrevendo a mente
        mente = jogadores[i]->getMente();
        saida.write(reinterpret_cast<char *>(&mente), sizeof(mente));

        // Escrevendo a tenacidade
        tenacidade = jogadores[i]->getTenacidade();
        saida.write(reinterpret_cast<char *>(&tenacidade), sizeof(tenacidade));

        // Escrevendo a força
        forca = jogadores[i]->getForca();
        saida.write(reinterpret_cast<char *>(&forca), sizeof(forca));

        // Escrevendo a destreza
        destreza = jogadores[i]->getDestreza();
        saida.write(reinterpret_cast<char *>(&destreza), sizeof(destreza));

        // Escrevendo a inteligência
        inteligencia = jogadores[i]->getInteligencia();
        saida.write(reinterpret_cast<char *>(&inteligencia), sizeof(inteligencia));

        // Escrevendo a fé
        fe = jogadores[i]->getFe();
        saida.write(reinterpret_cast<char *>(&fe), sizeof(fe));

        // Escrevendo a arcano
        arcano = jogadores[i]->getArcano();
        saida.write(reinterpret_cast<char *>(&arcano), sizeof(arcano));

        switch (tipo) {
            case MAGO: {
                // Escrevendo a Mana
                m1 = dynamic_cast<Mago *>(jogadores[i]);
                mana = m1->getMana();
                saida.write(reinterpret_cast<char *>(&mana), sizeof(mana));

                break;
            }
            case GUERREIRO: {
                // Escrevendo a Armadura
                g1 = dynamic_cast<Guerreiro *>(jogadores[i]);
                armadura = g1->getArmadura();
                saida.write(reinterpret_cast<char *>(&armadura), sizeof(armadura));

             break;
            }
            case LADRAO: {
                // Escrevendo a Furtividade
                l1 = dynamic_cast<Ladrao *>(jogadores[i]);
                furtividade = l1->getFurtividade();
                saida.write(reinterpret_cast<char *>(&furtividade), sizeof(furtividade));

            }
        }
    }

    saida.close();
}

void Servidor::recupera() {

    string nome;
    int tipo, tam, nivel, vitalidade, mente, tenacidade, forca, destreza, inteligencia, fe, arcano, mana, armadura, furtividade;

    ifstream entrada(fileName, ios::binary);
    
    if (entrada.is_open()) {

        jogadores.clear();

        // Lendo o tipo
        entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (entrada.good()) {

            // Lendo o Nível
            entrada.read(reinterpret_cast<char *>(&nivel), sizeof(nivel));

            // Lendo o nome

            // Lendo o tamanho da string (nome)
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);

            // Lendo os caracteres da string (nome)
            entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            // Lendo a vitalidae
            entrada.read(reinterpret_cast<char *>(&vitalidade), sizeof(vitalidade));

            // Lendo a mente
            entrada.read(reinterpret_cast<char *>(&mente), sizeof(mente));
            
            // Lendo a tenacidae
            entrada.read(reinterpret_cast<char *>(&tenacidade), sizeof(tenacidade));

            // Lendo a força
            entrada.read(reinterpret_cast<char *>(&forca), sizeof(forca));

            // Lendo a destreza 
            entrada.read(reinterpret_cast<char *>(&destreza), sizeof(destreza));

            // Lendo a inteligência
            entrada.read(reinterpret_cast<char *>(&inteligencia), sizeof(inteligencia));

            // Lendo a fé
            entrada.read(reinterpret_cast<char *>(&fe), sizeof(fe));

            // Lendo o arcano
            entrada.read(reinterpret_cast<char *>(&arcano), sizeof(arcano));

            switch (tipo) {
                case MAGO: {

                    // Lendo a Mana
                    entrada.read(reinterpret_cast<char *>(&mana), sizeof(mana));

                    jogadores.push_back(new Mago(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, mana));
                    break;
                }
                case GUERREIRO: {

                    // Lendo a Armadura
                    entrada.read(reinterpret_cast<char *>(&armadura), sizeof(armadura));

                    jogadores.push_back(new Guerreiro(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, armadura));
                    break;
                }
                case LADRAO: {

                    // Lendo a Furtividade
                    entrada.read(reinterpret_cast<char *>(&furtividade), sizeof(furtividade));

                    jogadores.push_back(new Ladrao(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, furtividade));
                    break;
                }
            }

            // Lendo o tipo
            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }
    entrada.close();
}

bool Servidor::adiciona(int tipo) {
    string nome;
    int tam, nivel, vitalidade, mente, tenacidade, forca, destreza, inteligencia, fe, arcano, mana, armadura, furtividade;
    Jogador* j;

    cin.ignore();
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Nivel: ";
    cin >> nivel;
    cout << "Vitalidade: ";
    cin >> vitalidade;
    cout << "Mente: ";
    cin >> mente;
    cout << "Tenacidae: ";
    cin >> tenacidade;
    cout << "Força: ";
    cin >> forca;
    cout << "Destreza: ";
    cin >> destreza;
    cout << "Inteligencia: ";
    cin >> inteligencia;
    cout << "Fé: ";
    cin >> fe;
    cout << "Arcano: ";
    cin >> arcano;

    switch(tipo) {
        case MAGO: {
            cout << "Mana: ";
            cin >> mana;
            j = new Mago(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, mana);
            break;
        }
        case GUERREIRO: {
            cout << "Armadura: ";
            cin >> armadura;
            j = new Guerreiro(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, armadura);
            break;
        }
        case LADRAO: {
            cout << "Furtividade: ";
            cin >> furtividade;
            j = new Ladrao(nome, nivel, vitalidade, mente, tenacidade, forca, destreza, 
                        inteligencia, fe, arcano, furtividade);
            break;
        }
    }

    jogadores.push_back(j);
    grava();
    return true;
}

bool Servidor::atualiza(string username) {
    int valor;
    bool ok = false;
    int pos = indice(username);
    int atributo;
    int tipo = jogadores[pos]->getClasse();

    if (pos != -1) {
        cout << "Qual atributo você deseja atualizar?" << endl;
        cout << "[1] Nível" << endl;
        cout << "[2] Vitalidade" << endl;
        cout << "[3] Mente" << endl;
        cout << "[4] Tenacidade" << endl;
        cout << "[5] Forca" << endl;
        cout << "[6] Destreza" << endl;
        cout << "[7] Inteligência" << endl;
        cout << "[8] Fé" << endl;
        cout << "[9] Arcano" << endl;
        switch (jogadores[pos]->getClasse()){
            case (MAGO):{
                cout << "[10] Mago" << endl;
                break;
            }case (GUERREIRO):{
                cout << "[10] Guerreiro" << endl;
                break;
            }case (LADRAO):{
                cout << "[10] Ladão" << endl;
                break;
            }
        }
        cin >> atributo;
        cout << "Insira o valor a ser atualizado: " ;
        cin >> valor;
        switch (atributo){
            case (1):{
                jogadores[pos]->setNivel(valor);
                break;
            }case(2):{
                jogadores[pos]->setVitalidade(valor);
                break;
            }case(3):{
                jogadores[pos]->setMente(valor);
                break;
            }case(4):{
                jogadores[pos]->setTenacidade(valor);
                break;
            }case(5):{
                jogadores[pos]->setForca(valor);
                break;
            }case(6):{
                jogadores[pos]->setDestreza(valor);
                break;
            }case(7):{
                jogadores[pos]->setInteligencia(valor);
                break;
            }case(8):{
                jogadores[pos]->setFe(valor);
                break;
            }case(9):{
                jogadores[pos]->setArcano(valor);
                break;
            }case(10):{
                switch (jogadores[pos]->getClasse()){
                    case (MAGO):{
                        Mago *m = dynamic_cast<Mago *>(jogadores[pos]);
                        m->setMana(valor);
                        break;
                    }case (GUERREIRO):{
                        Guerreiro *g = dynamic_cast<Guerreiro *>(jogadores[pos]);
                        g->setArmadura(valor);
                        break;
                    }case (LADRAO):{
                        Ladrao *l = dynamic_cast<Ladrao *>(jogadores[pos]);
                        l->setFurtividade(valor);
                        break;
                    }
                }
            }
        }
        grava();
        ok = true;
    }

    return ok;
}

bool Servidor::remove(string username) {
    bool ok = false;
    int pos = indice(username);

    if (pos != -1) {
        jogadores.erase(jogadores.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

void Servidor::exclui(string fileName)
{
    ifstream entrada(fileName, ios::binary);
    std::remove(fileName.c_str());
    jogadores.clear();
    entrada.close();
}

int Servidor::indice(string username) {
    long unsigned int tam = jogadores.size();
    long unsigned int pos = 0;

    while (pos < tam && jogadores[pos]->getUsername() != username) {
        pos++;
    }

    if (pos < tam) {
        return pos;
    } else {
        return -1;
    }
}

void Servidor::imprime(string username) {
    int pos = indice(username);

    if (pos != -1) {
        jogadores[pos]->Jogador::imprime();
    } else {
        cout << "Nome não encontrado";
    }
}

void Servidor::imprime(bool sorted) {
    vector<Jogador*> copia = jogadores;
    if (sorted) {
        sort(copia.begin(), copia.end(), Jogador::comparaNome);
    }
    for (long unsigned int i = 0; i < copia.size(); i++) {
        copia[i]->Jogador::imprime();
        cout << endl;
    }
}

char Servidor::opcao() {
    char c;
    cout << "[I] Imprime todos" << endl;
    cout << "[C] Imprime por Nome" << endl;
    cout << "[O] Imprime ordenado (Nome)" << endl;
    cout << "[M] Adiciona Mago" << endl;
    cout << "[G] Adiciona Guerreiro" << endl;
    cout << "[L] Adiciona Ladrão" << endl;
    cout << "[S] Atualiza Atributos (por Nome)" << endl;
    cout << "[R] Remove (por Nome)" << endl;
    cout << "[E] Exclui o arquivo dos jogadores" << endl;
    cout << "[F] Fim" << endl;
    cout << "> ";
    cin >> c;
    return (toupper(c));
}