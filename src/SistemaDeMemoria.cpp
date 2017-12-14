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

void SistemaDeMemoria::adicionaNaMemoria(list<string> &listaParaAdicionarNaMemoria){
    listasNaMemoriaString[id] = listaParaAdicionarNaMemoria;
    id++;
}

void SistemaDeMemoria::mostraListasNaMemoria(){

    /*for(auto& lista : listasNaMemoria){
        cout << lista.first << " => ";
        exibeLista(lista.second);
    }
    for(auto& lista : listasNaMemoriaString){
        cout << lista.first << " => ";
        exibeLista(lista.second);
    }*/

   /* map<int, list<int> >::iterator itNumerico = listasNaMemoria.begin();
    map<int, list<string> >::iterator itString = listasNaMemoriaString.begin();

    for(; itNumerico != listasNaMemoria.end(), itString != listasNaMemoriaString.end(); ++itNumerico, ++itString){
        if(itNumerico->first < itString->first){
            cout << itNumerico->first << " => ";
            exibeLista(itNumerico->second);
            cout << itString->first << " => ";
            exibeLista(itString->second);
        }else{
            cout << itString->first << " => ";
            exibeLista(itString->second);
            cout << itNumerico->first << " => ";
            exibeLista(itNumerico->second);
        }


    }*/

    for(int i = 1; i < id; i++){
        if(listasNaMemoria.find(i) != listasNaMemoria.end()){
            cout << i << " => ";
            exibeLista(listasNaMemoria[i]);
        }else{
            cout << i << " => ";
            exibeLista(listasNaMemoriaString[i]);
        }

    }

}

// ESTOU TESTANDO APENAS OS ELEMENTOS QUE EXISTEM NA MEMORIA DE LISTAS NUMERICAS
// JÁ QUE O ID DAS LISTAS É ÚNICO NAS DUAS MEMORIAS E, POR EXCLUSAO, SE UM ID
// ESTA NUMA LISTA, NAO ESTARA NA OUTRA, O QUE IRA RETORNAR VAZIO
int SistemaDeMemoria::verificaSeListaExisteNaMemoria(int idLista){

    map<int, list<int> >::iterator verificaSeExiste;

    verificaSeExiste = listasNaMemoria.find(idLista);

    if(verificaSeExiste != listasNaMemoria.end()){
        return 1;
    }else{
        return 0;
    }

}


list<int> SistemaDeMemoria::retornaLista(int idLista){
    return listasNaMemoria[idLista];
}

list<string> SistemaDeMemoria::retornaListaString(int idLista){
    return listasNaMemoriaString[idLista];
}



void SistemaDeMemoria::exibeLista(list<int> listaParaExibir){

    // DECLARACAO DE VARIAVEIS
    int inicio_aux = listaParaExibir.front();
    int fim_aux = listaParaExibir.back();

    listaParaExibir.pop_front();
    listaParaExibir.pop_back();
    cout << inicio_aux << ",";
    for(auto elemento : listaParaExibir){
        cout << elemento<< ",";
    }

    cout << fim_aux << endl;

}

void SistemaDeMemoria::exibeLista(list<string> listaParaExibir){
    // DECLARACAO DE VARIAVEIS
    string inicio_aux = listaParaExibir.front();
    string fim_aux = listaParaExibir.back();

    listaParaExibir.pop_front();
    listaParaExibir.pop_back();
    cout << inicio_aux << ",";
    for(auto elemento : listaParaExibir){
        cout << elemento<< ",";
    }

    cout << fim_aux << endl;

}

int SistemaDeMemoria::retornaUltimoIdValido(){
    return id;
}



