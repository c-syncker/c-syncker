#include "ProcessaEntrada.h"



ProcessaEntrada::ProcessaEntrada()
{

    // essa passagem vai servir como um parser para converter as alturas em listas de inteiros

    alturasCifrasEntrada["c"]   = 60;
    alturasCifrasEntrada["c#"]  = 61; // dúvida sobre essa representação de sustenido
    alturasCifrasEntrada["d"]   = 62;
    alturasCifrasEntrada["d#"]  = 63;
    alturasCifrasEntrada["e"]   = 64;
    alturasCifrasEntrada["f"]   = 65;
    alturasCifrasEntrada["f#"]  = 66;
    alturasCifrasEntrada["g"]   = 67;
    alturasCifrasEntrada["g#"]  = 68;
    alturasCifrasEntrada["a"]   = 69;
    alturasCifrasEntrada["a#"]  = 70;
    alturasCifrasEntrada["b"]   = 71;
}

ProcessaEntrada::~ProcessaEntrada(){

}

int ProcessaEntrada::mostraValorMIDIAlturas(string altura){
    return alturasCifrasEntrada[altura];
}

void ProcessaEntrada::converteAlturasParaInteiros(list<string> &entradas){

    for(auto altura : entradas){
        alturasConvertidas.push_back(alturasCifrasEntrada[altura]);
    }

}



void ProcessaEntrada::verificaEntrada(string listaDeEntrada, int opcaoDeEntrada){

    if(opcaoDeEntrada == 1){
        separaListas(listaDeEntrada, alturasCifras);
        converteAlturasParaInteiros(alturasCifras);
    }else if(opcaoDeEntrada == 2){
        separaListas(listaDeEntrada, duracoes);
    }

}


// recebe uma string contendo apenas caracteres correspondentes as alturas
// e converte em uma lista de strings com as alturas separadas
void ProcessaEntrada::separaListas(string listaDeEntrada, list<string> &listaAlturas){
    stringstream ss;
    string alturaAtual;
    size_t pos;
	pos = listaDeEntrada.find(',');
	while(pos!=string::npos)
	{
		string num = listaDeEntrada.substr(0,pos);
		listaDeEntrada.erase(0,pos+1);
		ss.str(num);

		ss >> alturaAtual;

		if (!ss.fail()){
            listaAlturas.push_back(alturaAtual);
            //alturasCifras.push_back(alturaAtual);
		}else{
            cout << "Entrada inválida. Por favor, entre com o formato x1,x2,x3..." << endl;
		}
		pos = listaDeEntrada.find(',');
		ss.clear();
		ss.str("");
	}
	ss.str(listaDeEntrada);
	ss >> alturaAtual;
	if (!ss.fail()){
        listaAlturas.push_back(alturaAtual);
        //alturasCifras.push_back(alturaAtual);
    }else{
        cout << "Entrada inválida. Por favor, entre com o formato x1,x2,x3..." << endl;
    }

	ss.clear();
	ss.str("");
    alturasCifras = listaAlturas;
}


// recebe uma lista string de entrada contendo números apenas
// e converte essa entrada numa lista de números, que representam
// as durações
void ProcessaEntrada::separaListas(string listaDeEntrada, list<int> &listaDuracoes){
    int i;
    stringstream ss;
    size_t pos;
	pos = listaDeEntrada.find(',');
	while(pos!=string::npos)
	{
		string num = listaDeEntrada.substr(0,pos);
		listaDeEntrada.erase(0,pos+1);
		ss.str(num);

		ss >> i;

		if (!ss.fail()){
			listaDuracoes.push_back(i);
		}else{
            cout << "Entrada invalida. Por favor entre com números 1,2,3 ..."  << endl;
		}
		pos = listaDeEntrada.find(',');
		ss.clear();
		ss.str("");
	}
	ss.str(listaDeEntrada);
	ss >> i;
	if (!ss.fail()){
		listaDuracoes.push_back(i);
	}else{
        cout << "Entrada invalida. Por favor entre com números 1,2,3 ..."  << endl;
	}

	ss.clear();
	ss.str("");

}



list<int> ProcessaEntrada::retornaAlturasNumericas(){
    return alturasConvertidas;
}

list<int> ProcessaEntrada::retornaDuracoes(){
    return duracoes;
}


// Esse método retorna uma lista com as alturas em cifras (strings)
// essas cifras são as chaves do dicionário alturasCifrasEntrada

/*
    duas ideias para implementação:
    1ª: percorrer o unordered_map e armazenar as chaves numa lista para depois comparar
    2ª: no momento de criação da lista de alturas convertidas, colocar as alturas cifradas em uma lista
*/

list<string> ProcessaEntrada::retornaAlturasString(){
    return alturasCifras;
}

