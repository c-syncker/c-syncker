#ifndef NOTA_H
#define NOTA_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Nota
{

    unordered_map<string, int> dicionarioAlturasCifradasNumerosMIDI; 

    string altura;
    string acidente1;
    string acidente2;
    string indice;
    int oitava;
    int duracao;
    int intensidade;
    int alturaNumerica;


    public:
        Nota();
        virtual ~Nota();
        string toString();
        
        void atribuaAltura(string altura);
        void atribuaAcidente1(string acidente1);
        void atribuaAcidente2(string acidente2);
        void atribuaOitava(int oitava);
        void atribuaDuracao(int duracao);
        void atribuaIntensidade(int intensidade);
        void atribuaAlturaNumerica(int alturaNumerica);

        int pegueOitava();
        int pegueDuracao();
        int pegueIntensidade();
        int pegueAlturaNumerica();
        string pegueAltura();
        string pegueAcidente1();
        string pegueAcidente2();
    

    protected:

    private:
};

#endif // NOTA_H
