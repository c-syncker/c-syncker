#ifndef MOTIVO_H
#define MOTIVO_H

#include <iostream>
#include <list>
#include "Inciso.h"

using namespace std;

class Motivo
{
    list<Inciso> incisos;

    public:
        Motivo();
        virtual ~Motivo();

    protected:

    private:
};

#endif // MOTIVO_H
