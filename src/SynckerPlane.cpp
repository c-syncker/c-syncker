#include "SynckerPlane.h"

SynckerPlane::SynckerPlane(GerenciadorDeMemorias *memoria,  ProcessadorDeEntradas *processadorDeEntradas)
{
    gerenciadoDeMemorias = memoria;
    entrada = processadorDeEntradas;
}

SynckerPlane::~SynckerPlane()
{
    
}

void SynckerPlane::carregueXMLdoMapa(string caminho)
{
    /*
        Carrega o arquivo XML de dentro do arquivo mapa
        do freeplane
    */
    // ifstream stream(caminho);
    // resultado = doc.load(stream);

    resultado = doc.load_file(caminho.c_str(), parse_default | parse_declaration);

    if(!resultado)
    {
        cout << "Parse error " << resultado.description() << endl;
        return;
    }

    doc.traverse(buscadorDeNos);
    
    auto indicesTemp = buscadorDeNos.pegueIndices();
    auto nosTemp = buscadorDeNos.pegueDicionarioNos();

    atribuaDicionarioDeIndices( indicesTemp );
    atribuaDicionarioDeNos( nosTemp );

    // stream.close();
}


void SynckerPlane::convertaAlturasEmListas(string alturas, list<string> &listaDeAlturas)
{
    int i;
    string aux;
    if(alturas.find(",") == string::npos)
    {
        // cout << alturas << endl;
        listaDeAlturas.push_back(alturas);
    }else
    {    
        for(i =0; i < alturas.length(); i++)
        {
            if(alturas[i] != ',')
            {
                aux += alturas[i];
                // aux.erase(aux.length()-1);
            }
            else
            {
                listaDeAlturas.push_back(aux);
                aux = "";
            }
        }
        listaDeAlturas.push_back(aux);
        // cout << aux << " ";
        // cout << endl;
        // aux="";
    }
}

void SynckerPlane::convertaDuracoesEmListas(string duracoes, list<string> &listaDeDuracoes)
{
    int i;
    string aux;
    if(duracoes.find(",") == string::npos)
    {
        //cout << duracoes << endl;
        listaDeDuracoes.push_back(duracoes);
    }else
    {    
        for(i = 0; i < duracoes.length(); i++)
        {   
            if(duracoes[i] != ',')
            {
                aux += duracoes[i];
            }
            else
            {
                listaDeDuracoes.push_back(aux);
                aux = "";
            }
            
            
            // if(duracoes[i] == ',')
            // {
            //     aux.erase(aux.length()-1);
            //     cout << aux << " ";
            //     listaDeDuracoes.push_back(aux);
            //     aux = "";
            // }
        }
        listaDeDuracoes.push_back(aux);
        // cout << aux << " ";
        // cout << endl;
        // aux="";
    }
}

bool SynckerPlane::escrevaNoXMLdoMapa(string caminho)
{      
    // carregueXMLdoMapa(caminho);
    bool sucesso = doc.save_file(caminho.c_str(), PUGIXML_TEXT("  "));
    assert(sucesso);
    return sucesso;
}

void SynckerPlane::numereNosDoMapa()
{

    string valor;
    map< xml_node, vector<xml_node> >::iterator it = indices.begin();
    it->first.attribute("index").set_value("1");
    // ADICIONAR UM NOVO FILHO COM O ATRIBUTO INDEX E O VALOR DO ÍNDICE

    for(; it != indices.end(); it++)
    {          
        if(it == indices.begin())
        {
            continue;
            
        }
        for(int i = 0; i < it->second.size(); i++)
        {
            valor = it->first.attribute("index").value();
            if( strcmp (valor.c_str(), "") != 0 )
            {
                valor.append(".");
            }
            valor.append( to_string(i+1) );
            it->second[i].append_attribute("index").set_value( valor.c_str() );
            
            if(valor != "1" && valor != "2"){
                index[valor] = it->first;
                //cout << i+1 << " " << it->second[i].attribute("index").value() << endl;
            }
        
            //cout << it->second[i].attribute("index").value() << endl;
            //cout << "\tID filho: " << it->second[i].attribute("ID").value() << " Nome: " << \
                        it->second[i].attribute("TEXT").value() << endl;
            
        }
    }

}

