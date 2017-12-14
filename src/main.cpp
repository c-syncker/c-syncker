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
    //cout << "6) Associar alturas e durações" << endl;
    cout << "6) Escrever partitura" << endl;
    cout << "7) Listas na memória" << endl;
    cout << "Esc para encerrar" << endl;

}


void exibeLista(list<int> listaParaExibir){

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

void exibeLista(list<string> listaParaExibir){
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

int verificaOcorrenciaNegativos( list<int> listaParaVerificar){
    int cont_negativos = 0;
    for(auto elemento : listaParaVerificar){
        if(elemento < 0){
            cont_negativos++;
        }
    }

    if(cont_negativos > 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){




    Sincronizador syncker;
    ProcessaEntrada processadorDeEntradas;
    SistemaDeMemoria registradorDeListas;
    Escriba escritor;


    // *********************************************************//
    //                  DECLARAÇÃO DE VARIÁVEIS                 //
    // *********************************************************//

    list<int> duracoes;
    list<int> listaDerivadas;
    list<int> listaSaidasAcumuladas;
    list<int> listaAlturasInteirosSaida;
    list<int> listaInteirosSincronizados;

    list<int> listaAuxiliar1;
    list<int> listaAuxiliar2;

    list<string> alturas;
    list<string> alturasExtraidasDaMelodia;
    list<string> listaAlturasStringSaida;
    list<string> listaResultanteAlturasDuracoes;
    list<string> listaParaEscreverLilypond;
    list<string> duracoesExtraidasDaMelodia;
    list<string> alturasDerivadasString;

    list<string>::const_iterator inicioLista;

    string entrada_string_usuario, resultanteNotasListaAlturas, intensidade_string, ultimaAlturaListaAlturas;

    char opcaoMenu=0;
    int opcaoMenuInterno, idLista;
    int lista1, lista2, aux, numerador_metrica, intensidade_numerica;
    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE VARIÁVEIS            //
    // *********************************************************//


    while( ((int)(opcaoMenu)) != 27 ){

        exibeMenu();
        cin >> opcaoMenu;

        cout << opcaoMenu << endl;
        switch(opcaoMenu){

            case '1':
                cout << "Informar listas.\n 1) Alturas\n 2) Duracoes\n 3) Métrica (numerador)\n 4) Intensidade" << endl;
                cin >> opcaoMenuInterno;
                if(opcaoMenuInterno == 1){
                    cout << "Informe as alturas\n";
                    cin >> entrada_string_usuario;
                    processadorDeEntradas.verificaEntrada(entrada_string_usuario, opcaoMenuInterno);

                    // lista com alturas numericas
                    listaAlturasInteirosSaida = processadorDeEntradas.retornaAlturasNumericas();

                    // adiciona essa lista no registrador interno
                    // registradorDeListas.adicionaNaMemoria(listaAlturasInteirosSaida);

                    // lista com alturas cifras
                    alturas = processadorDeEntradas.retornaAlturasString();

                    // adiciona a lista de strings equialentes as alturas na memória
                    registradorDeListas.adicionaNaMemoria(alturas);

                    //resetLista(listaAlturasInteirosSaida);
                    resetLista(alturas);

                }else if(opcaoMenuInterno == 2){
                    cout << "Informe as durações\n";
                    cin >> entrada_string_usuario;
                    processadorDeEntradas.verificaEntrada(entrada_string_usuario, opcaoMenuInterno);
                    duracoes = processadorDeEntradas.retornaDuracoes();
                    exibeLista(duracoes);
                    registradorDeListas.adicionaNaMemoria(duracoes);

                    resetLista(duracoes);

                }else if(opcaoMenuInterno == 3){
                    cout << "Informe a métrica\n";
                    cin >> numerador_metrica;
                    cout << "Metrica: " << numerador_metrica<<endl;
                }else{
                    cout << "Escolha:\n 1) Informar como caractere\n 2) Informar como número\n";
                    cin >> opcaoMenuInterno;

                    if(opcaoMenuInterno == 1){
                        cout << "Informe os caracteres\n";
                        cin >> intensidade_string;
                        cout << "Intensidade: " << intensidade_string << endl;
                    }else{
                        cout << "Informe os números\n";
                        cin >> intensidade_numerica;
                        cout << "Intensidade: " << intensidade_numerica << endl;
                    }


                }

            break;

            case '2':
                cout << "Sincronizar listas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();



                cin >> lista1 >> lista2;

                cout << "Resultado da associação" << endl;

                if(registradorDeListas.verificaSeListaExisteNaMemoria(lista1) && registradorDeListas.verificaSeListaExisteNaMemoria(lista2)){
                    listaAuxiliar1 = registradorDeListas.retornaLista(lista1);
                    listaAuxiliar2 = registradorDeListas.retornaLista(lista2);

                    if( verificaOcorrenciaNegativos(listaAuxiliar1) || verificaOcorrenciaNegativos(listaAuxiliar2)){
                        cout << "Listas com valores negativos não são permitidas\n";
                    }else{
                        syncker.sincronizaListasApenasNumeros(listaAuxiliar1, listaAuxiliar2, listaInteirosSincronizados);
                        registradorDeListas.adicionaNaMemoria(listaInteirosSincronizados);
                        exibeLista(listaInteirosSincronizados);
                    }

                }else{

                    if( registradorDeListas.verificaSeListaExisteNaMemoria(lista1) ){

                        listaAuxiliar1 = registradorDeListas.retornaLista(lista1);
                        alturas = registradorDeListas.retornaListaString(lista2);

                    }else{

                        alturas = registradorDeListas.retornaListaString(lista1);
                        listaAuxiliar1 = registradorDeListas.retornaLista(lista2);

                    }
                    if(verificaOcorrenciaNegativos(listaAuxiliar1)){
                        cout << "Listas com valores negativos não são permitidas\n";
                    }else{
                        syncker.associaAlturasDuracoes(alturas, listaAuxiliar1, listaResultanteAlturasDuracoes);
                        registradorDeListas.adicionaNaMemoria(listaResultanteAlturasDuracoes);
                        exibeLista(listaResultanteAlturasDuracoes);
                    }
                }

                resetLista(alturas);
                resetLista(listaResultanteAlturasDuracoes);
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
                registradorDeListas.adicionaNaMemoria(listaDerivadas);
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
                registradorDeListas.adicionaNaMemoria(listaSaidasAcumuladas);
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
                registradorDeListas.adicionaNaMemoria(listaAuxiliar2);
                exibeLista(listaAuxiliar2);

                resetLista(listaAuxiliar1);
                resetLista(listaAuxiliar2);
            break;

            case '6':
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostraListasNaMemoria();

                resultanteNotasListaAlturas = "";

                cout << "Informe a lista\n";
                cin >> lista1;



                if(lista1 > registradorDeListas.retornaUltimoIdValido()){
                    cout << "Número da lista inválido.";
                }else{
                    if(registradorDeListas.verificaSeListaExisteNaMemoria(lista1)){
                       cout << "Informe uma lista válida.\n";
                    }else{
                        alturas = registradorDeListas.retornaListaString(lista1);
                        ultimaAlturaListaAlturas = alturas.back();
                        alturas.pop_back();
                        for(auto nota : alturas){
                            resultanteNotasListaAlturas += nota + ",";
                        }

                            //string ultima_virgula = line.substr(line.find_last_of(','));

                            //int posicao = line.find(ultima_virgula);
                            //cout << "posicao " << posicao <<endl;
                            //line.erase(posicao, line.size());

                        resultanteNotasListaAlturas += ultimaAlturaListaAlturas;

                        cout << resultanteNotasListaAlturas << endl;
                        escritor.separaAlturasDeDuracoes(resultanteNotasListaAlturas, alturasExtraidasDaMelodia, duracoesExtraidasDaMelodia);

                        if(alturasExtraidasDaMelodia.size() == 0 || duracoesExtraidasDaMelodia.size() == 0){
                            cout << "As duas listas precisam ter conteúdo" << endl;
                        }else{

                            exibeLista(alturasExtraidasDaMelodia);
                            exibeLista(duracoesExtraidasDaMelodia);

                            listaParaEscreverLilypond.push_back(R"(\relative c'' {)");


                            entrada_string_usuario = "";

                            entrada_string_usuario = escritor.substituiAlturaCoringaDoDicionarioDeDuracoesString(alturasExtraidasDaMelodia, duracoesExtraidasDaMelodia);
                            //cout << entrada_string_usuario << endl;
                            listaParaEscreverLilypond.push_back(entrada_string_usuario);
                            listaParaEscreverLilypond.push_back("}");
                            escritor.geraArquivoLilypond(listaParaEscreverLilypond, "teste.ly");
                            escritor.initLilypond("teste.ly");
                        }
                    }

                }
                resetLista(listaParaEscreverLilypond);
                resetLista(alturasExtraidasDaMelodia);
                resetLista(duracoesExtraidasDaMelodia);
                resetLista(alturas);


            break;
            case '7':
                registradorDeListas.mostraListasNaMemoria();
            break;
            case 27:
                system("exit");
            break;


        }

    }


    return 0;
}
