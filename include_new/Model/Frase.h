#ifndef FRASE_H
#define FRASE_H
#include <iostream>
#include <list>
#include "Motivo.h"
#include "InterfaceLista.h"

using namespace std;

class Frase : public Lista, public InterfaceLista
{
    list<Motivo> motivos;

    public:
        Frase();
        virtual ~Frase();

        void orderneLista(Lista &lista);
        void deriveLista(Lista &lista);
        void desdobreLista(Lista &lista, int nVezes);
        void junteListas(Lista &lista1, Lista &lista2);
        void removaRepeticoes(Lista &lista);
        void revertaLista(Lista &lista);
        void exibaLista(Lista &lista);


    protected:

    private:
};

#endif // FRASE_H
