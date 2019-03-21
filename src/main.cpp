#include <iostream>
#include "ProcessadorDeListas.h"
#include "Escriba.h"
#include "ProcessadorDeEntradas.h"
#include "GerenciadorDeMemorias.h"
#include "SynckerPlane.h"
#include "Compositor.h"
#include <list>
#include <string>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "Notas.h"
#include <typeinfo>
#include "InterfaceXML.h"

#define LOCAL_ESCAPE_KEY 27

using namespace std;

void exibeMenu(){

    cout << "1) Incluir listas" << endl;
    cout << "2) Sincronizar listas" << endl;
    cout << "3) Obter derivada discreta de primeira ordem" << endl;
    cout << "4) Gerar lista de acumulações" << endl;
    cout << "5) Reverter lista" << endl;
    //cout << "6) Recuperar" << endl;
    //cout << "6) Associar alturas e durações" << endl;
    cout << "6) Escrever partitura" << endl;
    cout << "7) Carregue arquivo Freeplane" << endl;
    //cout << "8) Salvar arquivo" << endl;
    //cout << "9) Abrir arquivo" << endl;
    cout << "e) Excluir uma das listas" << endl;
    //cout << "d) Remover ultima lista" << endl;
    cout << "l) Listas na memória" << endl;
    cout << "Esc para encerrar" << endl;

}

bool vericaSeIDDaListaEValido(int idDaLista, GerenciadorDeMemorias &registradorDeListas){
    if(idDaLista >= registradorDeListas.pegueUltimoIdValido()){
        return false;
    }
    return true;
}

void exibeLista(list<int> listaParaExibir){
    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front() << endl;
    }else{

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
}

