#include "GerenciadorDeMemorias.h"

GerenciadorDeMemorias::GerenciadorDeMemorias()
{
    id = 0;
}

GerenciadorDeMemorias::~GerenciadorDeMemorias()
{
    //dtor
}


void GerenciadorDeMemorias::adicioneListaNaMemoria(list<int> &listaParaAdicionarNaMemoria){
    listasNumericasNaMemoria[id] = listaParaAdicionarNaMemoria;
    idsListasNumericasNaMemoria.push_back(id);
    ultimoIdUsado.push(id);
    id++;
}

void GerenciadorDeMemorias::adicioneListaNaMemoria(list<string> &listaParaAdicionarNaMemoria){
    listasAlfanumericasNaMemoria[id] = listaParaAdicionarNaMemoria;
    idsListasAlfanumericasNaMemoria.push_back(id);
    ultimoIdUsado.push(id);
    id++;
}

void GerenciadorDeMemorias::adicioneListaNaMemoria(list<Nota> &listaParaAdicionarNaMemoria){
    listasDeNotasNaMemoria[id] = listaParaAdicionarNaMemoria;
    idsListasDeNotasNaMemoria.push_back(id);
    ultimoIdUsado.push(id);
    id++;
}

void GerenciadorDeMemorias::mostreListasNaMemoria(){

    for(int i = 0; i < id; i++){

        if(!listasNumericasNaMemoria[i].empty())
        {
            cout << i+1 << " => ";
            imprimaListaNaTela(listasNumericasNaMemoria[i]);
        }
        else if(!listasAlfanumericasNaMemoria[i].empty())
        {
            cout << i+1 << " => ";
            imprimaListaNaTela(listasAlfanumericasNaMemoria[i]);
        }
        else if(!listasDeNotasNaMemoria[i].empty())
        {
            // cout << "tamanho da lista de notas " << listasDeNotasNaMemoria.size() << endl;
            cout << i+1 << " => ";
            imprimaListaNaTela(listasDeNotasNaMemoria[i]);
            
        }
        else
        {
            cout << "Lista vazia " << i << endl;
            listasDeNotasNaMemoria.erase(i);
        }

        
        
        // if(listasNumericasNaMemoria.find(i) != listasNumericasNaMemoria.end()){
        //     cout << i+1 << " => ";
        //     imprimaListaNaTela(listasNumericasNaMemoria[i]);
        // }else if(listasAlfanumericasNaMemoria.find(i) != listasAlfanumericasNaMemoria.end()){
        //     cout << i+1 << " => ";
        //     imprimaListaNaTela(listasAlfanumericasNaMemoria[i]);
        // }else{
        //     // if(listasDeNotasNaMemoria[i].front().pegueIndice() != "")
        //     // {   
        //     //     cout << i+1 << " => ";   
        //     //     imprimaListaDeNotasNaTela(listasDeNotasNaMemoria[i]);
        //     // }
        //     // else
        //     // {   
        //         cout << "Tamanho da lista de notas " << listasDeNotasNaMemoria[i].size() << endl;
        //         cout << i+1 << " => ";
        //             imprimaListaNaTela(listasDeNotasNaMemoria[i]);
        //     // }
            
        // }

    }



}

// ESTOU TESTANDO APENAS OS ELEMENTOS QUE EXISTEM NA MEMORIA DE LISTAS NUMERICAS
// JA QUE O ID DAS LISTAS É ÚNICO NAS DUAS MEMORIAS E, POR EXCLUSAO, SE UM ID
// ESTA NUMA LISTA, NAO ESTARA NA OUTRA, O QUE IRA RETORNAR VAZIO
int GerenciadorDeMemorias::verifiqueSeListaExisteNaMemoria(int idDaLista){

    map<int, list<int> >::iterator verificaSeExiste;

    verificaSeExiste = listasNumericasNaMemoria.find(idDaLista);

    if(verificaSeExiste != listasNumericasNaMemoria.end()){
        return 1;
    }else{
        return 0;
    }

}

list<int> GerenciadorDeMemorias::pegueListaNumericaDaMemoria(int idDaLista){
    return listasNumericasNaMemoria[idDaLista];
}

