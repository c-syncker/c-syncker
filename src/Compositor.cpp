#include "Compositor.h"

Compositor::Compositor()
{
    //ctor
}

Compositor::~Compositor()
{
    //dtor
}

void Compositor::associar(list<string> &alturas, list<int> &duracoes, list<int> &intensidades){
        if(alturas.size() == duracoes.size() && alturas.size() == intensidades.size()){

            //Nota nota;
            int cont = 0;
            auto altura = alturas.begin();
            auto duracao = duracoes.begin();
            auto intensidade = intensidades.begin();

            while(alturas.size() > cont){
                Nota nota;
                nota.atribuaAltura(*altura);
                nota.atribuaDuracao(*duracao);
                nota.atribuaIntensidade(*intensidade);
                listaDeNotas.push_back(nota);
                altura++;
                duracao++;
                intensidade++;
                cont++;
            }

        }else{
            cout << "Tamanho das listas diferente. Por favor, sincronize-as primeiro." << endl;
        }
}

void Compositor::associar(list<string> &alturas, list<int> &duracoes){
        
        if(alturas.size() == duracoes.size() &&  (!alturas.empty() && !duracoes.empty())){
            int cont = 0;
            string alturaString;

            conjuntoDeNotas.convertaEmNotas(alturas, duracoes);
            listaDeNotas = conjuntoDeNotas.pegueNotas();
            conjuntoDeNotas.limpeListaDeNotas();

        }else{
            cout << "Tamanho das listas diferente. Por favor, sincronize-as primeiro." << endl;
        }
}

void Compositor::desassociar(list<Nota> &listaDeNotas){
   
    alturas.erase(alturas.begin(), alturas.end());
    duracoes.erase(duracoes.begin(), duracoes.end());
    listaDeIDs.erase(listaDeIDs.begin(), listaDeIDs.end());

    if(listaDeNotas.empty())
    {
        cout << "Lista de notas vazia!" << endl;
    }
    else
    {
        for(auto nota : listaDeNotas)
        {
            alturas.push_back(nota.pegueAltura()+nota.pegueAcidente1()+nota.pegueAcidente2()+to_string(nota.pegueOitava()));
            duracoes.push_back(nota.pegueDuracao());
            listaDeIDs.push_back(nota.pegueID());
            //intensidades.push_back(nota->pegueIntensidade());
        }
    }
}

list<Nota>   *Compositor::pegueListaDeNotas() { return &listaDeNotas;}
list<int>    *Compositor::pegueListaDuracoes() { return &duracoes;}
list<int>    *Compositor::pegueListaIntensidades() { return &intensidades;}
list<string> *Compositor::pegueListaAlturas() { return &alturas;}
list<string> *Compositor::pegueListaDeIDs() { return &listaDeIDs;}

void Compositor::atribuaNotas( Notas &notas ){ this->conjuntoDeNotas = notas; }
void Compositor::limpeListaDeNotas() { listaDeNotas.erase(listaDeNotas.begin(), listaDeNotas.end()); }