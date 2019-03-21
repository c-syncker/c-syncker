#ifndef NOTA_H
#define NOTA_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "pugiconfig.hpp"
#include "pugixml.hpp"

using namespace std;
using namespace pugi;

class Nota
{

    unordered_map<string, int> dicionarioAlturasCifradasNumerosMIDI; 

    string altura;
    string acidente1;
    string acidente2;
    string indice;
    string id;
    int oitava;
    int duracao;
    int intensidade;
    int alturaNumerica;
    string idPai; // referencia a que nó do Freeplane essa nota pertence

    public:
        Nota();
        virtual ~Nota();
        string toString();
        
        void atribuaAltura(string altura);
        void atribuaAcidente1(string acidente1);
        void atribuaAcidente2(string acidente2);
        void atribuaOitava(int oitava);
        void atribuaDuracao(int duracao);
        void atribuaIntensidade(int intensidade);
        void atribuaAlturaNumerica(int alturaNumerica);
        void atribuaNoPai(string no);
        void atribuaIndice(string indice);
        void atribuaID(string id);

        int pegueOitava();
        int pegueDuracao();
        int pegueIntensidade();
        int pegueAlturaNumerica();
        string pegueAltura();
        string pegueAcidente1();
        string pegueAcidente2();
        string pegueIndice();
        string pegueNoPai();
        string pegueID();
    

    protected:

    private:
};

#endif // NOTA_H
