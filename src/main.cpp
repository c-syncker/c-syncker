#include <iostream>
#include "Sincronizador.h"
#include "Escriba.h"
#include "ProcessaEntrada.h"
#include "SistemaDeMemoria.h"
#include <list>
#include <string>
#include <ctype.h>
#include <sstream>


using namespace std;

void exibeMenu(){

    cout << "1) Informar listas (enter, informa; fração é métrica, esc, sai)" << endl;
    cout << "2) Sincronizar listas" << endl;
    cout << "3) Derivar listas numéricas" << endl;
    cout << "4) Acumular lista" << endl;
    cout << "5) Reverter lista" << endl;
    //cout << "6) Recuperar" << endl;
    cout << "6) Associar alturas e durações" << endl;
    cout << "Esc para encerrar" << endl;

}


void exibeLista(list<int> listaParaExibir){
    int aux;
    aux = *listaParaExibir.rbegin();

    cout << endl;

    for(list<int>::iterator elemento=listaParaExibir.begin(); elemento!=listaParaExibir.end(); ++elemento){
        if(*elemento != aux){
            cout << *elemento << ", ";
        }else{
            cout << *elemento;
        }
    }
    cout << endl;
}

void exibeLista(list<string> listaParaExibir){
    string aux;
    aux = *listaParaExibir.rbegin();

    cout << endl;

    for(list<string>::iterator elemento=listaParaExibir.begin(); elemento!=listaParaExibir.end(); ++elemento){
        if(*elemento != aux){
            cout << *elemento << ", ";
        }else{
            cout << *elemento;
        }
    }
    cout << endl;
}

void resetLista(list<int> &entrada){
    while(entrada.begin() != entrada.end()){
        entrada.pop_front();
    }
}

void resetLista(list<string> &entrada){
    while(entrada.begin() != entrada.end()){
        entrada.pop_front();
    }
}


int main(){




    Sincronizador syncker;
    ProcessaEntrada processadorDeEntradas;
    SistemaDeMemoria registradorDeListas;


    // *********************************************************//
    //                  DECLARAÇÃO DE VARIÁVEIS                 //
    // *********************************************************//

    list<int> duracoes;
    list<int> listaDerivadas;
    list<int> listaSaidasAcumuladas;
    list<int> listaAlturasInteirosSaida;

    list<int> listaAuxiliar1;
    list<int> listaAuxiliar2;

    list<string> alturas;
    list<string> listaAlturasStringSaida;


    string text, line;

    char opcaoMenu=0;
    int opcaoMenuInterno, idLista;
    int lista1, lista2;
    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE VARIÁVEIS            //
    // *********************************************************//


    while( ((int)(opcaoMenu)) != 27 ){

        exibeMenu();
        cin >> opcaoMenu;

        cout << opcaoMenu << endl;
        switch(opcaoMenu){

            case '1':
                cout << "Informar listas.\n1) Alturas \n2) Duracoes" << endl;
                cin >> opcaoMenuInterno;
                if(opcaoMenuInterno == 1){
                    cin >> text;
                    processadorDeEntradas.verificaEntrada(text, opcaoMenuInterno);

                    // lista com alturas numericas
                    listaAlturasInteirosSaida = processadorDeEntradas.retornaAlturasNumericas();

                    // adiciona essa lista no registrador interno
                    registradorDeListas.adicionaNaMemoria(listaAlturasInteirosSaida);

                    resetLista(listaAlturasInteirosSaida);

                }else if(opcaoMenuInterno == 2){
                    cin >> text;
                    processadorDeEntradas.verificaEntrada(text, opcaoMenuInterno);
                    duracoes = processadorDeEntradas.retornaDuracoes();

                    registradorDeListas.adicionaNaMemoria(duracoes);
                    resetLista(duracoes);

                }



            break;

            case '2':
                cout << "Sincronizar listas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();


                cin >> lista1 >> lista2;
                listaAuxiliar1 = registradorDeListas.retornaLista(lista1);
                listaAuxiliar2 = registradorDeListas.retornaLista(lista2);
                syncker.sincronizaListasApenasNumeros(listaAuxiliar1, listaAuxiliar2);

                resetLista(listaAuxiliar1);
                resetLista(listaAuxiliar2);

            break;

            case '3':
                cout << "Derivar listas numéricas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();
                cin >> idLista;
                listaAuxiliar1 = registradorDeListas.retornaLista(idLista);
                syncker.calculaDerivadaDiscreta(listaAuxiliar1, listaDerivadas);
                exibeLista(listaDerivadas);

                resetLista(listaDerivadas);

            break;

            case '4':
                cout << "Acumular listas numéricas" << endl;
                registradorDeListas.mostraListasNaMemoria();
                cout << "Escolha a lista informando o número ao lado dela" << endl;

                cin >> idLista;
                listaAuxiliar1 = registradorDeListas.retornaLista(idLista);
                syncker.acumuladorDeListas(listaAuxiliar1, listaSaidasAcumuladas);

                exibeLista(listaSaidasAcumuladas);

                resetLista(listaSaidasAcumuladas);
            break;

            case '5':
                cout << "Reverter listas" << endl;
                registradorDeListas.mostraListasNaMemoria();
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                cin >> idLista;
                listaAuxiliar1 = registradorDeListas.retornaLista(idLista);
                syncker.reverteLista(listaAuxiliar1, listaAuxiliar2);

                exibeLista(listaAuxiliar2);

                resetLista(listaAuxiliar1);
                resetLista(listaAuxiliar2);
            break;

            /*case '6':
                cout << "Recuperar" << endl;
                registradorDeListas.mostraListasNaMemoria();

            break;*/

            case '6':
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();


                cin >> lista1 >> lista2;
                listaAuxiliar1 = registradorDeListas.retornaLista(lista2);
                listaAuxiliar2 = registradorDeListas.retornaLista(lista1);
                processadorDeEntradas.converteInteirosParaAlturas(listaAuxiliar2, alturas);
                cout << "Resultado da associação" << endl;
                syncker.associaAlturasDuracoes(alturas, listaAuxiliar1);

                // devo guardar uma referência cruzada na classe SistemaDeMemoria?
                // um dicionário alturas->inteiros e inteiros->alturas?
                // esse conversor me poderia me auxiliar nesse método de sincronizar alturas e durações
                // pois preciso de uma lista de string e outra de inteiros.

                resetLista(listaAuxiliar1);
                resetLista(listaAuxiliar2);
                resetLista(alturas);
            break;

            case 27:
                system("exit");
            break;


        }

    }


    return 0;
}
