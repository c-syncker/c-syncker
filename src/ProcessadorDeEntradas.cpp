#include "ProcessadorDeEntradas.h"

ProcessadorDeEntradas::ProcessadorDeEntradas()
{

    // essa passagem vai servir como um parser para converter as alturas em listas de inteiros
    /*
    dicionarioAlturasCifradasNumerosMIDI["c"]   = 60;
    dicionarioAlturasCifradasNumerosMIDI["c#"]  = 61; // dúvida sobre essa representação de sustenido
    dicionarioAlturasCifradasNumerosMIDI["d"]   = 62;
    dicionarioAlturasCifradasNumerosMIDI["d#"]  = 63;
    dicionarioAlturasCifradasNumerosMIDI["e"]   = 64;
    dicionarioAlturasCifradasNumerosMIDI["f"]   = 65;
    dicionarioAlturasCifradasNumerosMIDI["f#"]  = 66;
    dicionarioAlturasCifradasNumerosMIDI["g"]   = 67;
    dicionarioAlturasCifradasNumerosMIDI["g#"]  = 68;
    dicionarioAlturasCifradasNumerosMIDI["a"]   = 69;
    dicionarioAlturasCifradasNumerosMIDI["a#"]  = 70;
    dicionarioAlturasCifradasNumerosMIDI["b"]   = 71;
    */

    dicionarioAlturasCifradasNumerosMIDI["c"] = 0;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 1;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 2;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 3;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 4;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 5;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 6;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 7;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 8;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 9;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 10;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 11;
/*
    dicionarioAlturasCifradasNumerosMIDI["c"] = 12;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 13;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 14;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 15;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 16;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 17;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 18;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 19;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 20;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 21;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 22;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 23;
    dicionarioAlturasCifradasNumerosMIDI["c"] = 24;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 25;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 26;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 27;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 28;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 29;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 30;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 31;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 32;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 33;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 34;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 35;
    dicionarioAlturasCifradasNumerosMIDI["c"] = 36;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 37;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 38;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 39;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 40;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 41;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 42;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 43;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 44;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 45;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 46;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 47;
    dicionarioAlturasCifradasNumerosMIDI["c"] = 48;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 49;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 50;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 51;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 52;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 53;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 54;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 55;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 56;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 57;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 58;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 59;
    dicionarioAlturasCifradasNumerosMIDI["c"] = 60;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 61;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 62;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 63;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 64;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 65;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 66;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 67;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 68;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 69;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 70;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 71;
    dicionarioAlturasCifradasNumerosMIDI["c"] = 72;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 73;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 74;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 75;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 76;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 77;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 78;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 79;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 80;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 81;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 82;
    dicionarioAlturasCifradasNumerosMIDI["b"] = 83;
    dicionarioAlturasCifradasNumerosMIDI["c "] = 84;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 85;
    dicionarioAlturasCifradasNumerosMIDI["d "] = 86;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 87;
    dicionarioAlturasCifradasNumerosMIDI["e" ] = 88;
    dicionarioAlturasCifradasNumerosMIDI["f" ] = 89;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 90;
    dicionarioAlturasCifradasNumerosMIDI["g "] = 91;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 92;
    dicionarioAlturasCifradasNumerosMIDI["a" ] = 93;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 94;
    dicionarioAlturasCifradasNumerosMIDI["b" ] = 95;
    dicionarioAlturasCifradasNumerosMIDI["c" ] = 96;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 97;
    dicionarioAlturasCifradasNumerosMIDI["d "] = 98;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 99;
    dicionarioAlturasCifradasNumerosMIDI["e "] = 100;
    dicionarioAlturasCifradasNumerosMIDI["f "] = 101;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 102;
    dicionarioAlturasCifradasNumerosMIDI["g "] = 103;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 104;
    dicionarioAlturasCifradasNumerosMIDI["a "] = 105;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 106;
    dicionarioAlturasCifradasNumerosMIDI["b "] = 107;
    dicionarioAlturasCifradasNumerosMIDI["c "] = 108;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 109;
    dicionarioAlturasCifradasNumerosMIDI["d "] = 110;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 111;
    dicionarioAlturasCifradasNumerosMIDI["e "] = 112;
    dicionarioAlturasCifradasNumerosMIDI["f "] = 113;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 114;
    dicionarioAlturasCifradasNumerosMIDI["g "] = 115;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 116;
    dicionarioAlturasCifradasNumerosMIDI["a "] = 117;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 118;
    dicionarioAlturasCifradasNumerosMIDI["b "] = 119;
    dicionarioAlturasCifradasNumerosMIDI["c "] = 120;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 121;
    dicionarioAlturasCifradasNumerosMIDI["d "] = 122;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 123;
    dicionarioAlturasCifradasNumerosMIDI["e "] = 124;
    dicionarioAlturasCifradasNumerosMIDI["f "] = 125;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 126;
    dicionarioAlturasCifradasNumerosMIDI["g "] = 127;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 128;
    dicionarioAlturasCifradasNumerosMIDI["a "] = 129;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 130;
    dicionarioAlturasCifradasNumerosMIDI["b "] = 131;
*/

    /*
    dicionarioNumerosMIDIDAlturasCifradas[60] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[61] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[62] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[63] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[64] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[65] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[66] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[67] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[68] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[69] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[70] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[71] = "b";
    */

    dicionarioNumerosMIDIDAlturasCifradas[0] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[1] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[2] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[3] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[4] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[5] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[6] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[7] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[8] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[9] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[10] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[11] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[12] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[13] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[14] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[15] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[16] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[17] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[18] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[19] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[20] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[21] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[22] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[23] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[24] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[25] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[26] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[27] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[28] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[29] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[30] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[31] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[32] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[33] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[34] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[35] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[36] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[37] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[38] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[39] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[40] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[41] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[42] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[43] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[44] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[45] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[46] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[47] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[48] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[49] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[50] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[51] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[52] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[53] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[54] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[55] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[56] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[57] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[58] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[59] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[60] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[61] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[62] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[63] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[64] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[65] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[66] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[67] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[68] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[69] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[70] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[71] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[72] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[73] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[74] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[75] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[76] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[77] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[78] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[79] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[80] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[81] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[82] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[83] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[84] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[85] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[86] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[87] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[88] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[89] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[90] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[91] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[92] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[93] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[94] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[95] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[96] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[97] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[98] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[99] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[100] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[101] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[102] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[103] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[104] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[105] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[106] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[107] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[108] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[109] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[110] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[111] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[112] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[113] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[114] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[115] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[116] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[117] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[118] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[119] = "b";
    dicionarioNumerosMIDIDAlturasCifradas[120] = "c";
    dicionarioNumerosMIDIDAlturasCifradas[121] = "c#";
    dicionarioNumerosMIDIDAlturasCifradas[122] = "d";
    dicionarioNumerosMIDIDAlturasCifradas[123] = "d#";
    dicionarioNumerosMIDIDAlturasCifradas[124] = "e";
    dicionarioNumerosMIDIDAlturasCifradas[125] = "f";
    dicionarioNumerosMIDIDAlturasCifradas[126] = "f#";
    dicionarioNumerosMIDIDAlturasCifradas[127] = "g";
    dicionarioNumerosMIDIDAlturasCifradas[128] = "g#";
    dicionarioNumerosMIDIDAlturasCifradas[129] = "a";
    dicionarioNumerosMIDIDAlturasCifradas[130] = "a#";
    dicionarioNumerosMIDIDAlturasCifradas[131] = "b";

}

