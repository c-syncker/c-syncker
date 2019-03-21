#ifndef VisualizadorDeEventos_H
#define VisualizadorDeEventos_H

#include <iostream>
#include <vector>
#include <list>
#include "Nota.h"

using namespace std;

//!  Classe responsável por mostrar na tela as listas disponíveis
/*!
    Essa classe recebe uma lista de valores e realiza sua impressão formatada
    na tela. A impressão pode ser padrão, exibindo todos os elementos da lista
    informada apenas com vírgulas ou espaços, ou pode ter outras formas como 
    desenhar bordas, impressão em 'dropdown' (todas as informações) etc. 
*/

/*

    IMPRESSÃO SIMPLES:

    ************************************* 
    * Index:          2.1.1.2           * 
    * Alturas:        a#2,b1,c4,db2     *
    * Durações:       2,1,1,2           *
    * Intensidade:    null              *    
    * Combinação:     2a#2,1b1,1c4,2db2 *
    *************************************



*/


class VisualizadorDeEventos
{

    public:

        VisualizadorDeEventos();
        virtual ~VisualizadorDeEventos();
        
        void imprimaLista( list<Nota> listaParaExibir );
        void imprimaListaDropDown();


    private:


};


#endif // VisualizadorDeEventos_H