#include "Escriba.h"


Escriba::Escriba(){
    this->nomeDoArquivo = "notas";
    dicionarioDeDuracoesFigLilypond[1] = "c16";
    dicionarioDeDuracoesFigLilypond[2] = "c8";
    dicionarioDeDuracoesFigLilypond[3] = "c8.";
    dicionarioDeDuracoesFigLilypond[4] = "c4";
    dicionarioDeDuracoesFigLilypond[5] = "c4~c16";
    dicionarioDeDuracoesFigLilypond[6] = "c4.";
    dicionarioDeDuracoesFigLilypond[7] = "c4.~c16";
    dicionarioDeDuracoesFigLilypond[8] = "c2";
    dicionarioDeDuracoesFigLilypond[9] = "c2~c16";
    dicionarioDeDuracoesFigLilypond[10] = "c2~c8";
    dicionarioDeDuracoesFigLilypond[11] = "c2~c8.";
    dicionarioDeDuracoesFigLilypond[12] = "c2.";
    dicionarioDeDuracoesFigLilypond[13] = "c2.~c16";
    dicionarioDeDuracoesFigLilypond[14] = "c2.~c8";
    dicionarioDeDuracoesFigLilypond[15] = "c2.~c8.";
    dicionarioDeDuracoesFigLilypond[16] = "c1";
    dicionarioDeDuracoesFigLilypond[17] = "c1~c16";
    dicionarioDeDuracoesFigLilypond[18] = "c1~c8";
    dicionarioDeDuracoesFigLilypond[19] = "c1~c8.";
    dicionarioDeDuracoesFigLilypond[20] = "c1~c4";
    dicionarioDeDuracoesFigLilypond[21] = "c1~c4~c16";
    dicionarioDeDuracoesFigLilypond[22] = "c1~c4.";
    dicionarioDeDuracoesFigLilypond[23] = "c1~c4~c8.";
    dicionarioDeDuracoesFigLilypond[24] = "c1.";
    dicionarioDeDuracoesFigLilypond[25] = "c1.~c16";
    dicionarioDeDuracoesFigLilypond[26] = "c1.~c8";
    dicionarioDeDuracoesFigLilypond[27] = "c1.~c8.";
    dicionarioDeDuracoesFigLilypond[28] = "c1.~c4";
    dicionarioDeDuracoesFigLilypond[29] = "c1.~c4~c16";
    dicionarioDeDuracoesFigLilypond[30] = "c1.~c4";
    dicionarioDeDuracoesFigLilypond[31] = "c1~c2.~c8.";
}

Escriba::Escriba(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
    dicionarioDeDuracoesFigLilypond[1] = "c16";
    dicionarioDeDuracoesFigLilypond[2] = "c8";
    dicionarioDeDuracoesFigLilypond[3] = "c8.";
    dicionarioDeDuracoesFigLilypond[4] = "c4";
    dicionarioDeDuracoesFigLilypond[5] = "c4~c16";
    dicionarioDeDuracoesFigLilypond[6] = "c4.";
    dicionarioDeDuracoesFigLilypond[7] = "c4.~c16";
    dicionarioDeDuracoesFigLilypond[8] = "c2";
    dicionarioDeDuracoesFigLilypond[9] = "c2~c16";
    dicionarioDeDuracoesFigLilypond[10] = "c2~c8";
    dicionarioDeDuracoesFigLilypond[11] = "c2~c8.";
    dicionarioDeDuracoesFigLilypond[12] = "c2.";
    dicionarioDeDuracoesFigLilypond[13] = "c2.~c16";
    dicionarioDeDuracoesFigLilypond[14] = "c2.~c8";
    dicionarioDeDuracoesFigLilypond[15] = "c2.~c8.";
    dicionarioDeDuracoesFigLilypond[16] = "c1";
    dicionarioDeDuracoesFigLilypond[17] = "c1~c16";
    dicionarioDeDuracoesFigLilypond[18] = "c1~c8";
    dicionarioDeDuracoesFigLilypond[19] = "c1~c8.";
    dicionarioDeDuracoesFigLilypond[20] = "c1~c4";
    dicionarioDeDuracoesFigLilypond[21] = "c1~c4~c16";
    dicionarioDeDuracoesFigLilypond[22] = "c1~c4.";
    dicionarioDeDuracoesFigLilypond[23] = "c1~c4~c8.";
    dicionarioDeDuracoesFigLilypond[24] = "c1.";
    dicionarioDeDuracoesFigLilypond[25] = "c1.~c16";
    dicionarioDeDuracoesFigLilypond[26] = "c1.~c8";
    dicionarioDeDuracoesFigLilypond[27] = "c1.~c8.";
    dicionarioDeDuracoesFigLilypond[28] = "c1.~c4";
    dicionarioDeDuracoesFigLilypond[29] = "c1.~c4~c16";
    dicionarioDeDuracoesFigLilypond[30] = "c1.~c4";
    dicionarioDeDuracoesFigLilypond[31] = "c1~c2.~c8.";
}

