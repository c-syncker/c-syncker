#ifndef LISTA_H
#define LISTA_H

class Lista {
    public:
        Lista();
        virtual ~Lista();

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

#endif // LISTA_H


/*
	template <typename T>
	class Lista : public std::vector<T> {
		
	}	

	list<Nota>
	
	void orderneLista(Lista &lista);
				|
				V
	void orderneLista(vector<Nota> &lista);


	class Secao : Lista, InterfaceLista

	(Secao)lista
	secao.desdobreLista(secao);


*/