ProcessadorDeEntradas::~ProcessadorDeEntradas(){

}

int ProcessadorDeEntradas::mostreValorMIDIDasAlturas(string altura){
    return dicionarioAlturasCifradasNumerosMIDI[altura];
}

void ProcessadorDeEntradas::convertaAlturasCifradasParaNumeroMIDI(list<string> &entradas){
    limpeLista(alturasConvertidasCifrasNumerosMIDI);
    for(auto altura : entradas){
        alturasConvertidasCifrasNumerosMIDI.push_back(dicionarioAlturasCifradasNumerosMIDI[altura]);
    }

}

void ProcessadorDeEntradas::convertaNumeroMIDIParaAlturasCifradas(list<int> &entradasInteiro, list<string> &saidaString){
    for(auto elemento : entradasInteiro){
        saidaString.push_back(dicionarioNumerosMIDIDAlturasCifradas[elemento]);
    }
}



void ProcessadorDeEntradas::verifiqueEntrada(string listaDeEntrada, int opcaoDeEntrada){

    if(opcaoDeEntrada == 1){
        limpeLista(alturasCifras);
        gereListaAlturas(listaDeEntrada, alturasCifras);
        convertaAlturasCifradasParaNumeroMIDI(alturasCifras);
    }else if(opcaoDeEntrada == 2){
        limpeLista(duracoesString);
        gereListaDuracoes(listaDeEntrada, duracoesString);
    }

}

// recebe uma string contendo apenas caracteres correspondentes as alturas
// e converte em uma lista de strings com as alturas separadas
void ProcessadorDeEntradas::gereListaAlturas(string listaDeEntrada, list<string> &listaAlturas){
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

    for(auto elemento : alturasCifras){
        notas.calculeEnarmonia(elemento, elemento.size());
    }

    listaDeNotas = notas.pegueNotas();
    notas.limpeListaDeNotas();
}