Escriba::~Escriba(){

}

void Escriba::gereArquivoLilypond(list<string> listaDeNotasParaEscriba, string nomeDoArquivo){

    /*
        recebe como parâmetros uma lista com as alturas e durações
        e as escreve no arquivo passado como parâmetro com extensão
        .ly

    */
    string arquivoLily = nomeDoArquivo+".ly";
    cout <<"Abrindo o arquivo " << arquivoLily << " ..." <<endl;

    ofstream wrt;
    wrt.open(arquivoLily);

    if(wrt.is_open()){
        for (std::list<string>::const_iterator listIterator = listaDeNotasParaEscriba.begin(); listIterator != listaDeNotasParaEscriba.end(); ++listIterator)
        {
            wrt << *listIterator;
        }
        wrt.close();
        cout << "Arquivo gravado com sucesso!" << endl;
    }else{
        cout << "Arquivo não encontrado!" << endl;
    }
}

void Escriba::inicieLilypond(string nomeDoArquivo){

    /*
        inicia o lilypond para converter o arquivo
        gerado pela função geraArquivoLilypond em arquivo PDF
    */

    string command, pdf_file, arquivoLily;
    arquivoLily = nomeDoArquivo+".ly";
    //inicializa o lilypond para a conversão
    cout << "Iniciando o Lilypond!" << endl;
    command = "lilypond " + arquivoLily;
    
    const char *iniciarLilypond = command.c_str();
    system(iniciarLilypond);

    string comandoConverterParaImg = "convert -density 400 "+ nomeDoArquivo+".pdf -quality 100 "+nomeDoArquivo+".png";
    const char *iniciarVisualizadorImg = comandoConverterParaImg.c_str();
    system(iniciarVisualizadorImg);
    // inicializa o evince para renderizar o pdf

    //string extensao = arquivoLily.substr(nomeDoArquivo.find_last_of('.'));
    //int posicao = arquivoLily.find(extensao);

    //arquivoLily.erase(posicao, arquivoLily.size());
    pdf_file = nomeDoArquivo + ".pdf";
    command = "evince " + pdf_file + "&";
    iniciarLilypond = command.c_str();
    system(iniciarLilypond);

    // 1 7 1 9 2 1 2 1 f,e,d 2 3 4 6 5
    // 1 3 1 2 2 1 2 1 f,e,d 2 3 4 6 5

}

void Escriba::separeAlturasDeDuracoes(string entrada,list<string> &listaDeAlturas, list<string> &listaDeDuracoes){


    /*
        recebe uma entrada no formato altura+duracao (a2, c1, d1, e2),
        uma lista de alturas e uma lista de durações vazias. Devolve, após
        processamento, a entrada separada em alturas e durações (a c d e | 2 1 1 2)
        dentro de suas respectivas listas;
    */


    string entradasDeAlturasEDuracoes, alturas, duracoes;
    entradasDeAlturasEDuracoes = entrada;
    // expressão regular para ler os valores numéricos de 0..9 da entrada
    regex altura("[[:digit:]]+");
     // expressão regular que trata todas as palavras na entrada
    regex duracao("[[:alpha:]]+");

    // formata a entrada com espaços vazios para separar altura e duração
    const string format="";

    // primeiro separa todas as listaAlturas da entrada
    alturas = regex_replace(entradasDeAlturasEDuracoes, altura, format, regex_constants::format_default);

    // separa as durações na entrada
    duracoes = regex_replace(entradasDeAlturasEDuracoes, duracao, format, regex_constants::format_default);


    // adiciono cada altura da string de listaAlturas (a) numa lista removendo os separadores
    for(auto it: alturas){
        if(it != ','){
            if(it != ' ')
                listaDeAlturas.push_back(string(1, it));
        }

    }

    // adiciono cada duração da string de durações (d) numa lista removendo os separadores
    string aux_string;
    for(auto it: duracoes){ // itera pela string para substituir as vírgulas
        if(it != ','){
            listaDeDuracoes.push_back(string(1, it)); // substitui a vírgula com um caractere de vazio
       // }else{
            //aux_string += it + " ";
        }
    }

   /* cout << "String sem virgulas " << aux_string << endl;

    istringstream iss(aux_string); // cria um stream sobre a string sem vírgulas
    string subs;
    do{
        iss >> subs; // a cada espaço, substitui o conteúdo em subs pelo valor antes do espaço
        listaDuracoes.push_back(subs); // adiciono na lista de durações
        cout << subs << endl;
    }while(getline(iss, subs, ' ')); // a string de durações é da forma [2 1 1 2]
                                    // remove os espaços colocando cada elemento na lista de durações
    */
}