void SynckerPlane::carregaAlturasEduracoesNaMemoria()
{

    list<int> duracoesAuxiliar;
    list<string> alturasAuxiliar;


    for(auto a : dicionarioDeNos)
    {

        if( strcmp(a.second.child("attribute").attribute("NAME").value(), "alturas") == 0 )
        {
            alturas = a.second.child("attribute").attribute("VALUE").value();
            cout << alturas << endl;
            
            if(!alturas.empty())
            {   
                convertaAlturasEmListas(alturas, alturasListadas);
                matrizDeListasDeAlturasDoMapa[a.first] = alturasListadas;
            }
            
            // matrizDeListasDeAlturasDoMapa[numeroDeListasDeAlturas++] = alturasListadas;
            
            // cout << a.first << endl;
            //entrada->verifiqueEntrada(alturas, 1);
            //alturasAuxiliar = entrada->pegueAlturasCifradas();
            //gerenciadoDeMemorias->adicioneListaNaMemoria(alturasAuxiliar);
            
            // salvando as alturas do nó
            //alturasNo[a.second] = alturas;
        }

        if( strcmp(a.second.child("attribute").next_sibling("attribute").attribute("NAME").value(), "duracoes") == 0 )
        {
            duracoes = a.second.child("attribute").next_sibling("attribute").attribute("VALUE").value();
            cout << duracoes << endl;
            if(!duracoes.empty())
            {
                convertaDuracoesEmListas(duracoes, duracoesListadas);
                matrizDeListasDeDuracoesDoMapa[a.first] = duracoesListadas;
            }
            // cout << duracoes << endl;
            //matrizDeListasDeDuracoesDoMapa[numeroDeListasDeDuracoes++] = duracoesListadas;
            
            //entrada->verifiqueEntrada(duracoes, 2);
            //duracoesAuxiliar = entrada->pegueDuracoes();
            //gerenciadoDeMemorias->adicioneListaNaMemoria(duracoesAuxiliar);
            
            // salvando as durações do nó
            //duracoesNo[a.second] = duracoes;
            
            // TESTE PARA MODIFICAÇÃO DE VALORES DOS NÓS
            //a.second.child("attribute").next_sibling("attribute").attribute("VALUE").set_value("");
        }
        
        if( (duracoes.size() != 0) || (alturas.size() != 0))
        {
            conjuntoDeNotas.convertaEmNotas(alturasListadas, duracoesListadas);
            auto listaNotas = conjuntoDeNotas.pegueNotas();
            // adicionando IDs para todas as notas
            string id = a.second.attribute("ID").value();
            
            associeIdENota(id, &listaNotas);

            // cout << listaNotas.front().pegueID() << " " << listaNotas.size() << endl;
            if( !listaNotas.empty() ) 
            {
                for(auto a : listaNotas)
                {   
                    cout << "Nota: " << a.toString() << endl;
                }       
                gerenciadoDeMemorias->adicioneListaNaMemoria(listaNotas);
            }

            cout << "ID: " << listaNotas.front().pegueID() << endl;
            cout << a.second.attribute("TEXT").value() << endl;
            cout << "Alturas: " << alturas << endl;
            cout << "Durações: " << duracoes << endl;
            cout << endl;

            duracoesListadas.erase(duracoesListadas.begin(), duracoesListadas.end());
            alturasListadas.erase(alturasListadas.begin(), alturasListadas.end());
            conjuntoDeNotas.limpeListaDeNotas();

        }
        else{
            cout << "lista vazia" << endl;
        }
    
        
    }

    // teste
    // as alturas do mapa são as mesmas que vão para o c-syncker
    // quando atualizar uma lista de alturas, procuro aquela altura pelo no_pai
    // e atualizo o valor
    matrizDeListasDeAlturasDoCSyncker = matrizDeListasDeAlturasDoMapa;

    // teste
    // as durações do mapa são as mesmas que vão para o c-syncker
    // quando atualizar uma lista de durações, procuro aquela duração pelo no_pai
    // e atualizo o valor
    matrizDeListasDeDuracoesDoCSyncker = matrizDeListasDeDuracoesDoMapa;

}

