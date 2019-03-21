#ifndef INCISO_H
#define INCISO_H

#include <iostream>
#include <list>
#include "Nota.h"

using namespace std;

class Inciso
{
    list<Nota> notas;

    public:
        Inciso();
        virtual ~Inciso();

    protected:

    private:
};

#endif // INCISO_H
