#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include <list>
#include "Frase.h"

using namespace std;

class Grupo
{
    list<Frase> frases;

    public:
        Grupo();
        virtual ~Grupo();

    protected:

    private:
};

#endif // GRUPO_H
