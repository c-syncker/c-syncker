#include "ProcessadorDeListas.h"

ProcessadorDeListas::ProcessadorDeListas()
{
    //ctor
}

ProcessadorDeListas::~ProcessadorDeListas()
{
    //dtor
}


int ProcessadorDeListas::mmc(int num1, int num2) {
    int resto, a, b;
    a = num1;
    b = num2;

    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);

    return ( num1 * num2) / a;
}



int ProcessadorDeListas::coeficienteDeRepeticoes(int MMClistasEnvolvidas, int somatorioElementosLista){
    /*
        retorna a quantidade de vezes que uma lista vai
        ser repetida/desdobrada, baseado no mmc calculado para as listas envolvidas
        e o somatório de todos os elementos de uma lista por vez
    */
    return MMClistasEnvolvidas/somatorioElementosLista;
}


// MODIFICAR PARA TER UM ÚNICO PARÂMETRO (INTEIROS PARA SINCRONIZAR)
// , list<int> &inteirosParaSincronizacao
int ProcessadorDeListas::calculeMMC(list<int> &listaDeValores){
    /*
        calcula o mmc para mais de dois elementos

        listaDeDuracoes: lista com os elementos para calcular mmc
        inteirosParaSincronizacao: recebe os valores de listaDeDuracoes
    */

    int n1, n2, resultadoMMC;

    n1 = listaDeDuracoes.front();
    //inteirosParaSincronizacao.push_back(n1);
    listaDeDuracoes.pop_front();
    //cout << n1 << endl;
    n2 = listaDeDuracoes.front();
    listaDeDuracoes.pop_front();
    //inteirosParaSincronizacao.push_back(n2);
    //cout << n2 << endl;

    resultadoMMC = mmc(n1, n2);

    // REALIZA MMC COM MAIS DE 2 VALORES

    while(listaDeDuracoes.begin() != listaDeDuracoes.end()){
        resultadoMMC = mmc(resultadoMMC, listaDeDuracoes.front());
       // inteirosParaSincronizacao.push_back(listaDeDuracoes.front());
        //listaDeDuracoes.pop_front();
    }

    listaDeDuracoes.push_front(n2);
    listaDeDuracoes.push_front(n1);

    return resultadoMMC;

}


// FAZ A UNIÃO DAS LISTAS DE DURAÇÔES DENTRO DE UM DICIONÁRIO
void ProcessadorDeListas::unaDeTabuadasOrdenadasSemRepeticoes(list<int>&inteirosParaSincronizacao, int resultadoMMC, map <int,int> &dicionarioDeTabuadasOrdenadasSemRepeticoes){

    while(inteirosParaSincronizacao.begin() != inteirosParaSincronizacao.end()){

        // inteirosParaSincronizacao contém os inteiros a serem sincronizados. Cada elemento é multiplicado
        // por um contador de 0 a ao mmc informado. Dessa forma, é feita tabuada
        // de 0 ao MMC, tendo como base o elemento da lista.
        // Ex: mmc = 6, elementos: 2 e 3
        // 0*2=0, 1*2=2, 2*2=4, 3*2=6, 4*2=8, 5*2=10, 6*2=12
        // 0*3=0, 1*3=3, 2*3=6, 3*3=9, 4*3=12
        // Une esses elementos no dicinonário usando cada resultado da tabuada como
        // chave do dicinonário, garantindo que eles só ocorram uma vez
        // A união dos elementos da inteirosParaSincronizacao fica: 0,2,3,4,6,8,9,10,12

        for(int i=0; (i*inteirosParaSincronizacao.front()) <= resultadoMMC; i++){
            if (uniaoDeTabuadasOrdenadasSemRepeticoes.find(i*inteirosParaSincronizacao.front()) == uniaoDeTabuadasOrdenadasSemRepeticoes.end()){
                uniaoDeTabuadasOrdenadasSemRepeticoes[i*inteirosParaSincronizacao.front()] = 1;
            }
        }
        inteirosParaSincronizacao.pop_front();
    }

}


