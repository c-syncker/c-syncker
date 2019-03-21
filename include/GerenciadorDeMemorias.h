#ifndef GERENCIADORDEMEMORIAS_H
#define GERENCIADORDEMEMORIAS_H

#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <stack>
#include "Nota.h"

using namespace std;

//!  Classe responsável por criar e salvar listas informadas pelo usuário.
/*!
  Essa classe é usada para registrar as listas informadas pelo usuário
  e aquelas que são criadas durante operações que o usuário realiza. Essas
  listas podem ser recuperadas para serem novamente usadas em operações pelo usuário.
  Essa classe também realiza o salvamento em arquivo das listas que estão na memória.
*/

class GerenciadorDeMemorias
{
    // *********************************************************//
    //                  DECLARAÇÃO DE ATRIBUTOS                 //
    // *********************************************************//
        // Dicionários
            map<int, list<int> > listasNumericasNaMemoria; // Dicionário contendo listas numéricas
            map<int, list<string> > listasAlfanumericasNaMemoria; // Dicionário contendo listas alfanuméricas
            map<int, list<Nota> > listasDeNotasNaMemoria;
        // Listas
            list<int> idsListasNumericasNaMemoria;
            list<int> idsListasAlfanumericasNaMemoria;
            list<int> idsListasDeNotasNaMemoria;
            stack<int> ultimoIdUsado;

        // Tipos primitivos
            int id;

    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE ATRIBUTOS            //
    // *********************************************************//

    public:
        GerenciadorDeMemorias();
        virtual ~GerenciadorDeMemorias();

        // Métodos sem retorno

        //! Recebe uma lista de durações em inteiros e as adiciona na memória
            /*!
                Dada uma lista contendo as durações, adiciona na memória e atribui um
                índice para que o usuário possa recuperá-la.

                @param listaParaAdicionarNaMemoria: lista com durações que será colocada em uma memória
            */
        void adicioneListaNaMemoria(list<int> &listaParaAdicionarNaMemoria); // Adiciona lista numérica na memória

        //! Recebe uma lista de alturas alfanuméricas e as adiciona na memória
            /*!
                Dada uma lista contendo as alturas no formato de cifras, adiciona na memória e atribui um
                índice para que o usuário possa recuperá-la.

                @param listaParaAdicionarNaMemoria: lista com alturas que será colocada em uma memória
            */
        void adicioneListaNaMemoria(list<string> &listaParaAdicionarNaMemoria); // Adiciona lista alfanumérica na memório

        void adicioneListaNaMemoria(list<Nota> &listaParaAdicionarNaMemoria);

        //! Exibe as listas na memória
            /*!
                Exibe para o usuário todas as listas que foram salvas até aquele momento.
            */
        void mostreListasNaMemoria(); // Exibe todas as listas na memória (numéricas e alfanuméricas)

        //! Exibe as notas na lista
            /*!
                Exibe para o usuário todas as notas que estão na lista passada.
                @param listaParaExibir: lista de notas que será exibida.
            */

        void imprimaListaDeNotasNaTela(list<Nota> listaParaExibir); // esse método precisa ir para VisualizadorDeEventos

        //! Remove uma lista da memória
            /*!
                Exclui da memória a lista com o id informado.

                @param idDaListaParaDeletar: identificador da lista que será removida.
            */
        void deleteDaMemoria(int idDaListaParaDeletar);

        void desfazer();

        // Métodos com retorno de listas

        //! Retorna uma lista numérica armazenada na memória
            /*!
                Dado um id, retorna a lista numérica que está naquela
                posição de memória.

                @param idDaLista: posição da lista que se quer pegar.
            */
        list<int> pegueListaNumericaDaMemoria(int idDaLista); // Retorna uma lista numérica armazenada na memória dado um id

        //! Retorna uma lista alfanumérica armazenada na memória
            /*!
                Dado um id, retorna a lista alfanumérica que está naquela
                posição de memória.

                @param idDaLista: posição da lista que se quer pegar.
            */
        list<string> pegueListaAlfanumericaDaMemoria(int idDaLista); // Retorna uma lista alfanumérica armazenada na memória dado um id

        
        list<Nota> pegueListaDeNotasDaMemoria(int idDaLista);
        
        // Métodos com retorno de tipos primitivos

        //! Verifica se uma lista está na memória
            /*!
                Dado um id de uma lista, retorna 1 se ela está na memória
                ou 0 se ela não estiver. Usado para saber em qual memória
                (numérica ou alfanumérica) está a lista associada ao id passado.

                @param idDaLista: posição da lista que se quer verificar a existência.
            */
        int verifiqueSeListaExisteNaMemoria(int idDaLista); // No comments =)

        //! Retorna o último id válido da memória.
            /*!
                Retorna um valor que corresponde a última posição
                válida na memória. Usado para testar se o id informado pelo usuário
                é válido.
            */
        int pegueUltimoIdValido(); // Retorna qual o último id válido da memória

        // EM CONSTRUÇÃO
        bool escrevaParaArquivo(ofstream &arquivoDeSaida);
        bool leiaDoArquivo(ifstream &arquivoDeEntrada);

    protected:

    private:
       void imprimaListaNaTela(list<int> listaParaExibir); // Imprime na tela uma lista virgulada corretamente
       void imprimaListaNaTela(list<string> listaParaExibir); // Imprime na tela uma lista virgulada corretamente
       void imprimaListaNaTela(list<Nota> listaParaExibir);
};

#endif // GerenciadorDeMemorias_H