string Escriba::substituiAlturaCoringaDoDicionarioDeDuracoesString(list<string> &listaDeAlturas,
                                list<string> &listaDeDuracoes){

    /*
        recebe como entrada um dicionario contedo as alturas e durações, uma lista
        com alturas e uma lista com durações.
        Usa cada elemento da lista de durações como índice do dicionário para
        buscar um shape (forma?) que processe a altura dada corretamente
        (dicionário = a16          entrada =>  altura = c duração  1)
        se transforma em:
        dicionario[1] = a16 -> a = c --> c16 essa é a string final enviada para o lilypond

    */

    string aux;
    int indice;

    while(listaDeDuracoes.size() != 0){
        string formataDuracoes = listaDeAlturas.front(); // substitui no dicionário de durações com a primeira
                                                     // ocorrência (topo) da lista de alturas
        listaDeAlturas.pop_front();   // apaga o topo para avançar na lista

        // essa regex vai substituir as alturas no dicionário pela altura desejada
        regex substituiAlturasDicionarioDuracoes("[[:alpha:]]+");

        indice = stoi( listaDeDuracoes.front() ); // converto para inteiro as durações para usar como
                                                // índices no dicionário

        // utiliza a regex_replace para pegar o valor do dicionário de durações
        // e substituir pela entrada do usuário
        aux += regex_replace(dicionarioDeDuracoesFigLilypond[indice], substituiAlturasDicionarioDuracoes,
                            formataDuracoes, regex_constants::format_default) + " ";
        listaDeDuracoes.pop_front();
    }
    // cout << aux << " "; // exibo os resultados que irão ser impressos no lilypond
    return aux;
}

string Escriba::substituiAlturaCoringaDoDicionarioDeDuracoes(list<string> &listaDeAlturas, list<int> &listaDeDuracoes){

    /*
        recebe como entrada um dicionario contedo as alturas e durações, uma lista
        com alturas e uma lista com durações.
        Usa cada elemento da lista de durações como índice do dicionário para
        buscar um shape (forma?) que processe a altura dada corretamente
        (dicionário = a16          entrada =>  altura = c duração  1)
        se transforma em:
        dicionario[1] = a16 -> a = c --> c16 essa é a string final enviada para o lilypond

    */

    string aux;
    int indice;

    while(listaDeDuracoes.size() != 0){
        string formataDuracoes = listaDeAlturas.front(); // substitui no dicionário de durações com a primeira
                                                     // ocorrência (topo) da lista de alturas
        listaDeAlturas.pop_front();   // apaga o topo para avançar na lista

        // essa regex vai substituir as alturas no dicionário pela altura desejada
        regex substituiAlturasDicionarioDuracoes("[[:alpha:]]+");


        indice = listaDeDuracoes.front();
        // utiliza a regex_replace para pegar o valor do dicionário de durações
        // e substituir pela entrada do usuário
        aux += regex_replace(dicionarioDeDuracoesFigLilypond[indice], substituiAlturasDicionarioDuracoes,
                            formataDuracoes, regex_constants::format_default) + " ";
        listaDeDuracoes.pop_front();
    }
    // cout << aux << " "; // exibo os resultados que irão ser impressos no lilypond
    return aux;
}

string Escriba::pegueONomeDoArquivo(){
    return nomeDoArquivo;
}

void Escriba::separeAlturas(list<Nota> notas)
{

    list<string> alturas;
    list<int> duracoes;

    compositor.desassociar(notas);

    alturas = *compositor.pegueListaAlturas();
    duracoes = *compositor.pegueListaDuracoes();

    cout << "[";
    for(auto a : alturas)
    {
        cout << a << ",";
    }
    cout << "]" << endl;

    cout << "[";
    for(auto d : duracoes)
    {
        cout << d << ",";
    }
    cout << "]" << endl;
    
}