void SynckerPlane::atribuaDicionarioDeIndices( map < xml_node , vector<xml_node> > &indices ) 
{
    this->indices = indices;
}

void SynckerPlane::atribuaDicionarioDeNos(  map <string, xml_node> &dicionarioDeNos )
{
    this->dicionarioDeNos = dicionarioDeNos;
}


string SynckerPlane::convertaListaEmString(list<string> &entrada)
{   
    string resultado = "";

    for(auto valor : entrada){
        resultado += valor + ",";
    }
    size_t pos = resultado.length()-1;
    resultado[pos] = '\0';
    return resultado;

}

void SynckerPlane::atualizeValoresDoMapa(string caminho)
{
    
    // carregueXMLdoMapa(caminho);
    

    string valor;

    cout << dicionarioDeNos.size() << endl;

    for(auto a : dicionarioDeNos)
    {

        // cout << a.second.attribute("ID").value() << endl;
        
        // atualizar as alturas do nó
        if( strcmp(a.second.child("attribute").attribute("NAME").value(), "alturas") == 0 )
        {   
            
            valor = convertaListaEmString( matrizDeListasDeAlturasDoCSyncker[a.first] );
            // cout << a.second.attribute("TEXT").value() << endl;
            cout << "Valores das alturas vindas do c-syncker: " << valor << endl;
            // cout << "Freeplane: " << a.second.child("attribute").attribute("VALUE").value() << endl;
            a.second.child("attribute").attribute("VALUE").set_value( valor.c_str() );
        }
        
        // atualizar as durações do nó
        if( strcmp(a.second.child("attribute").next_sibling("attribute").attribute("NAME").value(), "duracoes") == 0 )
        {
            valor = convertaListaEmString( matrizDeListasDeDuracoesDoCSyncker[a.first] );
            // cout << a.second.attribute("TEXT").value() << endl;
            cout << "Valores das durações vindas do c-syncker: " << valor << endl;
            // cout << "Freeplane: " << a.second.child("attribute").next_sibling("attribute").attribute("VALUE").value() << endl;
            a.second.child("attribute").next_sibling("attribute").attribute("VALUE").set_value( valor.c_str() );
        }

    }

    for(auto a : indices)
    {
        for(auto val : a.second)
        {
            buscadorDeNos.modify_node(val); // essa chamada altera os valores nos nós
        }
    }

    escrevaNoXMLdoMapa(caminho);
}

map< string, list<string> > SynckerPlane::pegueDicionariosDeAlturasDoMapa()
{
    return matrizDeListasDeAlturasDoMapa;
}

map< string, list<string> > SynckerPlane::pegueDicionariosDeDuracoesDoMapa()
{
    return matrizDeListasDeDuracoesDoMapa;
}

// fazendo testes usando ID no lugar de nodePai

void SynckerPlane::atribuaAlturasDoCSyncker(string &nodePai, list<string> &listasDeAlturasDoCSyncker)
{   
    cout << "ID do C-Syncker " << nodePai << endl;

    for(auto elemento : matrizDeListasDeAlturasDoCSyncker[nodePai])
    {
        cout << elemento << ",";
    }
    cout << endl;
    
    matrizDeListasDeAlturasDoCSyncker[nodePai] = listasDeAlturasDoCSyncker;
    
    
}

void SynckerPlane::atribuaDuracoesDoCSyncker(string &nodePai, list<string> &listasDeDuracoesDoCSyncker)
{
    cout << nodePai << endl;
    matrizDeListasDeDuracoesDoCSyncker[nodePai] = listasDeDuracoesDoCSyncker;
}

map< string, xml_node > SynckerPlane::pegueListaDeIndices(){
    return index;
}

vector<Nota> SynckerPlane::pegueNotas()
{   
    return notas;
}