// recebe uma lista string de entrada contendo números apenas
// e converte essa entrada numa lista de números, que representam
// as durações
void ProcessadorDeEntradas::gereListaDuracoes(string listaDeEntrada, list<string> &listaDuracoes){
    int i;
    limpeLista(duracoes);
    stringstream ss;
    size_t position;
	position = listaDeEntrada.find(',');
	while(position!=string::npos)
	{
		string num = listaDeEntrada.substr(0,position);
		listaDeEntrada.erase(0,position+1);
		ss.str(num);
        //cout << num << endl;
		ss >> i;

		if (!ss.fail()){
			listaDuracoes.push_back( to_string(i) );
            duracoes.push_back(i);
		}else{
            cout << "Entrada inválida. Por favor entre com números 1,2,3 ..."  << endl;
		}
		position = listaDeEntrada.find(',');
		ss.clear();
		ss.str("");
	}
	ss.str(listaDeEntrada);
	ss >> i;
    if (!ss.fail()){
		listaDuracoes.push_back( to_string(i) );
        duracoes.push_back(i);
	}else{
        cout << "Entrada inválida. Por favor entre com números 1,2,3 ..."  << endl;
	}

	ss.clear();
	ss.str("");

    // criação de listas de notas para fazer todos os dados no programa
    // serem de um único tipo
    // list<string> listaTemporariaDeAlturas;
    // for(int i=0; i<duracoes.size(); i++)
    // {
    //     listaTemporariaDeAlturas.push_back("");
    // }

    // notas.convertaEmNotas(listaTemporariaDeAlturas, duracoes);

    for(auto elemento : listaDuracoes){
        notas.calculeEnarmonia( elemento , elemento.size());
    }

    listaDeNotas = notas.pegueNotas();
    notas.limpeListaDeNotas();

}


list<int> ProcessadorDeEntradas::pegueAlturasNumeroMIDI(){
    return alturasConvertidasCifrasNumerosMIDI;
}

list<int> ProcessadorDeEntradas::pegueDuracoes(){
    return duracoes;
}

list<string> ProcessadorDeEntradas::pegueAlturasCifradas(){
    return alturasCifras;
}

void ProcessadorDeEntradas::limpeLista(list<int> &entrada){
    if(entrada.size() != 0){
        while(entrada.begin() != entrada.end()){
            entrada.pop_front();
        }
    }

}

void ProcessadorDeEntradas::limpeLista(list<string> &entrada){
    if(entrada.size() != 0){
        while(entrada.begin() != entrada.end()){
            entrada.pop_front();
        }
    }
}

void ProcessadorDeEntradas::extraiNotas(string entrada){
    
    limpeLista(alturasCifras);
    limpeLista(duracoesString);
    listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end());
    //cout << "Processador de Entradas: " << entrada << endl;
    entradaSeparada = {entrada.begin(), entrada.end()};

    entradaSeparada.push_back(','); // adiciono uma vírgula ao final da string para que 
                                    // o iterador vá até o final. Ex: f#3,g4,c#4, 
                                    // assim, todos os valores de alturas serão analisados 
                                    // caso contrário, o valor c#4 ficaria de fora
    int cont = 0, tam = 0;
    string aux = "";

    for(auto valor : entradaSeparada)
    {
        if( tam == (entradaSeparada.size()-1) )
        {
            break;
        }

        if(valor != ',')
        {   
            cont++; // usada para calcular o tamanho da nota que será passada para o cálculo da enarmonia
            aux += valor;
            tam++;
        }else{
            //cout << aux << endl;
            //calculeEnarmonia(aux, cont);
            notas.calculeEnarmonia(aux, cont);
            //cout << "Conversão finalizada" << endl;
            cont = 0;
            tam++;
            aux = ""; 
        }
    }

    listaDeNotas = notas.pegueNotas();
}

list<Nota> ProcessadorDeEntradas::pegueNotas()
{
    return listaDeNotas;
}

void ProcessadorDeEntradas::atribuaNotas(Notas &notas)
{
    this->notas = notas;
}

string ProcessadorDeEntradas::convertaListaEmString(list<string> &entrada)
{
    string resultado = "";

    for(auto valor : entrada){
        resultado += valor + ",";
    }
    size_t pos = resultado.length()-1;
    resultado[pos] = '\0';
    return resultado;
}

void ProcessadorDeEntradas::limpeListaDeNotas()
{
    listaDeNotas.erase( listaDeNotas.begin(), listaDeNotas.end() );
}