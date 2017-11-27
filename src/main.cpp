#include <iostream>
#include "Sincronizador.h"
#include "Escriba.h"
#include "ProcessaEntrada.h"
#include "SistemaDeMemoria.h"
#include <list>
#include <string>
#include <ctype.h>
#include <sstream>




// TODO: Criar uma classe que somente lê listas informadas pelo usuário
// em diversas sintaxes e "quebra em listas que possam ser processadas
// olhar o arquivo main1.cpp no dropbox

using namespace std;

void exibeMenu(){

    cout << "1) Informar listas (enter, informa; fração é métrica, esc, sai)" << endl;
    cout << "2) Sincronizar listas" << endl;
    cout << "3) Derivar listas numéricas" << endl;
    cout << "4) Acumular lista" << endl;
    cout << "5) Reverter lista" << endl;
    cout << "6) Recuperar" << endl;
    cout << "Esc para encerrar" << endl;

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

                    //for (auto alturaInteiro:listaAlturasInteirosSaida){
                    //   cout << alturaInteiro << endl;
                   // }

                }else if(opcaoMenuInterno == 2){
                    cin >> text;
                    processadorDeEntradas.verificaEntrada(text, opcaoMenuInterno);
                    duracoes = processadorDeEntradas.retornaDuracoes();

                    registradorDeListas.adicionaNaMemoria(duracoes);


                }



            break;

            case '2':
                cout << "Sincronizar listas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();

                int lista1, lista2;
                cin >> lista1 >> lista2;
                listaAuxiliar1 = registradorDeListas.retornaLista(lista1);
                listaAuxiliar2 = registradorDeListas.retornaLista(lista2);
                syncker.sincronizaListasApenasNumeros(listaAuxiliar1, listaAuxiliar2);

            break;

            case '3':
                cout << "Derivar listas numéricas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();
                cin >> idLista;
                listaAuxiliar1 = registradorDeListas.retornaLista(idLista);
                syncker.calculaDerivadaDiscreta(listaAuxiliar1, listaDerivadas);

            break;

            case '4':
                cout << "Acumular listas numéricas" << endl;
                registradorDeListas.mostraListasNaMemoria();
                cout << "Escolha a lista informando o número ao lado dela" << endl;

                cin >> idLista;
                listaAuxiliar1 = registradorDeListas.retornaLista(idLista);
                syncker.acumuladorDeListas(listaAuxiliar1, listaSaidasAcumuladas);
                for(auto saida:listaSaidasAcumuladas){
                    cout << saida << ",";
                }
                cout << endl;
            break;

            case '5':
                cout << "Reverter listas" << endl;
                registradorDeListas.mostraListasNaMemoria();

            break;

            case '6':
                cout << "Recuperar" << endl;
                registradorDeListas.mostraListasNaMemoria();

            break;

            case 27:
                system("exit");
            break;


        }

    }


    return 0;
}
