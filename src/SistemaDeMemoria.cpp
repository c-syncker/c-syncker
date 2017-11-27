#include "SistemaDeMemoria.h"

SistemaDeMemoria::SistemaDeMemoria()
{
    id = 1;
}

SistemaDeMemoria::~SistemaDeMemoria()
{
    //dtor
}


void SistemaDeMemoria::adicionaNaMemoria(list<int> &listaParaAdicionarNaMemoria){
    listasNaMemoria[id] = listaParaAdicionarNaMemoria;
    id++;
}


void SistemaDeMemoria::mostraListasNaMemoria(){
    list<int> listaAux;
    for (map<int, list<int> >::iterator lista=listasNaMemoria.begin(); lista!=listasNaMemoria.end(); ++lista){
        cout << lista->first << " => ";
        listaAux = lista->second;
        for(auto iterador : listaAux){
            cout << iterador << ",";
        }
        cout << endl;
    }
}

list<int> SistemaDeMemoria::retornaLista(int idLista){
    return listasNaMemoria[idLista];
}
