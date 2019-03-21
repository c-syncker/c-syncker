#include "Nota.h"

Nota::Nota()
{
    dicionarioAlturasCifradasNumerosMIDI["c"] = 0;
    dicionarioAlturasCifradasNumerosMIDI["c#"] = 1;
    dicionarioAlturasCifradasNumerosMIDI["d"] = 2;
    dicionarioAlturasCifradasNumerosMIDI["d#"] = 3;
    dicionarioAlturasCifradasNumerosMIDI["e"] = 4;
    dicionarioAlturasCifradasNumerosMIDI["f"] = 5;
    dicionarioAlturasCifradasNumerosMIDI["f#"] = 6;
    dicionarioAlturasCifradasNumerosMIDI["g"] = 7;
    dicionarioAlturasCifradasNumerosMIDI["g#"] = 8;
    dicionarioAlturasCifradasNumerosMIDI["a"] = 9;
    dicionarioAlturasCifradasNumerosMIDI["a#"] = 10; 
    dicionarioAlturasCifradasNumerosMIDI["b"] = 11;

    altura = "";
    acidente1 = "";
    acidente2 = "";
    oitava = 0;
    duracao = 0;
    id = "";

}

Nota::~Nota()
{
    //dtor
}

string Nota::toString(){
     return altura +  acidente1 + acidente2 + ( altura != "" ? to_string(oitava) : "") + "" + (duracao != 0 ? to_string(duracao) : "") ;
}

int Nota::pegueAlturaNumerica(){
    return alturaNumerica;
}

int Nota::pegueDuracao(){
    return duracao;
}

int Nota::pegueOitava(){
    return oitava;
}

int Nota::pegueIntensidade(){
    return intensidade;
}

string Nota::pegueAcidente1(){
    return acidente1;
}

string Nota::pegueAcidente2(){
    return acidente2;
}

string Nota::pegueAltura(){
    return altura;
}

string Nota::pegueIndice(){
    return indice;
}

string Nota::pegueNoPai(){
    return idPai;
}

string Nota::pegueID()
{
    return id;
}

void Nota::atribuaAcidente1(string acidente1){
    this->acidente1 = acidente1;
}

void Nota::atribuaAcidente2(string acidente2){
    this->acidente2 = acidente2;
}

void Nota::atribuaAltura(string altura){
    this->altura = altura;
}

void Nota::atribuaOitava(int oitava){
    this->oitava = oitava;
}

void Nota::atribuaDuracao(int duracao){
    this->duracao = duracao;
}

void Nota::atribuaIntensidade(int intensidade){
    this->intensidade = intensidade;
}

void Nota::atribuaAlturaNumerica(int alturaNumerica){
    this->alturaNumerica = alturaNumerica;
}

void Nota::atribuaNoPai(string no){
    this->idPai = no;
}

void Nota::atribuaIndice(string indice){
    this->indice = indice;
}

void Nota::atribuaID(string id){
    this->id = id;
}