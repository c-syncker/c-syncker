#ifndef FACHADADOPROCESSADORDELISTAS_H
#define FACHADADOPROCESSADORDELISTAS_H
#include "Lista.h"

class FachadaDoProcessadorDeListas
{
    public:
        FachadaDoProcessadorDeListas();
        virtual ~FachadaDoProcessadorDeListas();

        /*  INTERFACE QUE TODAS AS CLASSES QUE SEJAM LISTAS DEVEM IMPLEMENTAR.
            O OBJETIVO DISSO É QUE AS OPERAÇÕES DE LISTAS SEJAM HOMOGÊNEAS E
            QUEM IMPLEMENTAR ESTA INTERFACE SABERÁ REALIZAR QUALQUER OPERAÇÃO
            SOBRE LISTAS.
            PODEMOS FAZER ALGUMAS SOBRECARGAS DE OPERADORES NESSA CLASSE PARA
            FACILITAR A MANIPULAÇÃO DE LISTAS PELO USUÁRIO.
        */

        virtual void orderneLista(Lista &lista) = 0;
        virtual void deriveLista(Lista &lista) = 0;
        virtual void desdobreLista(Lista &lista, int nVezes) = 0;
        virtual void junteListas(Lista &lista1, Lista &lista2) = 0;
        virtual void removaRepeticoes(Lista &lista) = 0;
        virtual void revertaLista(Lista &lista) = 0;
        virtual void exibaLista(Lista &lista) = 0;

        /*
            BLOCO DE SOBRECARGA DE OPERADORES
        */

        /*
            Lista operator+ (Lista &lista); // soma duas listas (coloca uma no final da outra)
            Lista operator- (Lista &lista); // faz a diferença entre duas listas (membros diferentes permanecem)
            Lista operator* (Lista &lista); // desdobra uma lista n vezes
            bool operator== (Lista &lista); // testa se duas listas sao iguais
            bool operator!= (Lista &lista); // testa se duas listas são diferentes
        */

       
    protected:

    private:
};

#endif // OPERACOESSOBREEVENTOS_H
