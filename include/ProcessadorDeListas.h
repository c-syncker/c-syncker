#ifndef PROCESSADORDELISTAS_H
#define PROCESSADORDELISTAS_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;


//!  Classe responsável pelas operações sobre listas
/*!
  Essa classe realiza diversas operações sobre listas numéricas
  e/ou alfanuméricas informadas pelo usuário. Essas operações
  são usadas no processo de composição.

*/

class ProcessadorDeListas
{
    // *********************************************************//
    //                  DECLARAÇÃO DE ATRIBUTOS                 //
    // *********************************************************//

        // Dicionários
            map <int, int> uniaoDeTabuadasOrdenadasSemRepeticoes; // Armazena a união ordenada das tabuadas de 2 int até o limite do MMC

        // Listas
            list<int> inteirosParaSincronizacao;// Lista contendo inteiros para sincronizar (sincronização com mais de 2 elementos)
            list<int> listaDeDuracoes; // Lista que armazena as duraçoes
            list<int> listaDerivadaDiscreta; // Armazena a derivada discreta, ou seja, a diferença entre os elementos adjancentes da lista de união
            list<int> listaDeAlturas;
            // list<int> alturasDesdobradas;
            list<int> lista1, lista2; // Duas listas genéricas usadas em operações diversas, como, por exemplo, swap

        // Tipos primitivos
            int resultadoMMC; // Armazena o resultado dos MMCs calculados

    // *********************************************************//
    //                FIM DA DECLARAÇÃO DE ATRIBUTOS            //
    // *********************************************************//

    public:
        ProcessadorDeListas();
        virtual ~ProcessadorDeListas();

        // Métodos sem retorno
            //! Une listas de durações através de um dicionário - DESCONTINUADO
            /*!
                inteirosParaSincronizacao contém os inteiros a serem sincronizados. Cada elemento é multiplicado
                por um contador de 0 ao MMC dos elementos da lista informada. Dessa forma, é feita uma tabuada (multiplicação)
                de 0 ao MMC, tendo como base o elemento da lista.
                Ex: elementos: 2 e 3 (listas unitárias). MMC (2,3) = 6.
                Multiplicação de 2 até o MMC: 0*2=0, 1*2=2, 2*2=4, 3*2=6, 4*2=8, 5*2=10, 6*2=12.
                Multiplicação de 3 até o MMC: 0*3=0, 1*3=3, 2*3=6, 3*3=9, 4*3=12.
                Esses elementos são adicionados no dicinonário (map). Cada valor da tabuada
                e usado como chave do dicinonário. Isso garante que os valores não se repetiro no dicionário.
                Para este exemplo o método retornará (0,2,3,4,6,8,9,10,12).

                @param inteirosParaSincronizacao: lista com durações que serão sincronizadas
                @param resultadoMMC: limite para sincronização das listas
                @param uniaoDeTabuadasOrdenadasSemRepeticoes: dicionário contendo as listas unidas, sem repetições e ordenadas
            */
            void unaDeTabuadasOrdenadasSemRepeticoes(list<int>&inteirosParaSincronizacao, int resultadoMMC, map <int,int> &dicionarioDeTabuadasOrdenadasSemRepeticoes);


           //! Faz associação um a um entre alturas e durações.
            /*!
                Dada uma lista com as alturas e outra com as durações,
                retorna um dicinonário com a combinação das alturas e durações (listas unitárias apenas)

                @param listaDeAlturas: alturas que serão associadas
                @param listaDeDuracoes: lista com as durações que serão associadas
                @param listaComAlturasEduracoesAssociadas: contém as repetições de alturas quando a listaDeAlturas é desdobrada

            */
            void associeAlturasEduracoes(list<string> &listaDeAlturas, list<int> &listaDeDuracoes, list<string> &listaComAlturasEduracoesAssociadas);

            //! Ordena listas.
            /*!
                Recebe uma lista desordenada como parâmetro e a ordena.
                Esse ordenação é somente de tipos que já possuam operadores definidos (tipos numéricos e alfanuméricos).

                @param listaNaoOrdenada: lista que será ordenada.
            */
            void ordeneLista(list<int> &listaNaoOrdenada);

            //! Acumula (soma) os valores de uma lista.
            /*!
                Recebe na entrada uma lista que terá seus elementos somados, iniciando em zero
                até o elemento final da lista.
                Os valores são colocados na listaAcumulada de forma crescente.

                @param listaParaAcumular: lista que será somada.
                @param listaAcumulada: lista contendo o resultado.

            */
            void acumuleValoresDaLista(list<int> &listaParaAcumular, list<int> &listaAcumulada);