void ProcessadorDeListas::calculeDerivadaDiscreta (map <int,int> &uniaoDeTabuadasOrdenadasSemRepeticoes, list<int> &listaDerivada){

    // Usa o dicinonário uniaoDeTabuadasOrdenadasSemRepeticoes, que contém a sequência calculada
    // pela função acima.
    // Percorre esse dicionário realizando a subtração do sucessor - antecessor, devolvendo
    // uma lista de diferenças que é usada como lista de durações

    int aux;
    aux = uniaoDeTabuadasOrdenadasSemRepeticoes.begin()->first;

    // CALCULA A DIFERENÇA ENTRE OS ITENS DO DICIONÁRIO (sucessor - antecessor)
    for(map<int,int>::iterator it = uniaoDeTabuadasOrdenadasSemRepeticoes.begin(); it != uniaoDeTabuadasOrdenadasSemRepeticoes.end(); ++it){
        cout << it->first << " "<< it->second << endl;
        if( (it != uniaoDeTabuadasOrdenadasSemRepeticoes.begin()) &&  (it != uniaoDeTabuadasOrdenadasSemRepeticoes.end()) ){
            //cout <<"indice " <<it->first << endl;
            listaDerivada.push_back(it->first - aux);
            aux = it->first;
        }
    }

    // IMPRIMIR A LISTA DE VALORES
    cout << '\n';
    for(auto i : listaDerivada){
        cout << i << endl;
    }



}


// CONSIDERE ELIMINAR O PARÂMETRO listaDesdobramentoAlturas E FAZÊ-LO LOCAL
void ProcessadorDeListas::associeAlturasEduracoes(list<string> &listaDeAlturas, list<int> &listaDeduracoes, list<string> &listaComAlturasEduracoesAssociadas){

    /*
        Dadas uma lista com as alturas e outra com as durações,
        retorna um dicinonário com a combinação das alturas e durações (lista unitária)

    */

    list<string> listaDesdobramentoAlturas;
    list<int> duracoesDesdobradas;

    int MMCsizeListas, sizeAlturas;
    int sizeListaDuracao = listaDeduracoes.size();
    //cout << "Size durações " << sizeListaDuracao << endl;
    sizeAlturas = listaDeAlturas.size();
    //cout << "Size alturas " << sizeAlturas << endl;

    map<int, string> combinacaoAlturasDuracoes;

    /*
        listaAlturas: alturas informadas pelo usuário [a, e, d ...]
        listaDesdobramentoAlturas: lista com as repetições de alturas (lista sincronizada)
        duracoes: durações calculadas após a chamada de calculaDerivadaDiscreta [2 1 1 2]...
        duracoesDesdobradas: lista sincronizada de durações
        combinacaoAlturasDuracoes: dicionário com a combinação 1 a 1 das alturas e durações. Esse resultado é enviado ao Parser para lilypond
    */

    //cout << "Chamando mmc" << endl;

    MMCsizeListas = mmc(sizeAlturas, sizeListaDuracao);

   // cout << "Desdobrando" << endl;
    desdobreListas(listaDeAlturas, MMCsizeListas,listaDesdobramentoAlturas);
    desdobreListas(listaDeduracoes, MMCsizeListas,duracoesDesdobradas);

    //cout << "tamanho durações desdobradas " << duracoesDesdobradas.size() << endl;
    //cout << "tamanho alturas desdobradas " << listaDesdobramentoAlturas.size() << endl;

    for(int i=0; i<MMCsizeListas; i++){
        combinacaoAlturasDuracoes[i] = listaDesdobramentoAlturas.front() + to_string(duracoesDesdobradas.front());


        // lembrar que as lista de alturas e durações estão sendo apagadas...
        // toda a combinação está dentro combinacaoAlturasDuracoes
        listaDesdobramentoAlturas.pop_front();
        duracoesDesdobradas.pop_front();

    }

    for(int i=0; i<MMCsizeListas; i++){
        //cout << combinacaoAlturasDuracoes[i] << endl;
        listaComAlturasEduracoesAssociadas.push_back(combinacaoAlturasDuracoes[i]);
    }
}


