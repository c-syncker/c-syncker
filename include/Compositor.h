#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <iostream>
#include "Nota.h"
#include <list>	
#include <map>
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>

using namespace std;

class Compositor
{

    list<string> alturasCifras;
    list<string> alturasCifrasSemOitavas;
    list<string> listaDeIDs;
    list<string> duracoesString;
    list<int> duracoes;
    list<int> intensidades;
    list<int> alturasConvertidasCifrasNumerosMIDI;
    list<Nota> listaDeNotas;

    unordered_map<string, int> dicionarioAlturasCifradasNumerosMIDI;

    public:

        Compositor();
        virtual ~Compositor();
        
        // usar o metodo convertaEmNotas no lugar do associar.
		list<Nota> associeEmNotas(list<string> &alturasRecebidas, list<int> &duracoesRecebidas);
		
		// sobrecarga para funcionar com listas de duracoes no formato string
		list<Nota> associeEmNotas(list<string> &alturas, list<string> &duracoes);
		
		void desassociar(list<Nota> &listaDeNotas);
		
		void calculeEnarmonia(string entrada, int tam);
		
		void removaChars(string &entrada);
		
		// getters
		list<Nota>   *pegueListaDeNotas();
        list<int>    *pegueListaDuracoes();
        list<int>    *pegueListaIntensidades();
        list<string> *pegueListaAlturas();
        list<string> *pegueListaDeIDs();
        list<string> *pegueListaDeAlturasSemOitavas();
        list<int> pegueAlturasNumerosMIDI();
		
		void limpeListaDeNotas();
        void limpeListaDeAlturas();
        void limpeListaDeDuracoes();
        void limpeListas();
        
    private:
        template <typename T>
        vector<T> convertaListEmVector(list<T>);
};

#endif // COMPOSITOR_H