void SynckerPlane::convertaEmNotas()
{
  
    auto iterador_alt = matrizDeListasDeAlturasDoMapa.begin();
    auto iterador_dur = matrizDeListasDeDuracoesDoMapa.begin();
    auto iterador_ind = index.begin();

    vector<string> alturas  ; // convertendo list em vector
    vector<string> duracoes ;
    vector<string> indices  ;

    list<Nota> listaAux;

    size_t tam = matrizDeListasDeAlturasDoMapa.size(); 

    string alturasConvertidas, duracoesConvertidas, indicesConvertidos;

    list<string> alturasDoMapa, duracoesDoMapa;
    const string format="";

    for(int i=1; i < tam; i++)
    {
       
         // cada vector contém uma linha de alturas, durações ou índices
        alturasDoMapa = iterador_alt->second;
        duracoesDoMapa = iterador_dur->second;

        alturas  = { alturasDoMapa.begin(), alturasDoMapa.end() }; // convertendo list em vector
        // alturas.push_back(",");
        alturasDoMapa.pop_front();
        duracoes = { duracoesDoMapa.begin(), duracoesDoMapa.end() }; // convertendo list em vector
        // duracoes.push_back(",");
        duracoesDoMapa.pop_front();
        indices  = { iterador_ind->first };

        indicesConvertidos = iterador_ind->first;

        alturasConvertidas = unaListasDeAlturasDuracoes(alturas, duracoes);
        regex whitespace("[[:s:]]+"); 

        alturasConvertidas = regex_replace(alturasConvertidas, whitespace, format, regex_constants::format_default);
        

        cout << "Alturas convertidas " << alturasConvertidas << endl;

        // entrada->extraiNotas(alturasConvertidas);
        convertaAlturasEmListas(alturasConvertidas, alturasListadas);
        for(auto elemento : alturasListadas)
        {   
            conjuntoDeNotas.calculeEnarmonia(elemento, elemento.size());
        }
        
        
        // listaAux = entrada->pegueNotas();
        // cout << conjuntoDeNotas.pegueNotas().size() << endl;
        listaAux = conjuntoDeNotas.pegueNotas();
        auto noPai = iterador_alt->first;
        cout << noPai << endl;
        associeNoPaiEindice(indicesConvertidos, &listaAux, noPai);
        // cout << "Tamanho da lista de notas vindas do freeplane " << listaAux.size() << endl;
        gerenciadoDeMemorias->adicioneListaNaMemoria(listaAux);
        //gerenciadoDeMemorias->imprimaListaNaTela(listaAux);
        conjuntoDeNotas.limpeListaDeNotas();
        alturasListadas.erase(alturasListadas.begin(), alturasListadas.end());
        // incremento do iterador para andar por todos os elementos do dicionário
        iterador_ind++; 
        iterador_alt++; 
        iterador_dur++; 
        
    }
}

string SynckerPlane::unaListasDeAlturasDuracoes(vector<string> &alturas, vector<string> &duracoes)
{
    string uniaoDasListas, alturasUnidas, duracoesUnidas, aux0;
   
    vector<string> aux1, aux2;
    int cont1=0, cont2=0;

    for(int i=0; i<alturas.size(); i++)
    {   
        aux0 = alturas[i] + duracoes[i] + ",";
        uniaoDasListas += aux0;
        // uniaoDasListas = aux1[i] + aux2[i] + ",";
    }
    uniaoDasListas.erase(uniaoDasListas.length()-1);
    
    return uniaoDasListas;

}

void SynckerPlane::associeNoPaiEindice(string &indice, list<Nota> *notas, string &pai)
{
    auto tam = notas->size();
    auto inicio = notas->begin();
    cout << pai << endl;
    while( inicio != notas->end() )
    {
        inicio->atribuaIndice(indice);
        inicio->atribuaNoPai(pai);

        inicio++;
    }

}

void SynckerPlane::associeIdENota(string &id, list<Nota>*notas)
{

    auto inicio = notas->begin();
    while( inicio != notas->end() )
    {  
        inicio->atribuaID(id);
        inicio++;
    }
}