void ProcessadorDeListas::desdobreListas (list<int> &listaParaDesdobrar, int numeroDeRepeticoes, list<int> &listaResultante){
    /*
        [out] essa função desdobra uma lista (repete a lista) n vezes;

        @params
        listaParaDesdobrar: lista que será repetida
        listaResultate: guarda as repetições da listaParaDesdobrar
        numeroDeRepeticoes: número de desdobramentos
    */
    int cont = 0;
    int sizeList = listaParaDesdobrar.size();

    int *vetorElementosLista = new int[sizeList];

    while(listaParaDesdobrar.begin() != listaParaDesdobrar.end()){
        vetorElementosLista[cont] = listaParaDesdobrar.front();
        listaParaDesdobrar.pop_front();
        cont+=1;

    }

    cont = 0;

    int i,j;
    for(i=0; i<numeroDeRepeticoes; i+=j){
        for(j=0; j<sizeList; j++){
            listaResultante.push_back(vetorElementosLista[j]);
        }
    }
    
    delete[] vetorElementosLista;
}

void ProcessadorDeListas::desdobreListas (list<string> &listaParaDesdobrar, int numeroDeRepeticoes, list<string> &listaResultante){
    /*
        [out] essa função desdobra uma lista (repete a lista) n vezes;

        @params
        listaParaDesdobrar: lista que será repetida
        listaResultate: guarda as repetições da listaParaDesdobrar
        numeroDeRepeticoes: número de desdobramentos
    */
    int cont = 0;
    int sizeList = listaParaDesdobrar.size();

    string *vetorElementosLista = new string[sizeList];

    while(listaParaDesdobrar.begin() != listaParaDesdobrar.end()){
        vetorElementosLista[cont] = listaParaDesdobrar.front();
        listaParaDesdobrar.pop_front();
        cont+=1;

    }

    cont = 0;

    int i,j;
    for(i=0; i<numeroDeRepeticoes; i+=j){
        for(j=0; j<sizeList; j++){
            listaResultante.push_back(vetorElementosLista[j]);
        }
    }
    
    delete[] vetorElementosLista;
}


int ProcessadorDeListas::acumule (list<int> &listaElementosParaAcumular){

    // realiza o somatório de todos elementos entre o first e o last
    // essa função é genérica para somar qualquer coisa
    int valorAcumulado = 0;

    for(auto elemento : listaElementosParaAcumular){
        valorAcumulado += elemento;
    }


    return valorAcumulado;
}


void ProcessadorDeListas::sincronizeListasNumericas(list<int> &lista1, list<int> &lista2, list<int> &listaResultante){
    //int init = 0;
    //T init2 = 0;
    int somatorioElementosLista1, somatorioElementosLista2;

    somatorioElementosLista1 = acumule(lista1);
    //cout << "acumule funciona" << somatorioElementosLista1 <<endl;
//    init = 0;
    somatorioElementosLista2 = acumule(lista2);

    int rep1, rep2, mmc_res;

    mmc_res = mmc((int)somatorioElementosLista1, (int)somatorioElementosLista2);
    rep1 = coeficienteDeRepeticoes(mmc_res, (int)somatorioElementosLista1);
    rep2 = coeficienteDeRepeticoes(mmc_res, (int)somatorioElementosLista2);
    //cout << "mmc funciona" << mmc_res <<endl;
    //cout << "rep1 " << rep1 << endl;
    //cout << "rep2 " << rep2 << endl;

    list<int> listaDesdobrada1, listaDesdobrada2;

    desdobreListas(lista1, lista1.size()*rep1, listaDesdobrada1);
    desdobreListas(lista2, lista2.size()*rep2, listaDesdobrada2);

    //cout << "tamanho da lista resultante 1 " << listaDesdobrada1.size() << endl;
    //cout << "tamanho da lista resultante 2 " << listaDesdobrada2.size() << endl;

    // imprimindo lista1 de resultados
    //for(auto a: listaDesdobrada1){
    //    cout << a << endl;
   //}

    list<int> listaAcumulada1,listaAcumulada2;

    acumuleValoresDaLista(listaDesdobrada1, listaAcumulada1);
    acumuleValoresDaLista(listaDesdobrada2, listaAcumulada2);
    list<int> listaUniao;
    //cout << "União das listas" << endl;
    junteListas(listaAcumulada1, listaAcumulada2, listaUniao);

    //cout << "removendo repetições" << endl;
    list<int> listaSemRepeticoes;

    removaRepeticoes(listaUniao, listaSemRepeticoes);


    //cout << "Lista sem repetições" << endl;
   // for(auto a : listaSemRepeticoes){
   //     cout << a << endl;
   // }


    //cout << "Lista ordenada" << endl;
    ordeneLista(listaSemRepeticoes);


    //for(auto a : listaSemRepeticoes){
    //    cout << a << endl;
    //}


    list<int> listaDerivada;
    calculeDerivadaDiscreta(listaSemRepeticoes, listaDerivada);

    /*
    for(auto a : listaDerivada){

        if (a != listaDerivada.back()){
            cout << a << ",";
        }else{
            cout << a;
        }
        listaResultante.push_back(a);
    }
    cout << "\n" ;
    */
    listaResultante = listaDerivada;

}