list<string> GerenciadorDeMemorias::pegueListaAlfanumericaDaMemoria(int idDaLista){
    return listasAlfanumericasNaMemoria[idDaLista];
}

void GerenciadorDeMemorias::imprimaListaNaTela(list<int> listaParaExibir){

    int inicio_aux = listaParaExibir.front();
    int fim_aux = listaParaExibir.back();

    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front() << endl;
    }else{

        listaParaExibir.pop_front();
        listaParaExibir.pop_back();

        cout << inicio_aux << ",";
        for(auto elemento : listaParaExibir){
            cout << elemento<< ",";
        }

        cout << fim_aux << endl;
    }
}

void GerenciadorDeMemorias::imprimaListaNaTela(list<string> listaParaExibir){
    
    string inicio_aux = listaParaExibir.front();
    string fim_aux = listaParaExibir.back();

    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front() << endl;
    }else{
        listaParaExibir.pop_front();
        listaParaExibir.pop_back();

        cout << inicio_aux << ",";
        for(auto elemento : listaParaExibir){
            cout << elemento<< ",";
        }

        cout << fim_aux << endl;
    }
}

void GerenciadorDeMemorias::imprimaListaNaTela(list<Nota> listaParaExibir){
    
    auto inicio_aux = listaParaExibir.front();
    auto fim_aux = listaParaExibir.back();

    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front().toString() << endl;
    }else{
        listaParaExibir.pop_front();
        listaParaExibir.pop_back();

        cout << inicio_aux.toString() << ",";
        for(auto elemento : listaParaExibir){
            cout << elemento.toString()<< ",";
        }

        cout << fim_aux.toString() << endl;
    }
}

void GerenciadorDeMemorias::imprimaListaDeNotasNaTela(list<Nota> listaParaExibir){
   
    auto inicio_aux = listaParaExibir.front();
    auto fim_aux = listaParaExibir.back();
    cout << "*************************" << endl;
    cout << "*  Índice  => \t" << listaParaExibir.front().pegueIndice() << "\t*" << endl;
    if(listaParaExibir.size() <= 1){
       
        // cout << "*  Índice  => \t" << listaParaExibir.front().pegueIndice() << "\t*" << endl;
        cout << "*  Altura  => \t" << listaParaExibir.front().pegueAltura() << listaParaExibir.front().pegueAcidente1() << listaParaExibir.front().pegueAcidente2() << ( listaParaExibir.front().pegueAltura() != "" ? to_string(listaParaExibir.front().pegueOitava()) : "" )  << "\t*" << endl;
        cout << "*  Duração => \t" << listaParaExibir.front().pegueDuracao() << "\t*" << endl;
        cout << "*************************" << endl;
    }else{
        listaParaExibir.pop_front();
        listaParaExibir.pop_back();

        // cout << "*************************" << endl;
        //cout << "*  Índice  => \t" << inicio_aux.pegueIndice() << "\t*" << endl;
        cout << "*  Altura  => \t" << inicio_aux.pegueAltura() << inicio_aux.pegueAcidente1() << inicio_aux.pegueAcidente2() << ( inicio_aux.pegueAltura() != "" ? to_string(inicio_aux.pegueOitava()) : "" )<< "\t*" << endl;
        cout << "*  Duração => \t" << inicio_aux.pegueDuracao() << "\t*" << endl;
        // cout << "*************************" << endl;

        for(auto elemento : listaParaExibir){
            // cout << "*************************" << endl;
            //cout << "*  Índice  => \t" << elemento.pegueIndice() << "\t*" << endl;
            cout << "*  Altura  => \t" << elemento.pegueAltura() << elemento.pegueAcidente1() << elemento.pegueAcidente2() << ( elemento.pegueAltura() != "" ? to_string(elemento.pegueOitava()) : "" ) << "\t*" << endl;
            cout << "*  Duração => \t" << elemento.pegueDuracao() << "\t*" << endl;
            // cout << "*************************" << endl;
        }

        // cout << "*************************" << endl;
        //cout << "*  Índice  => \t" << fim_aux.pegueIndice() << "\t*" << endl;
        cout << "*  Altura  => \t" << fim_aux.pegueAltura() << fim_aux.pegueAcidente1() << fim_aux.pegueAcidente2() <<( fim_aux.pegueAltura() != "" ? to_string(fim_aux.pegueOitava()) : "" ) << "\t*" << endl;
        cout << "*  Duração => \t" << fim_aux.pegueDuracao() << "\t*" << endl;
        cout << "*************************" << endl;
    }
}


