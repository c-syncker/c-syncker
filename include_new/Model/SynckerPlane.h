#ifndef SYNCKERPLANE_H
#define SYNCKERPLANE_H

#include <iostream>
#include <string.h>
#include "pugiconfig.hpp"
#include "pugixml.hpp"
#include <vector>
#include <map>
#include <string>
#include <list>
#include <unordered_map>
#include "Nota.h"
#include "GerenciadorDeMemorias.h"
#include "ProcessadorDeEntradas.h"
#include <regex>

using namespace std;
using namespace pugi;

struct simple_walker: xml_tree_walker   
{   
    map <string, xml_node> dicionarioNos;
    map < xml_node , vector<xml_node> > indices;

    map <string, xml_node> pegueDicionarioNos(){
        return dicionarioNos;
    }

    map < xml_node , vector<xml_node> > pegueIndices(){
        return indices;
    }

    char name[5] = "node";
    virtual bool for_each(pugi::xml_node& node)
    {
            if( strcmp(node.name(), name) == 0){
                dicionarioNos[node.attribute("ID").value()] = node;
                if( indices.find(node.parent()) == indices.end() ){ // se o pai não existe ainda, então adiciono-o a lista
                    indices[node.parent()].push_back(node);
                }else{ // se o pai já existe na lista, apenas adiciono o nó naquele pai
                    indices[node.parent()].push_back(node);
                }
            }
        return true; // continue traversal
    }

    void modify_node(pugi::xml_node &node)
    {
        
        if( strcmp(node.name(), name) == 0){
            //node = node.attribute("ID").value()
            node = dicionarioNos[node.attribute("ID").value()];
        }
        //return true; // continue traversal
    }

};

class SynckerPlane
{

    /************************************************************/
    /*              Declaração de Dicionários                  */
    /**********************************************************/
    
    // nós do mapa  
    map <string, xml_node> dicionarioDeNos;
    
    // nós pais e seus filhos  
    map < xml_node , vector<xml_node> > indices;

    // listas de alturas e durações que foram tiradas do mapa
    map< xml_node, list<string> > matrizDeListasDeAlturasDoMapa;
    map< xml_node, list<string> > matrizDeListasDeDuracoesDoMapa;

    // listas de alturas e durações vindas do c-syncker
    map< xml_node , list<string> > matrizDeListasDeAlturasDoCSyncker;
    map< xml_node , list<string> > matrizDeListasDeDuracoesDoCSyncker;

    // nós com suas alturas e durações
    //map< xml_node, string > alturasNo;
    //map< xml_node, string > duracoesNo;
    map< string, xml_node > index;

    /************************************************************/
    /*              Declaração de Listas                       */
    /**********************************************************/
    list<string> alturasListadas, duracoesListadas;
    vector<Nota> notas;
    /************************************************************/
    /*             Declaração de objetos e structs             */
    /**********************************************************/
    xml_document doc;
    simple_walker buscadorDeNos;
    ProcessadorDeEntradas *entrada;
    xml_parse_result resultado;
    GerenciadorDeMemorias *gerenciadoDeMemorias;

    /************************************************************/
    /*              Declaração de variáveis primitivas         */
    /**********************************************************/
    string alturas, duracoes;
    char alt[8] = "alturas";
    char dur[9] = "duracoes";
    int numeroDeListasDeAlturas = 1, numeroDeListasDeDuracoes = 1;

    public:
        
        SynckerPlane(GerenciadorDeMemorias *memoria, ProcessadorDeEntradas *processadorDeEntradas);//GerenciadorDeMemorias &memoria, ProcessadorDeEntradas &processadorDeEntradas);
        virtual ~SynckerPlane();
        // CRIAR UM OBJETO DE GERENCIADOR DE LISTAS E GRAVAR NELE
        // AS LISTAS DE ALTURAS E DURAÇÕES
        
        void carregueXMLdoMapa(string caminho);
        void carregaAlturasEduracoesNaMemoria();
        void numereNosDoMapa();
        bool escrevaNoXMLdoMapa(string caminho);
        void atualizeValoresDoMapa();
        void leiaXMLdoMapa();
        void imprimaListas();
        void convertaListas();
        void atribuaAlturasDoCSyncker(map< xml_node, list<string> > &matrizDeListasDeAlturasDoCSyncker);
        void atribuaDuracoesDoCSyncker(map< xml_node, list<string> > &matrizDeListasDeDuracoesDoCSyncker);
        void convertaEmNotas();

        string convertaListaEmString( list<string> &entrada);
        string unaListasDeAlturasDuracoes(vector<char> alturas, vector<char> duracoes);

        map< xml_node, list<string> > pegueDicionariosDeAlturasDoMapa();
        map< xml_node, list<string> > pegueDicionariosDeDuracoesDoMapa();
        map< string, xml_node > pegueListaDeIndices();

        vector<Nota> pegueNotas();

    protected:

    private:

        void convertaAlturasEmListas(string alturas, list<string> &listaDeAlturas);
        void convertaDuracoesEmListas(string duracoes, list<string> &listaDeDuracoes);
        void atribuaDicionarioDeIndices( map < xml_node , vector<xml_node> > &indices );
        void atribuaDicionarioDeNos(  map <string, xml_node> &dicionarioDeNos );
};

#endif // !SYNCKERPLANE_H