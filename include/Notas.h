#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include "Nota.h"
#include <regex>
#include <string>

using namespace std;
using namespace pugi;

class Notas
{

    vector<Nota> listaDeNotas;
    vector<string> duracoesString, alturasCifras, alturas;
    vector<int> alturasConvertidasCifrasNumerosMIDI, duracoes;
    unordered_map<string, int> dicionarioAlturasCifradasNumerosMIDI;

    public:
        Notas();
        virtual ~Notas();
        string toString();
        
        void calculeEnarmonia(string entrada, int tam);
        list<Nota> pegueNotas();
        void convertaEmNotas(list<string> &alturas, list<int> &duracoes);
        void convertaEmNotas(list<string> &alturas, list<string> &duracoes);
        void removaChars(string &entrada);
        void limpeListaDeNotas();
    protected:

    private:
        template <typename T>
        vector<T> convertaListEmVector(list<T>);
};

#endif // NOTAS_H