            //! Desdobra/Repete uma lista.
            /*!
                Desdobra/repete o parâmetro listaParaDesdobrar n vezes e guarda o
                resultado em listaResultante.

                @param listaParaDesdobrar: lista que será desdobrada/repetida
                @param numeroDeRepeticoes: quantidade de vezes que a listaParaDesdobrar será repetida
                @param listaResultante: guarda as repetições. É a saída da função
            */
            void desdobreListas (list<int> &listaParaDesdobrar, int numeroDeRepeticoes, list<int> &listaResultante);
            void desdobreListas (list<string> &listaParaDesdobrar, int numeroDeRepeticoes, list<string> &listaResultante);

            //! Sincroniza o tamanho de duas listas numéricas.
            /*!
                Informadas duas listas numéricas, elas são desdobradas (repetidas)
                até possuírem o mesmo tamanho e tem seus elementos unidos, ordenados e
                com repetições removidas. Só funciona com números, já que a saída é o vetor
                intervalar (derivada discreta) das duas listas.


                @param lista1: primeira lista de entrada para ser sincronizada.
                @param lista2: segunda lista de entrada para ser sincronizada.

            */
            void sincronizeListasNumericas(list<int> &lista1, list<int> &lista2, list<int> &listaResultante);


            //! Dadas duas listas, realiza uma junção entre elas (semelhante ao append()).
            /*!
                Dadas duas listas na entrada, faz uma operação de junção
                entre elas, colocando o resultado dentro de listaJuntada.

                @param lista1: primeira lista de entrada para junção.
                @param lista2: segunda lista de entrada para junção.
                @param listaJuntada: resultado da junção das duas listas.

            */
            void junteListas(list<int> &lista1, list<int> &lista2, list<int> &listaJuntada);


            //! Dada uma lista contendo repetições de elementos, faz uma remoção desses valores.
            /*!

                @param listaComRepeticoes: lista para remover repetições.
                @param listaSemRepeticoes: lista sem repetições de elementos.


            */
            void removaRepeticoes(list<int> &listaComRepeticoes, list<int> &listaSemRepeticoes);


            //! Calcula a derivada discreta (vetor intervalar) de uma lista.
            /*!

                Dada uma lista numérica, retorna como resultado uma
                lista contendo a derivada discreta (elemento sucessor menos elemento antecessor)
                dessa lista. Apenas para listas numéricas.

                @param listaParaDerivar: entrada contendo os valores numéricos.
                @param listaDerivada: lista resultante.


            */
            void calculeDerivadaDiscreta (list<int> &listaParaDerivar, list<int> &listaDerivada);

            //! Calcula a derivada discreta (vetor intervalar) de uma lista.
            /*!

                Sobrecarga do método descrito acima. Usa um dicionário
                para calcular o vetor intervalar da lista informada na entrada.

                @param uniaoDeTabuadasOrdenadasSemRepeticoes: mapa contendo o vetor intervalar unido, sem repetições e ordenado.
                @param listaDerivada: lista resultante.


            */
            void calculeDerivadaDiscreta (map <int,int> &uniaoDeTabuadasOrdenadasSemRepeticoes, list<int> &listaDerivadaDiscreta);

            void revertaLista(list<int> &listaOrdemNormal, list<int> &listaOrdemInversa);
            void revertaLista(list<string> &listaOrdemNormal, list<string> &listaOrdemInversa);
            void exibaLista(list<string> listaParaExibir);
            void exibaLista(list<int> listaParaExibir);

        // Métodos com retorno de tipos primitivos
            int coeficienteDeRepeticoes(int MMClistasEnvolvidas, int somatorioElementosLista);

            //! Calcula o Mínimo Múltiplo Comum (MMC).
            /*!
                recebe dois valores numéricos inteiros e calcula o MMC.

                @param num1: primeiro valor para calcular MMC
                @param num2: segundo valor para calcular MMC
                @param return: retorna o mmc das entradas
            */
            int mmc(int num1, int num2);


            //! Calcula o Mínimo Múltiplo Comum (MMC) com mais de dois elementos.
            /*!
                Recebe uma lista de valores numéricos para calcular o MMC.

                @param listaDeValores: lista com todos os valores para serem calculados o MMC
                @param return: retorna o mmc das entradas
            */
            int calculeMMC(list<int> &listaDeValores);
            // , list<int> &inteirosParaSincronizacao
            //  @param inteirosParaSincronizacao: recebe os valores da lista de entrada (backup da lista)

    protected:

    private:
        int acumule (list<int> &listaElementosParaAcumular);

};

#endif // PROCESSADORDELISTAS_H
