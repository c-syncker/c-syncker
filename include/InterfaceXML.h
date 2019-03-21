#ifndef INTERFACEXML_H
#define INTERFACEXML_H

#include <iostream>
#include <string.h>
#include "pugiconfig.hpp"
#include "pugixml.hpp"
#include <map>
#include <vector>

using namespace std;
using namespace pugi;


/****************************************************************/
/*               Struct para buscador de nós                   */
/***************************************************************/


struct simple_walker: xml_tree_walker   
{   
    vector<string> nosDoMapa;
    map < xml_node , vector<xml_node> > indices;

    map < xml_node , vector<xml_node> > pegueIndices(){
        return indices;
    }

    vector<string> pegueNomesDosNos()
    {
        return nosDoMapa;
    }

    char name[5] = "node";
    virtual bool for_each(pugi::xml_node& node)
    {
            if( strcmp(node.name(), name) == 0){
                nosDoMapa.push_back(node.attribute("TEXT").value());
                
                if( indices.find(node.parent()) == indices.end() ){ // se o pai não existe ainda, então adiciono-o a lista
                    indices[node.parent()].push_back(node);
                }else{ // se o pai já existe na lista, apenas adiciono o nó naquele pai
                    indices[node.parent()].push_back(node);
                }
                
            }
        return true; // continue traversal
    }
};

/****************************************************************/
/*              Fim da Struct para buscador de nós             */
/***************************************************************/

class InterfaceXML
{

    /************************************************************/
    /*             Declaração de objetos e structs             */
    /**********************************************************/
        xml_document doc;
        xml_node root;
        xpath_node xpathNode;
        xml_node *noContendoQualidade;
        simple_walker buscadorDeNos;
        vector<string> nomesDosNos;

    /************************************************************/
    /*              Declaração de variáveis primitivas         */
    /**********************************************************/

        string qualidadeCopia, qualidade;
        string caminhoDoArquivo;

    public:

        InterfaceXML();
        ~InterfaceXML();

        // carrega os dados do XML desejado na memória
        void carregueXMLdoMapa(string caminho);

        // salva modificações no mapa
        void salveNoXMLdoMapa(string caminho); 

        // realiza buscas na árvore XML por um ID
        xpath_node busquePorID(xml_node root, string id);

        // realiza buscas na árvore XML por um nome
        xpath_node busquePorNome(xml_node root, string nome);

        // retorna uma qualidade desejada da árvore carregada 
        string pegueQualidadePorNo(string nomeDoNo, string qualidadeDesejada);

        // altera em um nó o valor da qualidade informada.
        void altereUmaQualidadeNoMapa(string nomeDoNo, string qualidadeDesejada, string novoValor, string caminho);

        
        void busqueNomesDosNos(string caminho);

};


#endif // INTERFACEXML