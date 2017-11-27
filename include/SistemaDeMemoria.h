#ifndef SISTEMADEMEMORIA_H
#define SISTEMADEMEMORIA_H
#include <map>
#include <list>
#include <iostream>

using namespace std;

class SistemaDeMemoria
{

    map<int, list<int> > listasNaMemoria;
    int id;

    public:
        SistemaDeMemoria();
        virtual ~SistemaDeMemoria();
        void adicionaNaMemoria(list<int> &listaParaAdicionarNaMemoria);
        void mostraListasNaMemoria();
        void deletaDaMemoria(list<int> listaParaDeletar);
        list<int> retornaLista(int idLista);

    protected:

    private:
};

#endif // SISTEMADEMEMORIA_H