void exibeLista(list<string> listaParaExibir){

    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front() << endl;
    }else{
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

void telaInicial()
{
    string lines = "";///NULL string
    ifstream splash("splash.txt");///ifstream used to read ascii art from txt

    cout <<"Presented by...\n" << endl;
    if(splash.is_open())
    {
        while(!splash.eof())///checks to see if End Of File... Loops unil end
        {
            string tempString;
            getline(splash, tempString);///Takes text from document and stores in tempString
            tempString += "\n";///adds Newline

            lines += tempString;///
        }
        cout << lines;
    }
    else
    {
        cout <<"ERROR file could not be loaded or does not exist!\n";
    }
}

void sig_handler(int sig)
{
    cout << "Bye ..." << endl;
    exit(sig);    
}

int separaListaDeNotas(Compositor &composer, list<Nota> &notas, list<string> &alturas, list<int> &duracoes)
{
    composer.desassociar(notas);
    alturas = *composer.pegueListaAlturas();
    duracoes = *composer.pegueListaDuracoes();

    if( alturas.front() == "" )
    {
        return 1; // a lista só contém durações
    }else if(duracoes.front() == 0)
    {
        return 2; // a lista só contém alturas
    }

    return 3; // a lista ou já está sincronizada ou está vazia
}

int main() {

    telaInicial();
    cout << "Bem vindo ao C-Syncker" << endl;
    cout << "Enter, informa; esc, sai\n";

    // *********************************************************//
    //                  DECLARAÇÃO DE VARIÁVEIS                 //
    // *********************************************************//

        // Objetos

            ProcessadorDeListas syncker;
            ProcessadorDeEntradas processadorDeEntradas;
            GerenciadorDeMemorias registradorDeListas;
            Escriba escritor;
            SynckerPlane synckerPlane(&registradorDeListas, &processadorDeEntradas);
            Compositor compositor;
            Notas notas;
            InterfaceXML mmSyncker;
        // Listas
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
            list<string> alturasOrdemInversa;

            list<string>::const_iterator inicioLista;

            list<Nota> listaDeNotas;

        // Tipos Primitivos
            string entrada_string_usuario, resultanteNotasListaAlturas, intensidade_string, ultimaAlturaListaAlturas;
            string caminho;
            char opcaoMenu;
            int opcaoMenuInterno, idLista;
            int lista1, lista2, aux, numerador_metrica, intensidade_numerica;
    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE VARIÁVEIS            //
    // *********************************************************//


    processadorDeEntradas.atribuaNotas(notas);

    // exibeMenu();
    // cin >> opcaoMenu;

    while( true ){

        exibeMenu();

        cin >> opcaoMenu;

        cout << endl;

        
        switch(opcaoMenu){

            case '1':
                cout << "Informar listas.\n 1) Alturas\n 2) Duracoes\n 3) Métrica (numerador)\n 4) Intensidade" << endl;
                cin >> opcaoMenuInterno;
                if(opcaoMenuInterno == 1){
                    cout << "Informe as alturas\n";
                    cin >> entrada_string_usuario;
                    processadorDeEntradas.verifiqueEntrada(entrada_string_usuario, opcaoMenuInterno);
 
                    // lista com alturas numericas
                    listaAlturasInteirosSaida = processadorDeEntradas.pegueAlturasNumeroMIDI();
 
                    // adiciona essa lista no registrador interno
                    // registradorDeListas.adicioneListaNaMemoria(listaAlturasInteirosSaida);
 
                    // lista com alturas cifras
                    alturas = processadorDeEntradas.pegueAlturasCifradas();
 
                    // teste para composição com lista de notas
                    // listaDeNotas = processadorDeEntradas.pegueNotas();
                    // registradorDeListas.adicioneListaNaMemoria(listaDeNotas);

                    // adiciona a lista de strings equialentes as alturas na memória
                    listaDeNotas = processadorDeEntradas.pegueNotas();
                    registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
 
                    //resetLista(listaAlturasInteirosSaida);
                    resetLista(alturas);
                    listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
 
                }else if(opcaoMenuInterno == 2){
 
                    cout << "Informe as durações\n";
                    cin >> entrada_string_usuario;
                    processadorDeEntradas.verifiqueEntrada(entrada_string_usuario, opcaoMenuInterno);
                    duracoes = processadorDeEntradas.pegueDuracoes();
                    
                    // teste para composição com lista de notas
                    // listaDeNotas = processadorDeEntradas.pegueNotas();
                    // registradorDeListas.adicioneListaNaMemoria(listaDeNotas);

                    exibeLista(duracoes);
                    listaDeNotas = processadorDeEntradas.pegueNotas();
                    registradorDeListas.adicioneListaNaMemoria(listaDeNotas);

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

                resetLista(duracoes);
                resetLista(alturas);
                listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                processadorDeEntradas.limpeListaDeNotas();

            break;

            case '2':
                cout << "Sincronizar listas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostreListasNaMemoria();

                cin >> lista1 >> lista2;
                // fazendo uma correção no número lido pois o índice do vetor começa em 0
                lista1 = lista1-1;
                lista2 = lista2-1;

                


                if( vericaSeIDDaListaEValido(lista1, registradorDeListas) && vericaSeIDDaListaEValido(lista2, registradorDeListas) ){
                    cout << "Processando..." << endl;

                    if( !registradorDeListas.pegueListaDeNotasDaMemoria(lista1).empty() || !registradorDeListas.pegueListaDeNotasDaMemoria(lista2).empty() )
                    {   
                        
                        
                        auto listaNotas1 = registradorDeListas.pegueListaDeNotasDaMemoria(lista1);
                        auto listaNotas2 = registradorDeListas.pegueListaDeNotasDaMemoria(lista2);
                        
                        if( listaNotas1.front().pegueAltura() != "" && listaNotas1.front().pegueDuracao() != 0 )
                        {
                            if( listaNotas2.front().pegueAltura() != "" && listaNotas2.front().pegueDuracao() != 0 )
                            {
                                cout << "Listas já sincronizadas!" << endl;
                                break;
                            }
                        }

                        // testando se a primeira lista passada era uma lista apenas com alturas
                        // se a altura do primeiro elemento não for vazia, salvo todas as alturas para 
                        // sincronizar
                        list<string> alturas1, alturas2;
                        list<int> duracoes1, duracoes2;
                        
                        
                        if ( listaNotas1.front().pegueAltura() != "" )
                        {
                            // varro toda a lista de notas1 e coloco as alturas dentro da lista alturas no formato string
                            for( auto elemento : listaNotas1 )
                            {
                                // lista de alturas extraídas das notas
                                alturas1.push_back(elemento.pegueAltura()+elemento.pegueAcidente1()+elemento.pegueAcidente2()+to_string(elemento.pegueOitava()));
                            }

                        }
                        // testando se a lista passada é uma lista de durações
                        else if( listaNotas1.front().pegueDuracao() != 0 )  
                        {
                            for(auto elemento : listaNotas1)
                            {
                                duracoes1.push_back( elemento.pegueDuracao() );
                            }

                        }
                        
                        if ( listaNotas2.front().pegueAltura() != "" )
                        {
                            // varro toda a lista de notas1 e coloco as alturas dentro da lista alturas no formato string
                            for( auto elemento : listaNotas2 )
                            {
                                // lista de alturas extraídas das notas
                                alturas2.push_back(elemento.pegueAltura()+elemento.pegueAcidente1()+elemento.pegueAcidente2()+to_string(elemento.pegueOitava()));
                            }

                        }
                        // testando se a lista passada é uma lista de durações
                        else if( listaNotas2.front().pegueDuracao() != 0 )  
                        {
                            for(auto elemento : listaNotas2)
                            {
                                duracoes2.push_back( elemento.pegueDuracao() );
                            }

                        }

                        
                        if( !alturas1.empty() && !duracoes2.empty() )
                        {
                            syncker.associeAlturasEduracoes(alturas1,duracoes2,listaResultanteAlturasDuracoes);
                            
                            for(auto elemento : listaResultanteAlturasDuracoes)
                            {
                                notas.calculeEnarmonia(elemento, elemento.size());
                            }
                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        }
                        else if(  !alturas2.empty() && !duracoes1.empty() )
                        {
                            syncker.associeAlturasEduracoes(alturas2,duracoes1,listaResultanteAlturasDuracoes);
                            
                            for(auto elemento : listaResultanteAlturasDuracoes)
                            {
                                notas.calculeEnarmonia(elemento, elemento.size());
                            }
                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        }
                        else if( !duracoes1.empty() && !duracoes2.empty() )
                        {
                            syncker.sincronizeListasNumericas(duracoes1, duracoes2, listaInteirosSincronizados);
                            
                            for(auto elemento : listaInteirosSincronizados)
                            {
                                notas.calculeEnarmonia(to_string(elemento), 1);
                            }
                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                            
                        }
                        
                    }
                    else
                    {
                        
                        if(registradorDeListas.verifiqueSeListaExisteNaMemoria(lista1) && registradorDeListas.verifiqueSeListaExisteNaMemoria(lista2)){
                            listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(lista1);
                            listaAuxiliar2 = registradorDeListas.pegueListaNumericaDaMemoria(lista2);

                            if( verificaOcorrenciaNegativos(listaAuxiliar1) || verificaOcorrenciaNegativos(listaAuxiliar2)){
                                cout << "Listas com valores negativos não são permitidas\n";
                            }else{
                                syncker.sincronizeListasNumericas(listaAuxiliar1, listaAuxiliar2, listaInteirosSincronizados);
                                for(auto elemento : listaInteirosSincronizados)
                                {
                                    notas.calculeEnarmonia( to_string(elemento), 1 );
                                }
                                listaDeNotas = notas.pegueNotas();
                                registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                                //registradorDeListas.imprimaListaNaTela(listaDeNotas);
                            }

                        }
                        
                        else{

                            if( registradorDeListas.verifiqueSeListaExisteNaMemoria(lista1) ){

                                listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(lista1);
                                exibeLista(listaAuxiliar1);
                                alturas = registradorDeListas.pegueListaAlfanumericaDaMemoria(lista2);
                                exibeLista(alturas);
                            }else{

                                alturas = registradorDeListas.pegueListaAlfanumericaDaMemoria(lista1);
                                exibeLista(alturas);
                                listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(lista2);
                                exibeLista(listaAuxiliar1);

                            }

                            if(verificaOcorrenciaNegativos(listaAuxiliar1)){
                                cout << "Listas com valores negativos não são permitidas\n";
                            }else{
                                cout << "Resultado da associação" << endl;
                                //cout << "Size lista durações " << listaAuxiliar1.size() << endl;
                                syncker.associeAlturasEduracoes(alturas, listaAuxiliar1, listaResultanteAlturasDuracoes);
                                //cout << "1\n";
                                for(auto elemento : listaResultanteAlturasDuracoes)
                                {
                                    notas.calculeEnarmonia(elemento, elemento.size());
                                }
                                listaDeNotas = notas.pegueNotas();
                                registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                                //cout << "2\n";
                                // exibeLista(listaResultanteAlturasDuracoes);
                                //registradorDeListas.imprimaListaNaTela(listaDeNotas);
                            }
                        }
                    }
                    resetLista(alturas);
                    resetLista(listaResultanteAlturasDuracoes);
                    resetLista(listaAuxiliar1);
                    resetLista(listaAuxiliar2);
                    listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                    notas.limpeListaDeNotas();
                }else{
                    cout << "Número da lista inválido.\n";
                }

            break;

            case '3':
                cout << "Derivar listas" << endl;
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostreListasNaMemoria();
                cin >> idLista;
                idLista = idLista-1;
                
                if( vericaSeIDDaListaEValido(idLista, registradorDeListas)){
                    
                    listaDeNotas = registradorDeListas.pegueListaDeNotasDaMemoria(idLista);

                    if( !listaDeNotas.empty() )
                    {
                        cout << "alturas" << endl;
                        // derivar apenas as alturas.
                        if( listaDeNotas.front().pegueAltura() != "")
                        {
                            for(auto elemento : listaDeNotas)
                            {
                                //cout << elemento.pegueAlturaNumerica() << endl;
                                listaAlturasInteirosSaida.push_back(elemento.pegueAlturaNumerica());
                            }

                            syncker.calculeDerivadaDiscreta(listaAlturasInteirosSaida, listaDerivadas);

                            for(auto elemento : listaDerivadas)
                            {
                                notas.calculeEnarmonia(to_string(elemento), 1);
                            }

                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        }

                        else if(listaDeNotas.front().pegueDuracao() != 0 && listaDeNotas.front().pegueAltura() == "")
                        {
                            /*
                            cout << "durações" << endl;
                            for(auto elemento : listaDeNotas)
                            {
                                cout << elemento.pegueDuracao() << endl;
                                duracoes.push_back(elemento.pegueDuracao());
                            }

                            syncker.calculeDerivadaDiscreta(duracoes, listaDerivadas);

                            for(auto elemento : listaDerivadas)
                            {
                                notas.calculeEnarmonia(to_string(elemento), 1);
                            }

                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                            */
                           cout << "Vetor intervalar apenas calculado para alturas!" << endl;
                        }

                        resetLista(listaDerivadas);
                        resetLista(duracoes);
                        resetLista(listaAlturasInteirosSaida);
                        listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                        notas.limpeListaDeNotas();

                    }
                    else
                    {
                        if(registradorDeListas.verifiqueSeListaExisteNaMemoria(idLista)){
                        listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(idLista);
                        syncker.calculeDerivadaDiscreta(listaAuxiliar1, listaDerivadas);
                        for(auto elemento : listaDerivadas)
                            {
                                notas.calculeEnarmonia( to_string(elemento), 1 );
                            }
                        listaDeNotas = notas.pegueNotas();
                        registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        // registradorDeListas.imprimaListaNaTela(listaDeNotas);
                        //registradorDeListas.adicioneListaNaMemoria(listaDerivadas);
                        }else{
                            alturas = registradorDeListas.pegueListaAlfanumericaDaMemoria(idLista);
                            processadorDeEntradas.convertaAlturasCifradasParaNumeroMIDI(alturas);
                            listaAuxiliar1 = processadorDeEntradas.pegueAlturasNumeroMIDI();
                            syncker.calculeDerivadaDiscreta(listaAuxiliar1, listaDerivadas);
                            
                            for(auto elemento : listaDerivadas)
                            {
                                notas.calculeEnarmonia( to_string(elemento), 1 );
                            }
                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                            // registradorDeListas.imprimaListaNaTela(listaDeNotas);
                            //registradorDeListas.adicioneListaNaMemoria(listaDerivadas);
                        }

                        exibeLista(listaDerivadas);

                        resetLista(listaDerivadas);
                        listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                        notas.limpeListaDeNotas();
                    }



                }else{
                    cout << "Número da lista inválido.\n";
                }
            break;

            case '4':
                cout << "Acumular listas numéricas" << endl;
                registradorDeListas.mostreListasNaMemoria();
                cout << "Escolha a lista informando o número ao lado dela" << endl;

                resetLista(listaSaidasAcumuladas);
                resetLista(duracoes);
                resetLista(listaAlturasInteirosSaida);
                listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                notas.limpeListaDeNotas();


                cin >> idLista;
                idLista = idLista-1;
                if( vericaSeIDDaListaEValido(idLista, registradorDeListas)){
                    listaDeNotas = registradorDeListas.pegueListaDeNotasDaMemoria(idLista);
                    
                    if( !listaDeNotas.empty() )
                    {

                        if( listaDeNotas.front().pegueDuracao() != 0 && listaDeNotas.front().pegueAltura() == "")
                        {
                            for(auto elemento : listaDeNotas )
                            {
                                duracoes.push_back(elemento.pegueDuracao());
                            }

                            syncker.acumuleValoresDaLista(duracoes, listaSaidasAcumuladas);

                            for(auto elemento : listaSaidasAcumuladas)
                            {
                                notas.calculeEnarmonia( to_string(elemento), 1 );
                            }

                            listaDeNotas = notas.pegueNotas();
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        }
                        else
                        {
                            if(listaDeNotas.front().pegueAltura() != "")
                            {   

                                for(auto elemento : listaDeNotas )
                                {
                                    listaAlturasInteirosSaida.push_back(elemento.pegueAlturaNumerica());
                                }

                                syncker.acumuleValoresDaLista(listaAlturasInteirosSaida, listaSaidasAcumuladas);

                                for(auto elemento : listaSaidasAcumuladas)
                                {
                                    notas.calculeEnarmonia( to_string(elemento), 1 );
                                }

                                listaDeNotas = notas.pegueNotas();
                                registradorDeListas.adicioneListaNaMemoria(listaDeNotas);

                            }
                        }   

                        resetLista(listaSaidasAcumuladas);
                        resetLista(duracoes);
                        resetLista(listaAlturasInteirosSaida);
                        listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                        notas.limpeListaDeNotas();


                    }
                    else{
                        listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(idLista);
                        syncker.acumuleValoresDaLista(listaAuxiliar1, listaSaidasAcumuladas);

                        for(auto elemento : listaSaidasAcumuladas)
                        {
                            notas.calculeEnarmonia( to_string(elemento), 1 );
                        }
                        listaDeNotas = notas.pegueNotas();
                        registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                        // registradorDeListas.imprimaListaNaTela(listaDeNotas);

                        // registradorDeListas.adicioneListaNaMemoria(listaSaidasAcumuladas);
                        //exibeLista(listaSaidasAcumuladas);

                        resetLista(listaSaidasAcumuladas);
                        listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                        notas.limpeListaDeNotas();
                    }

                }else{
                    cout << "Número da lista inválido.\n";
                }

                resetLista(listaSaidasAcumuladas);
                resetLista(duracoes);
                resetLista(listaAlturasInteirosSaida);
                listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                notas.limpeListaDeNotas();

            break;

            case '5':
                cout << "Reverter listas" << endl;
                registradorDeListas.mostreListasNaMemoria();
                cout << "Escolha a lista informando o número ao lado dela" << endl;
                cin >> idLista;
                idLista = idLista-1;

                // verificando se o valor digitado está dentro da faixa de valores
                // de ID disponíveis                
                 if( vericaSeIDDaListaEValido(idLista, registradorDeListas)){

                    // if(registradorDeListas.verifiqueSeListaExisteNaMemoria(idLista) == 1){
                    //     listaAuxiliar1 = registradorDeListas.pegueListaNumericaDaMemoria(idLista);
                    //     cout << "Lista de durações selecionada. Tamanho: "<< listaAuxiliar1.size() << endl;
                        
                    //     if(!listaAuxiliar1.empty())
                    //     {
                    //         syncker.revertaLista(listaAuxiliar1, listaAuxiliar2);

                    //         for(auto elemento : listaAuxiliar2)
                    //         {
                    //             cout << elemento << endl;
                    //             notas.calculeEnarmonia( to_string(elemento), 1 );
                    //         }
                    //         listaDeNotas = notas.pegueNotas();
                    //         registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                    //     }
                    //     else
                    //     {
                    //         cout << "Lista vazia" << endl;
                    //     }
                    //     // registradorDeListas.imprimaListaNaTela(listaDeNotas);

                    //     // registradorDeListas.adicioneListaNaMemoria(listaAuxiliar2);
                    //     // exibeLista(listaAuxiliar2);
                    //     listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());

                    // }
                    // else if( !registradorDeListas.pegueListaDeNotasDaMemoria(idLista).empty() )
                    // {   



                        // pegue da memória a lista de notas a ser invertida
                        listaDeNotas = registradorDeListas.pegueListaDeNotasDaMemoria(idLista);

                        // separe a lista de notas em suas componentes de alturas e durações
                        compositor.desassociar(listaDeNotas);

                        // atribua essas componentes à listas temporárias
                        listaAuxiliar1 = *compositor.pegueListaDuracoes();
                        alturas = *compositor.pegueListaAlturas();
                        auto listaDeIds = *compositor.pegueListaDeIDs();
                        
                        for(auto a : listaDeIds)
                        {
                            cout << "ID " << a << endl;
                        }

                        // aplique a operação de reversão de listas na listas temporárias
                        syncker.revertaLista(listaAuxiliar1, listaAuxiliar2);
                        syncker.revertaLista(alturas, alturasOrdemInversa);

                        // remonte a lista de notas a partir das novas componentes
                        compositor.associar(alturasOrdemInversa, listaAuxiliar2);

                        // guarde na memória a nova lista de notas 
                        listaDeNotas = *compositor.pegueListaDeNotas();
                        if(!listaDeNotas.empty())
                        {
                            registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                            registradorDeListas.imprimaListaDeNotasNaTela(listaDeNotas);
                        }
                        else
                        {
                            cout << "Lista vazia!" << endl;
                        }
                        


                        /*
                                REMOVENDO, MOMENTANEAMENTE, A PARTE DE SALVAR
                                NO FREEPLANE

                        */
                        
                        /*

                        // atribuindo as componentes de notas nas listas temporárias
                        compositor.desassociar(listaDeNotas);
                        listaAuxiliar1 = *compositor.pegueListaDuracoes();
                        alturas = *compositor.pegueListaAlturas();

                        // enviando para o mapa a lista de alturas modificadas e o nó pai
                        string id = listaDeIds.front();

                        synckerPlane.atribuaAlturasDoCSyncker(id, alturasOrdemInversa);

                        list<string> duracoesStringAux;
                        // convertendo lista de inteiros para string
                        for(auto elemento : listaAuxiliar1)
                        {
                            duracoesStringAux.push_back(to_string(elemento));
                        }

                        cout << "IDs das listas " << id << " " << listaDeNotas.front().pegueID() << endl;

                        // enviando para o mapa a lista de durações modificadas e o id
                        synckerPlane.atribuaDuracoesDoCSyncker(id, duracoesStringAux);

                        // invoca os métodos que alteram o mapa
                        synckerPlane.atualizeValoresDoMapa(caminho);
                        // synckerPlane.escrevaNoXMLdoMapa(caminho);

                        // limpando as listas envolvidas no processo
                        listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                        resetLista(listaAuxiliar2);
                        resetLista(alturasOrdemInversa);
                        compositor.limpeListaDeNotas();

                        */
                         /*
                                REMOVENDO, MOMENTANEAMENTE, A PARTE DE SALVAR
                                NO FREEPLANE

                        */

                    // }
                    // else
                    // {
                    //     alturas = registradorDeListas.pegueListaAlfanumericaDaMemoria(idLista);
                    //     cout << "Lista de alturas selecionada. Tamanho: "<< alturas.size() << endl;
                    //     //processadorDeEntradas.convertaAlturasCifradasParaNumeroMIDI(alturas);
                    //     //listaAuxiliar1 = processadorDeEntradas.pegueAlturasNumeroMIDI();
                    //     syncker.revertaLista(alturas, alturasOrdemInversa);
                    //     //processadorDeEntradas.convertaNumeroMIDIParaAlturasCifradas(listaAuxiliar2, alturas);
                    //     for(auto elemento : alturasOrdemInversa)
                    //     {
                    //         cout << elemento << endl;
                    //         notas.calculeEnarmonia( elemento , 1 );
                    //     }
                    //     listaDeNotas = notas.pegueNotas();
                    //     registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                    //     // registradorDeListas.imprimaListaNaTela(listaDeNotas);
                        
                    //     //registradorDeListas.adicioneListaNaMemoria(alturasOrdemInversa);
                    //     // exibeLista(alturasOrdemInversa);
                    //     resetLista(alturasOrdemInversa);
                    //     resetLista(alturas);
                    //     listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());

                    // }




                    resetLista(listaAuxiliar1);
                    resetLista(listaAuxiliar2);
                    resetLista(alturas);
                    listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
                    notas.limpeListaDeNotas();
                 }else{
                    cout << "Número da lista inválido.\n";
                 }

            break;

            case '6':

                resetLista(listaParaEscreverLilypond);
                resetLista(alturasExtraidasDaMelodia);
                resetLista(duracoesExtraidasDaMelodia);
                resetLista(alturas);

                cout << "Escolha a lista informando o número ao lado dela" << endl;
                registradorDeListas.mostreListasNaMemoria();

                resultanteNotasListaAlturas = "";

                int listaLida;
                cout << "Informe a lista\n";
                cin >> listaLida;
                
                lista1 = listaLida-1;

                if( !vericaSeIDDaListaEValido(lista1, registradorDeListas) ){
                    cout << "Número da lista inválido.\n";
                }else{
                    // if(registradorDeListas.verifiqueSeListaExisteNaMemoria(lista1)){
                    //    cout << "Informe uma lista válida.\n";
                    // }else{
                        cout << "Id da lista " << lista1 << endl;
                        listaDeNotas = registradorDeListas.pegueListaDeNotasDaMemoria(lista1);

                        resetLista(duracoes);

                        for(auto nota : listaDeNotas)
                        {
                            // não estou usando as oitavas aqui
                            resultanteNotasListaAlturas += nota.pegueAltura() + nota.pegueAcidente1() + nota.pegueAcidente2() + ",";
                            
                            duracoes.push_back(nota.pegueDuracao());
                        }
                        resultanteNotasListaAlturas.erase( resultanteNotasListaAlturas.size()-1 );
                        // cout << "Alturas> "<< resultanteNotasListaAlturas << endl;

                        
                        // duracoes = compositor.pegueListaDuracoes();

                        for(auto elemento : duracoes)
                        {
                            duracoesExtraidasDaMelodia.push_back( to_string(elemento) );
                            // cout << "durações: " << to_string(elemento) << endl;
                        }

                        compositor.limperListas();

                        compositor.desassociar(listaDeNotas);
                        alturas = *compositor.pegueListaDeAlturasSemOitavas();

                        cout << "Alturas" << endl;
                        for(auto a : alturas)
                        {
                            cout << a << endl;
                        }

                        // cout << "Lista de duracoes> " << duracoesExtraidasDaMelodia.size() << endl;

                        listaParaEscreverLilypond.push_back(R"(\include "lilypond-book-preamble.ly" \relative c'' {)");
                        
                        // resultanteNotasListaAlturas.erase(resultanteNotasListaAlturas.size()-1);
                        // cout << resultanteNotasListaAlturas << endl;

                        //processadorDeEntradas.verifiqueEntrada(resultanteNotasListaAlturas,1);
                        for(auto elemento : resultanteNotasListaAlturas)
                        {
                            if(elemento != ',')
                            {
                                entrada_string_usuario += elemento;
                            }
                            else
                            {   
                                // cout << "Altura adicionada na lista " << entrada_string_usuario << endl;
                                alturasExtraidasDaMelodia.push_back(entrada_string_usuario);
                                entrada_string_usuario = "";
                            }
                        }
                        //alturasExtraidasDaMelodia = processadorDeEntradas.pegueAlturasCifradas();
                        
                        entrada_string_usuario = "";

                        entrada_string_usuario = escritor.substituiAlturaCoringaDoDicionarioDeDuracoesString(alturas, duracoesExtraidasDaMelodia);
                        cout << "Entrada string " << entrada_string_usuario << endl;
                        listaParaEscreverLilypond.push_back(entrada_string_usuario);
                        
                        // listaParaEscreverLilypond.push_back("\n");
                        // listaParaEscreverLilypond.push_back(R"(\layout{})");
                        // listaParaEscreverLilypond.push_back("\n");
                        // listaParaEscreverLilypond.push_back(R"(\midi{})");
                        listaParaEscreverLilypond.push_back("}");
                        
                        escritor.gereArquivoLilypond(listaParaEscreverLilypond, "teste");
                        escritor.inicieLilypond("teste");
                    //}

                        
                }
                resetLista(listaParaEscreverLilypond);
                resetLista(alturasExtraidasDaMelodia);
                resetLista(duracoesExtraidasDaMelodia);
                resetLista(alturas);
                compositor.limperListas();
                

            break;
            case 'l':
                registradorDeListas.mostreListasNaMemoria();
                //registradorDeListas.imprimaListaNaTela();
            break;

            case '7':
                {
                    cout << "Informe o caminho do arquivo usando / como separador" << endl;
                    cin >> caminho;
                    synckerPlane.carregueXMLdoMapa(caminho);
                   
                    synckerPlane.carregaAlturasEduracoesNaMemoria();
                 
                    // synckerPlane.numereNosDoMapa();
                    synckerPlane.atualizeValoresDoMapa(caminho);
                    synckerPlane.escrevaNoXMLdoMapa(caminho);
                    synckerPlane.convertaEmNotas();
                    
                    // listaDeNotas = processadorDeEntradas.pegueNotas();
                    
                    // registradorDeListas.adicioneListaNaMemoria(listaDeNotas);
                    // registradorDeListas.imprimaListaNaTela(listaDeNotas);

                    // exibo os nós que existem no dicionário
                    // mmSyncker.busqueNomesDosNos(caminho);
                    // cout << "Deseja carregar algum um nó?\n1 - Sim\n2 - Não" << endl;
                    // string nomeDoNo;
                    // int op;
                    // cin >> op;
                    // string qualidadeAltura ;  
                    // string qualidadeDuracao;
                    // if(op == 1)
                    // {   
                    //     // caso o usuário queira carregar o conteúdo de algum dos nós
                    //     // ele informa o nome do nó desejado (pode ser usado um índice numérico para facilitar)
                    //     cout << "Informe o nome do nó" << endl;
                    //     cin >> nomeDoNo;

                    //     // carrego então as alturas e durações do nó que o usuário 
                    //     // informou
                    //     qualidadeAltura  = mmSyncker.pegueQualidadePorNo(nomeDoNo, "alturas");
                    //     qualidadeDuracao = mmSyncker.pegueQualidadePorNo(nomeDoNo, "duracoes");

                    //     // imprimindo as qualidades
                    //     cout << "[" << qualidadeAltura << "]"<< endl;
                    //     cout << "[" << qualidadeDuracao << "]"<< endl;

                    //     // convertendo as qualidades em listas de Notas
                        


                        // próximos passos:
                        /*
                            1º - converter as strings retornadas em listas de notas
                            2º - adicionar as novas listas na memória
                            3º - caso o usuário queria salvar as modificações em uma das listas, criar uma 
                                opção no menu em que ele passa qual lista deseja salvar no mapa.
                            4º - simplificar as operações que estão sendo realizadas nesse menu
                        */

                    //}   
                    

                    

                    
                }
            break;

            case '8':
                {
                    ofstream ofile("sample.bin", ios::binary);
                    if (ofile.is_open()){
                        registradorDeListas.escrevaParaArquivo(ofile);
                        ofile.close();
                    }
                }

            break;

            case '9':
                {
                    ifstream ifile("sample.bin", ios::binary);

                    if (ifile.is_open()){
                        while(true){
                            list<int> listaNumerica;
                            ifile.read(reinterpret_cast<char*>(&listaNumerica), sizeof(listaNumerica));
                            if (ifile.fail() || ifile.eof()) break;
                            registradorDeListas.adicioneListaNaMemoria(listaNumerica);
                        }
                        //registradorDeListas.leiaDoArquivo(ifile);
                        ifile.close();
                    }
                }

            break;

            case 'd':

                registradorDeListas.desfazer();

            break;

            case 'e':
                registradorDeListas.mostreListasNaMemoria();
                cout << "Informe o id da lista\n";
                cin >> idLista;
                idLista = idLista-1;


                if( vericaSeIDDaListaEValido(idLista, registradorDeListas) ){
                    registradorDeListas.deleteDaMemoria(idLista);
                }else{
                    cout << "Id invalido.\n";
                }

            break;

            case 27:
                //system("exit");
                signal(SIGINT, sig_handler);
            break;
            
            default:
                cout << "Opção inválida" << endl;
        }

        
    }


    return 0;
}
