#ifndef ProcessadorDeEntradas_H
#define ProcessadorDeEntradas_H

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include "Nota.h"

using namespace std;

//!  Classe responsável por tratar as entradas do usuário
/*!
  Essa classe recebe listas numéricas e/ou alfanuméricas do usuário.
  Faz o tratamento necessário sobre essa entrada extraindo listas de alturas e durações a partir dos valores
  informados. Essas listas podem ser passadas para outras classes que realizam operações
  sobre listas.
*/

class ProcessadorDeEntradas
{
    // *********************************************************//
    //                  DECLARAÇÃO DE ATRIBUTOS                 //
    // *********************************************************//

        // Dicionários
            unordered_map<string, int> dicionarioAlturasCifradasNumerosMIDI; // Dicionário que contem as alturas cifradas e seus correspondentes MIDI numericos
            unordered_map<int, string> dicionarioNumerosMIDIDAlturasCifradas; // Dicionário que contem os valores numéricos MIDI e as alturas cifradas relacionadas a eles
            map<string, list<int> > dicionarioDeQualidadesMusicais; // Todas as qualidades musicais ficam aqui

        // Listas
            list<string> alturasCifras; // Alturas informadas no formato de cifras
            list<string> duracoesString;
            // list<int> alturasNumerosMIDI; // Alturas informadas no formato de número MIDI
            list<int> alturasConvertidasCifrasNumerosMIDI; // Alturas convertidas de cifras para valores numéricos MIDI
            list<int> duracoes;
            list<Nota> listaDeNotas;
        
        // Vectors
            vector<char> entradaSeparada; // contém todos os caracteres da entrada do  usu

    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE ATRIBUTOS            //
    // *********************************************************//

    public:
        ProcessadorDeEntradas();
        virtual ~ProcessadorDeEntradas();

        // Métodos sem retorno

        //! Recebe uma lista de alturas em cifras e as converte em seus equivalentes numéricos
            /*!
                Dada uma lista de strings na entrada, a converte para uma lista de inteiros.
                Essa lista pode ser recuperada por pegueAlturasNumeroMIDI();

                @param entradas: lista com alturas no formato de cifras que serão convertidas em números
            */
        void convertaAlturasCifradasParaNumeroMIDI(list<string> &entradas); // cifras para números MIDI

        //! Recebe uma lista com valores inteiros e os converte em seus equivalentes alfanuméricos
            /*!
               Dada uma lista de inteiros no padrão MIDI, os converte para seus equivalentes
               em cifras para alturas.

                @param entradasInteiro: lista com alturas no formato numérico que serão convertidas em cifras
                @param saidaString: lista com alturas cifradas
            */
        void convertaNumeroMIDIParaAlturasCifradas(list<int> &entradasInteiro, list<string> &saidaString); // números MIDI para Cifras

        //! Não mais usado no código atual
        void verifiqueEntrada(string listaDeEntrada, int opcaoDeEntrada);

        //! Recebe uma entrada no formato string com valores de alturas ou durações e as separa em listas
        /*!
            Dada uma string contendo alturas, durações ou alturas e durações, faz a separação
            desses valores em listas distintas contendo só alturas e só durações. Essas listas
            podem ser recuperadas pelos métodos pegueDuracoes() e pegueAlturasCifradas().

            @param entrada: string contendo a entrada informada pelo usuário que será separada em listas.

        */
        void calculeEnarmonia(string entrada, int tamanho); // separa a entrada do usuário (entradas numéricas ou alfanuméricas) em listas


        void extraiNotas(string entrada);

        //void leiaXMLdoMapa(map< int, list<string> > &matrizDeListasDeAlturas, map< int, list<string> > &matrizDeListasDeDuracoes);

        // Métodos com retorno de listas

        //! Retorna uma lista com as alturas convertidas em números MIDI
        /*!
            Retorna uma lista de inteiros com os valores correspondentes em MIDI das alturas
            cifradas informadas pelo usuário.
        */
        list<int> pegueAlturasNumeroMIDI(); // retorna uma lista de inteiros provenientes da conversão para MIDI

        //! Retorna uma lista com as durações informadas pelo usuário
        /*!
            Retorna uma lista de inteiros com os valores das durações que foram passadas
            pelo usuário na entrada.
        */
        list<int> pegueDuracoes();

        //! Retorna uma lista com as alturas no formato de cifras
        /*!
            Retorna uma lista das alturas cifradas que foram passadas pelo usuário.
        */
        list<string> pegueAlturasCifradas(); // retorna também o formato cifra apresentado ao usuário

        list<Nota> pegueNotas();

        // Métodos com retorno de tipos primitivos
        int verifiqueTipoLista(list<int> listaDeEntrada);
        int verifiqueTipoLista(list<string> listaDeEntrada);

        //! Retorna um número MIDI correspondente a uma altura cifrada.
        /*!
            Ao informar uma altura cifrada de caractere único na entrada,
            retorna sua representação numérica MIDI.

            @param altura: altura cifrada cuja representação numérica MIDI deseja ser conhecida.
        */
        int mostreValorMIDIDasAlturas(string altura);

    protected:

    private:
        // Métodos sem retorno
        void gereListaAlturas(string stringDeEntrada, list<string> &listaAlturas); // Recebe uma string, contendo alturas cifradas e gera uma lista com cada uma das alturas
        void gereListaDuracoes(string stringDeEntrada, list<string> &listaDuracoes); // Recebe uma string, contendo durações e gera uma lista com cada uma das durações
        void limpeLista(list<int> &entrada);
        void limpeLista(list<string> &entrada);
        void removaChars(string &entrada);
};

#endif // ProcessadorDeEntradas_H
