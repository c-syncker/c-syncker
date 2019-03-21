#ifndef SECAO_H
#define SECAO_H
#include <iostream>
#include <list>
#include "Grupo.h"

using namespace std;

class Secao
{
    list<Grupo> grupos;

    public:
        Secao();
        virtual ~Secao();

    protected:

    private:
};

#endif // SECAO_H
