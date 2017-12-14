#ifndef SISTEMADEMEMORIA_H
#define SISTEMADEMEMORIA_H
#include <map>
#include <list>
#include <iostream>

using namespace std;

class SistemaDeMemoria
{

    map<int, list<int> > listasNaMemoria;
    map<int, list<string> > listasNaMemoriaString;
    int id;

    public:
        SistemaDeMemoria();
        virtual ~SistemaDeMemoria();
        void adicionaNaMemoria(list<int> &listaParaAdicionarNaMemoria);
        void adicionaNaMemoria(list<string> &listaParaAdicionarNaMemoria);
        void mostraListasNaMemoria();
        void deletaDaMemoria(list<int> listaParaDeletar);
        void deletaDaMemoria(list<string> listaParaDeletar);
        list<int> retornaLista(int idLista);
        list<string> retornaListaString(int idLista);
        int verificaSeListaExisteNaMemoria(int idLista);
        int retornaUltimoIdValido();
    protected:

    private:
       void exibeLista(list<int> listaParaExibir);
       void exibeLista(list<string> listaParaExibir);
};

#endif // SISTEMADEMEMORIA_H
