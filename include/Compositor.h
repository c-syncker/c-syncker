#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <iostream>
#include "Nota.h"
#include <list>	
#include <map>
#include <string>
#include "Notas.h"

using namespace std;

class Compositor
{

    map<int, list<Nota> > notas;
    list<int> duracoes;
    list<string> alturas;
    list<string> listaDeIDs;
    list<int> intensidades;
    list<Nota> listaDeNotas;
    Notas conjuntoDeNotas;

    public:

        Compositor();
        virtual ~Compositor();
        void associar(list<string> &alturas, list<int> &duracoes);
        void associar(list<string> &alturas, list<int> &duracoes, list<int> &intensidades);
        void desassociar(list<Nota> &listaDeNotas);
        void desassociar(Nota nota);

        list<Nota>   *pegueListaDeNotas();
        list<int>    *pegueListaDuracoes();
        list<int>    *pegueListaIntensidades();
        list<string> *pegueListaAlturas();
        list<string> *pegueListaDeIDs();

        void atribuaNotas(Notas &notas);
        void limpeListaDeNotas();
    private:
};

#endif // COMPOSITOR_H
