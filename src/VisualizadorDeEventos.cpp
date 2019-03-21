#include "VisualizadorDeEventos.h"

void VisualizadorDeEventos::imprimaLista(list<Nota> listaParaExibir)
{
    auto inicio_aux = listaParaExibir.front().toString();
    auto fim_aux = listaParaExibir.back().toString();

    if(listaParaExibir.size() <= 1){
        cout << listaParaExibir.front().toString() << endl;
    }else{

        listaParaExibir.pop_front();
        listaParaExibir.pop_back();

        cout << inicio_aux << ",";
        for(auto elemento : listaParaExibir){
            cout << elemento.toString()<< ",";
        }

        cout << fim_aux << endl;
    }
}