void ProcessadorDeListas::ordeneLista(list<int> &listaParaOrdenar){
    listaParaOrdenar.sort();
}


void ProcessadorDeListas::removaRepeticoes(list<int> &listaComRepeticoes, list<int> &listaSemRepeticao){
    unordered_set<int> set_auxiliar;

    for(list<int>::iterator it = listaComRepeticoes.begin(); it!= listaComRepeticoes.end(); it++){
        if(set_auxiliar.find(*it) == set_auxiliar.end()){
            set_auxiliar.insert(*it);
            listaSemRepeticao.push_back(*it);
        }
    }
}


void ProcessadorDeListas::calculeDerivadaDiscreta (list<int> &listaParaDerivar, list<int> &listaDerivada){

    int aux;
    aux = listaParaDerivar.front();

    for(typename std::list<int>::iterator it = listaParaDerivar.begin(); it != listaParaDerivar.end(); ++it){

        if( (it != listaParaDerivar.begin()) &&  (it != listaParaDerivar.end()) ){
            listaDerivada.push_back(*it - aux);
            aux = *it;
        }
    }

}


// dadas duas listas, realiza a união delas dentro de listaUnida;
// essa união é não ordenada e com repetição

void ProcessadorDeListas::junteListas(list<int> &lista1, list<int> &lista2, list<int> &listaJuntada){
    for (auto elemento : lista1){
        listaJuntada.push_back(elemento);
    }
    for (auto elemento : lista2){
        listaJuntada.push_back(elemento);
    }
}


void ProcessadorDeListas::acumuleValoresDaLista(list<int> &listaParaAcumular, list<int> &listaAcumulada){
    //acumuladorDeListas[0] = 0;

    listaAcumulada.push_back(0);

    int aux;
    aux = 0;

    for(auto iteradorLista : listaParaAcumular){
        aux += iteradorLista;
        listaAcumulada.push_back(aux);
        //cont+=1;
    }

    //for(auto iteradorLista : listaAcumulada){
    //    cout << iteradorLista << endl;
    //}

}

void ProcessadorDeListas::revertaLista(list<int> &listaOrdemNormal, list<int> &listaOrdemInversa){

    for(list<int>::reverse_iterator ordemInversa = listaOrdemNormal.rbegin(); ordemInversa != listaOrdemNormal.rend(); ++ordemInversa){
        listaOrdemInversa.push_back(*ordemInversa);
        //cout << *ordemInversa << ", ";
    }
    //cout << endl;

}

void ProcessadorDeListas::revertaLista(list<string> &listaOrdemNormal, list<string> &listaOrdemInversa){

    for(list<string>::reverse_iterator ordemInversa = listaOrdemNormal.rbegin(); ordemInversa != listaOrdemNormal.rend(); ++ordemInversa){
        listaOrdemInversa.push_back(*ordemInversa);
        //cout << *ordemInversa << ", ";
    }
    //cout << endl;

}



void ProcessadorDeListas::exibaLista(list<int> listaParaExibir){
    int aux;
    aux = *listaParaExibir.rbegin();

    cout << endl;

    for(list<int>::iterator elemento=listaParaExibir.begin(); elemento!=listaParaExibir.end(); ++elemento){
        if(*elemento != aux){
            cout << *elemento << ", ";
        }else{
            cout << *elemento;
        }
    }
    cout << endl;
}

void ProcessadorDeListas::exibaLista(list<string> listaParaExibir){
    string aux;
    aux = *listaParaExibir.rbegin();

    cout << endl;

    for(list<string>::iterator elemento=listaParaExibir.begin(); elemento!=listaParaExibir.end(); ++elemento){
        if(*elemento != aux){
            cout << *elemento << ", ";
        }else{
            cout << *elemento;
        }
    }
    cout << endl;
}