int GerenciadorDeMemorias::pegueUltimoIdValido(){
    return id;
}

bool GerenciadorDeMemorias::escrevaParaArquivo(ofstream& arquivoDeSaida) {

    // primeiro escreve as listas numéricas em arquivo

    for(map<int, list<int> >::iterator listaNumerica = listasNumericasNaMemoria.begin(); listaNumerica != listasNumericasNaMemoria.end(); ++listaNumerica){
        arquivoDeSaida.write(reinterpret_cast<const char*> (&listaNumerica->first), sizeof(listaNumerica->first));
        arquivoDeSaida.write(reinterpret_cast<const char*> (&listaNumerica->second), sizeof(listaNumerica->second));
    }

    // depois escreve as listas alfanumericas no arquivo

    for(map<int, list<string> >::iterator listaAlfanumerica = listasAlfanumericasNaMemoria.begin(); listaAlfanumerica != listasAlfanumericasNaMemoria.end(); ++listaAlfanumerica){
        arquivoDeSaida.write(reinterpret_cast<const char*> (&listaAlfanumerica->first), sizeof(listaAlfanumerica->first));
        auto tamanho = static_cast<int>(listaAlfanumerica->second.size());
        arquivoDeSaida.write(reinterpret_cast<const char*> (&tamanho), sizeof(tamanho));
        arquivoDeSaida.write(reinterpret_cast<const char*> (&listaAlfanumerica->second), sizeof(listaAlfanumerica->second));
        //arquivoDeSaida.write(listaAlfanumerica->second , listaAlfanumerica->second.size());
    }

    /*for(auto const & valores : listasNumericasNaMemoria, auto const idListasNumericas : idsListasNumericasNaMemoria){
        arquivoDeSaida.write(reinterpret_cast<const char*> (&idListasNumericas), sizeof(idListasNumericas));
        arquivoDeSaida.write(reinterpret_cast<const char*> (&valores), sizeof(valores));
    }*/

    return !arquivoDeSaida.fail();
}

bool GerenciadorDeMemorias::leiaDoArquivo(ifstream& arquivoDeEntrada) {
    // ler primeiro as listas numéricas e seus índices


    while (!listasNumericasNaMemoria.empty()){
        //cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        listasNumericasNaMemoria.erase(listasNumericasNaMemoria.begin());
    }

    //while(true){
        list<int> listaNumerica;
        arquivoDeEntrada.read(reinterpret_cast<char*> (&id), sizeof(id));
        arquivoDeEntrada.read(reinterpret_cast<char*> (&listaNumerica), sizeof(listaNumerica));
        imprimaListaNaTela(listaNumerica);

        //if(arquivoDeEntrada.fail() || arquivoDeEntrada.eof()) break;
        listasNumericasNaMemoria[id] = listaNumerica;
   // }


    // depois ler as listas alfanuméricas e seus índices

    return !arquivoDeEntrada.fail();
}

void GerenciadorDeMemorias::deleteDaMemoria(int idDaListaParaDeletar){

    if( verifiqueSeListaExisteNaMemoria(idDaListaParaDeletar) ){
        listasNumericasNaMemoria.erase(idDaListaParaDeletar);
        id--;
    }else{
        listasAlfanumericasNaMemoria.erase(idDaListaParaDeletar);
        id--;
    }

}

void GerenciadorDeMemorias::desfazer(){
    if(!ultimoIdUsado.empty()){
        int ultimoId = ultimoIdUsado.top();
        deleteDaMemoria(ultimoId);
        ultimoIdUsado.pop();
        id--;
    }

}

list<Nota> GerenciadorDeMemorias::pegueListaDeNotasDaMemoria(int idDaLista)
{
    return listasDeNotasNaMemoria[idDaLista];
}