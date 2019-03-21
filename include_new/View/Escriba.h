#ifndef ESCRIBA_H
#define ESCRIBA_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;


//!  Classe responsável pelos arquivo de saída
/*!
  Essa classe faz a conversão das alturas e durações para um arquivo .ly,
  entendido pelo Lilypond.
  Também executa a separação em uma lista de alturas e outra de durações a partir
  de uma entrada no formato: a1, c1, d1, e1 (exemplo de entrada)

*/

class Escriba
{
    // *********************************************************//
    //                  DECLARAÇÃO DE ATRIBUTOS                 //
    // *********************************************************//

        // Dicionários
            unordered_map<int, string> dicionarioDeDuracoesFigLilypond; // Declaração do dicionário contendo as notas a serem passadas para o Lilypond

        // Listas
            list<string> listaNotasParaEscriba;
            list<string> alturasExtraidasDaMelodia;
            list<string> listaDeDuracoes;

        // Tipos primitivos
            string nomeDoArquivo;
    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE ATRIBUTOS            //
    // *********************************************************//

    public:
        //! Construtor da classe Escriba.
        /*!
            Construtor sem parâmetros de Escriba.
            Inicializa o dicionário com alturas coringa e atribui um nome padrão
            ao arquivo lilypond (notas.ly)
        */
        Escriba();

        //! Construtor sobrecarregado da classe Escriba.
        /*!
            Construtor que recebe como parâmetro o nome do arquivo ly.
            Inicializa o dicionário com alturas coringa e atribui o nome
            ao arquivo lilypond.
        */

        Escriba(string nomeDoArquivo);
        virtual ~Escriba();

        // Métodos sem retorno
        //! Separa alturas e durações.
        /*!
            Recebe uma entrada no formato altura+duracao (a2, c1, d1, e2),
            uma lista de alturas e uma lista de durações, ambas vazias. Devolve, após
            processamento, a entrada separada em alturas e durações, i.e., ((a, c, d, e), (2, 1, 1, 2));

            @param entrada: uma lista com as alturas e durações. Ex: (a2, c1, d1, e2)
            @param alturasExtraidasDaMelodia: saída contendo todas as alturas extraídas da entrada
            @param listaDeDuracoes: saída contendo todas as durações extraídas da entrada
        */
        void separeAlturasDeDuracoes(string entrada,list<string> &alturasExtraidasDaMelodia, list<string> &listaDeDuracoes);



        //! Gera o arquivo de saída do Lilypond.
        /*!
            Recebe como parâmetros uma lista com as alturas e durações
            e as escreve no arquivo passado como parâmetro com extensão
            .ly


            @param listaNotasParaEscriba: notas já substituídas no dicionario de durações para escrever no Lilypond
            @param nomeDoArquivo: nome do arquivo gerado na saída
        */
        void gereArquivoLilypond(list<string> listaDeNotasParaEscriba, string nomeDoArquivo);

        //! Executa o Lilypond
        /*!
            Realiza uma chamada de sistema que executa o lilypond para converter o arquivo
            gerado pela função geraArquivoLilypond em arquivo PDF

           @param nomeDoArquivo: nome do arquivo gerado na saída
        */
        void inicieLilypond(string nomeDoArquivo);

        // Métodos com retorno de tipos primitivos
        //! Substitui uma altura e duração no dicionário de durações.
        /*!
            Recebe como entrada uma lista com alturas e uma lista com durações.
            Usa cada elemento da lista de durações como chave do dicionário interno
            da classe para converter a altura entrada em um símbolo lido pelo Lilypond.
            Exemplo: dada a entrada c1, após a substituição no dicionário fica c16
            dicionárioDeNotas[1] = c16, onde 1 é a duração e c foi a altura passada.


            @param listaAlturas: alturas que irão ser escritas no arquivo Lilypond
            @param listaDuracoes: durações usadas como índices do dicionário para achar a altura correspondente
            @param saida: string contendo as notas que serão escritas no arquivo a ser compilado pelo Lilypond
        */
        string substituiAlturaCoringaDoDicionarioDeDuracoesString(list<string> &listaDeAlturas, list<string> &listaDeDuracoes);

        //! Semelhant a substituiAlturaCoringaDoDicionarioDeDuracoesString() usando uma lista de durações numéricas.
        /*!
            Faz a substituição de caracteres no dicionário interno da classe, usando
            uma lista de durações no formato de inteiros.

           @param nomeDoArquivo: nome do arquivo gerado na saída
        */
        string substituiAlturaCoringaDoDicionarioDeDuracoes(list<string> &listaDeAlturas, list<int> &listaDeDuracoes);

        //! Retorna o nome do arquivo .ly.
        string pegueONomeDoArquivo();


    protected:

    private:


};

#endif // ESCRIBA_H
