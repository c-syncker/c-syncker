#include "InterfaceXML.h"

InterfaceXML::InterfaceXML()
{
}
InterfaceXML::~InterfaceXML(){}

void InterfaceXML::carregueXMLdoMapa(string caminho)
{
    doc.load_file(caminho.c_str());
    root = doc.document_element();
}

void InterfaceXML::salveNoXMLdoMapa(string caminho)
{
    bool saveSucceeded = doc.save_file(caminho.c_str(), PUGIXML_TEXT("  "));  
}

void InterfaceXML::busqueNomesDosNos(string caminho)
{
    caminhoDoArquivo = caminho;
    carregueXMLdoMapa(caminho);
    doc.traverse(buscadorDeNos);
    nomesDosNos = buscadorDeNos.pegueNomesDosNos();

    cout << endl;
    for(auto elemento : nomesDosNos)
    {
        cout << "[" << elemento << "]" << endl;
    }
    cout << endl;
}


xpath_node InterfaceXML::busquePorID(xml_node noRaiz, string id)
{
    string query = "//node[@ID='" + id + "']";
    xpath_node xpathNode = noRaiz.select_node(query.c_str());
    return xpathNode;
}

xpath_node InterfaceXML::busquePorNome(xml_node noRaiz, string nome)
{
    string query = "//node[@TEXT='" + nome + "']";
    xpath_node xpathNode = noRaiz.select_node(query.c_str());
    return xpathNode;
}

string InterfaceXML::pegueQualidadePorNo(string nomeDoNo, string qualidadeDesejada)
{
    // busca um nó pelo seu atributo TEXT
    xpathNode = busquePorNome(root, nomeDoNo);

    auto nosDoMapa = xpathNode.node().children();

    for(auto no : nosDoMapa)
    {   
        if( strcmp(no.attribute("NAME").value(), qualidadeDesejada.c_str()) == 0 )
        {   
            // guardo uma copia da lista original para
            // comparar tamanhos posteriormente
            qualidade = no.attribute("VALUE").value();
            qualidadeCopia = qualidade;
            // cout << qualidade << endl;
            break;
        }
    }

    return qualidade;
}

void InterfaceXML::altereUmaQualidadeNoMapa(string nomeDoNo, string qualidadeDesejada, string novoValor, string caminho)
{

    // busca um nó pelo seu atributo TEXT
    xpathNode = busquePorNome(root, nomeDoNo);

    auto nosDoMapa = xpathNode.node().children();

    for(auto no : nosDoMapa)
    {   
        if( strcmp(no.attribute("NAME").value(), qualidadeDesejada.c_str()) == 0 )
        {   
            // guardo uma copia da lista original para
            // comparar tamanhos posteriormente
            qualidade = no.attribute("VALUE").value();
            qualidadeCopia = qualidade;

            if(qualidadeCopia.size() == novoValor.size())
            {  
                no.attribute("VALUE").set_value(novoValor.c_str());
                salveNoXMLdoMapa(caminho);
            }
            else
            {
                int op;
                cout << "Os tamanhos são diferentes. Deseja alterar mesmo assim?\n1 - Sim\n2 - Não" << endl;
                cin >> op;
                if(op == 1)
                {
                    no.attribute("VALUE").set_value(novoValor.c_str());
                    salveNoXMLdoMapa(caminho);
                }
                else
                {
                    cout << "Não alterado." << endl;
                }
                
            }

        }
    }



}