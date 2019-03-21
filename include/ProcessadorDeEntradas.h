#ifndef PROCESSADORDEENTRADAS_H
#define PROCESSADORDEENTRADAS_H

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include "Compositor.h"
#include "Nota.h"
#include "Notas.h"


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
            vector<char> entradaSeparada; // contém todos os caracteres da entrada do usuario

        // Objetos
           Notas notas;
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

        //! Recebe uma entrada no formato string com valores de alturas ou durações e as separa em listas
        /*!
            Dada uma string contendo alturas, durações ou alturas e durações, faz a separação
            desses valores em listas distintas contendo só alturas e só durações. Essas listas
            podem ser recuperadas pelos métodos pegueDuracoes() e pegueAlturasCifradas().

            @param entrada: string contendo a entrada informada pelo usuário que será separada em listas.
            @param opcaoDeEntrada: Tipo de dado que será tratado. 1 para alturas e 2 para durações.
        */
        
        void verifiqueEntrada(string listaDeEntrada, int opcaoDeEntrada);
        
        //! Calcula o número MIDI de uma Nota.
        /*! 
            Dado uma nota de entrada, calcula, o número MIDI referente a ela. Usa como
            base o tamanho da string. Uma string completa terá tamanho cinco, pois contém 
            altura, dois acidentes, oitava e duração. Porém a quatidade de informação pode
            variar.
            @param entrada: string contendo a entrada informada pelo usuário que será separada em listas.
            @param tamanho: inteiro com o tamanho da entrada.
        */

        // transferir esse método para a classe Notas
        void calculeEnarmonia(string entrada, int tamanho); // separa a entrada do usuário (entradas numéricas ou alfanuméricas) em listas
        
        //! Atribui um objeto do tipo Notas.
        /*!
            @param notas: objeto da classe Notas que será passado por referência.
        */

        void atribuaNotas(Notas &notas);

        //! Recebe uma entrada e separa em Notas.
        /*!
            Dada uma string contendo as alturas e durações com oitavas e acidentes, separa cada
            elemento delimitado por ',' em uma nota contendo altura, duração, oitava e acidentes. 
            @param entrada: string contendo a entrada informada pelo usuário que será separada em notas.
        */

        void extraiNotas(string entrada);

        
        // Recebe uma string, contendo alturas cifradas e gera uma lista com cada uma das alturas
        void gereListaAlturas(string stringDeEntrada, list<string> &listaAlturas); 
        
        // Recebe uma string, contendo durações e gera uma lista com cada uma das durações
        void gereListaDuracoes(string stringDeEntrada, list<string> &listaDuracoes); 
        


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

        //! Retorna uma lista com as notas da composição
        /*!
            Retorna uma lista com a combinação de alturas e durações, que formam as notas.
        */

        list<Nota> pegueNotas();

        // Métodos com retorno de tipos primitivos

        //! Retorna um número MIDI correspondente a uma altura cifrada.
        /*!
            Ao informar uma altura cifrada de caractere único na entrada,
            retorna sua representação numérica MIDI.

            @param altura: altura cifrada cuja representação numérica MIDI deseja ser conhecida.
        */
        int mostreValorMIDIDasAlturas(string altura);

        string convertaListaEmString(list<string> &entrada);

        void limpeListaDeNotas();

    protected:

    private:
        void limpeLista(list<int> &entrada);
        void limpeLista(list<string> &entrada);
        void removaChars(string &entrada);
};

#endif // PROCESSADORDEENTRADAS_H
