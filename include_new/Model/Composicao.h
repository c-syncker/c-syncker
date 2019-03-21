#ifndef COMPOSICAO_H
#define COMPOSICAO_H
#include <iostream>
#include <list>
#include "Secao.h"

using namespace std;


class Composicao
{
    list<Secao> secoes;

    public:
        Composicao();
        virtual ~Composicao();

    protected:

    private:
};

#endif // COMPOSICAO_H
