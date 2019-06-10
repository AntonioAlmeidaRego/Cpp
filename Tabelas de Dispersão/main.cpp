#include <iostream>
#include <stdlib.h>
using namespace std;

//----- Classe No------
template <class T>
class No{

    public:
        No(){
            prox = NULL;
        }
    No* getProx(){
      return this->prox;
    }

    void setProx(No *p){
        this->prox = p;
    }

    T getChave(){
        return this->chave;
    }

    void setChave(T c){
        this->chave = c;
    }

    private:
        T chave;
        No *prox;
};


//--------- Classe Lista Encadeada-------
template <class T>
class Lista: public No<T>{


    public:
        Lista(){
            noCabeca = new No<T>();
            noCabeca->setProx(NULL);
        }
    void inserirList(No<T> *novo);
    bool remover(T chave);
    T print();
    No<T>* search(T chave);
    No<T>* Proximo(T chave);
    No<T>* Busca_final();
    No<T>* Anterior(T chave);
    No<T>* NoFinal(T chave);
    void clear();

    private:
        No<T> *noCabeca;
};
    template <class T>
    void Lista<T>::inserirList(No<T> *novo){
        No<T> *aux = noCabeca->getProx();
        noCabeca->setProx(novo);
        novo->setProx(aux);
    }
    template <class T>
    No<T>* Lista<T>::Busca_final(){
        No<T> *aux = noCabeca->getProx();
        No<T> *ultimo = noCabeca;
        while(aux != NULL){
            ultimo = aux;
            aux = aux->getProx();
        }
        return ultimo;
    }
    template <class T>
    No<T>* Lista<T>::NoFinal(T chave){
        No<T> *aux = noCabeca->getProx();
        No<T> *ant = noCabeca;
        while((aux != NULL) && (aux->getChave() != chave)){
            ant = aux;
            aux = aux->getProx();
        }
        return ant;
    }
    template <class T>
    No<T>* Lista<T>::Proximo(T chave){
        No<T> *aux = noCabeca->getProx();
        No<T> *ant = noCabeca;
        No<T> *ultimo = noCabeca;
        while((aux != NULL)){
            ultimo = aux;
            if(ultimo->getChave() == chave){
                aux = aux->getProx();
                return aux;
            }
            aux = aux->getProx();
        }
    }
    template <class T>
    No<T>* Lista<T>::Anterior(T chave){
        No<T> *aux = noCabeca->getProx();
        No<T> *ultimo = noCabeca;
        No<T> *ant = noCabeca;
        while(aux != NULL){
            ultimo = aux;
            if(ultimo->getChave() == chave){
                return ant;
            }
            ant = ultimo;
            aux = aux->getProx();
        }

    }
    template <class T>
    No<T>* Lista<T>::search(T chave){
        No<T> *aux = noCabeca->getProx();
        while((aux != NULL) && (aux->getChave() != chave)){
            aux = aux->getProx();
        }
        return aux;
    }
    template <class T>
    bool Lista<T>::remover(T chave){
        No<T> *busca;
        No<T> *buscafinal = Busca_final();
        No<T> *anterior = Anterior(chave);
        No<T> *nofinal = NoFinal(chave);
        No<T> *proximo = Proximo(chave);

        busca = search(chave);
        if((busca != NULL) && (busca == noCabeca->getProx())){
            noCabeca = noCabeca->getProx();
            delete busca;
        }else if((busca != NULL) && (busca == buscafinal)){
            nofinal->setProx(NULL);
            delete busca;
        }else if((busca != NULL) && (busca != buscafinal)){
            anterior->setProx(proximo);
            delete busca;
        }

    }
    template <class T>
    void Lista<T>::clear(){
        No<T> *aux = noCabeca->getProx();
        while(aux != NULL){
            delete aux;
            aux = aux->getProx();
        }
        noCabeca->setProx(NULL);
    }
    template <class T>
    T Lista<T>::print(){
        No<T> *aux = noCabeca->getProx();
        while((aux != NULL) && (aux->getChave() != 0)){
            cout << aux->getChave() << " ";
            aux = aux->getProx();
        }
    }
//-------- Classe HashTable ------------
template <class T>
    class HashTable: public No<T>, public Lista<T>{

    public:
        HashTable(int m){
            this->M = m;
            table = new Lista<T>[M];
            qtd = 0;
        }

    bool Insert(T chave);
    bool Remove(T chave);
    No<T>* Search(T chave);
    void PrintHashTable();
    int H(T chave);
    int size();
    void clear();

    private:
        Lista<T> *table;
        int qtd;
        int M;

};
    template <class T>
    int HashTable<T>::size(){
        return qtd;
    }
    template <class T>
    int HashTable<T>::H(T chave){
        return (int)chave % M;
    }
    template <class T>
    bool HashTable<T>::Insert(T chave){
        No<T> *novo = new No<T>();
        novo->setChave(chave);
        table[H(novo->getChave())].inserirList(novo);
            qtd++;
        return true;

    }
    template <class T>
    bool HashTable<T>::Remove(T chave){
        for(int i = 0; i< M;i++){
            table[i].remover(chave);
        }
        qtd--;
        return true;
    }
    template <class T>
    No<T>* HashTable<T>::Search(T chave){
        No<T> *aux = NULL;
        bool achou = false;
        for(int i = 0; i < M;i++){
             aux = table[i].search(chave);
             if(aux != NULL){
                cout<<"RESULTADO DA SEARCH: "<<aux->getChave()<<" "<<"NA POSICAO "<<i;
                achou = true;
                break;
         	}
        }
        if(achou == false){
            cout<<"\nCHAVE NAO ENCONTRADA\n";
		}
        return aux;
    }
    template <class T>
    void HashTable<T>::clear(){
        for(int i =0; i<M;i++){
            table[i].clear();
        }
        qtd = 0;
    }
    template <class T>
    void HashTable<T>::PrintHashTable(){
        for(int i = 0;i<M;i++){
            cout<<i<<"-> ";
            table[i].print();
            cout << endl;
        }
    }
//----- Menu de Escolha para Escolher o tipo ---------
template<class T>
void MenuEscolhas(int M){
    int esc;
    T chave, chave2, chave3;
    No <T> n;
    Lista <T> l;
    HashTable <T> *h = new HashTable<T>(M);
    system("cls");
    do{
        cout<<"\nPARA INSERIR DIGITE 1\n";
        cout<<"\nPARA REMOVER DIGITE 2\n";
        cout<<"\nPARA SEARCH  DIGITE 3\n";
        cout<<"\nPARA CLEAR   DIGITE 4\n";
        cout<<"\nDIGITE SUA ESCOLHA\n";
        cin>>esc;
        switch(esc){
            case 1:
                cout<<"\nDIGITE A CHAVE: \n";
                cin>>chave;
                h->Insert(chave);
                break;
            case 2:
                cout<<"\nDIGITE A CHAVE: \n";
                cin>>chave2;
                h->Remove(chave2);
                break;
            case 3:
                cout<<"\nDIGITE A CHAVE: \n";
                cin>>chave3;
                h->Search(chave3);
                break;
            case 4:
                h->clear();
                break;
            default:
                if(esc != 0){
                    cout<<"\nVALOR INVALIDO\n";
                }
                break;
        }
        cout<<"\n\n";
        cout<<"\nSIZE: "<<h->size();
        cout<<"\n";
        h->PrintHashTable();
    }while(esc != 0);
}
int main(){

    int esc;
    int M;

    cout<<"\nDIGITE O TAMANHO DA TABELA: \n";
    cin>>M;
    if(M>0){
        cout<<"\nESCOLHA O TIPO\n";
        cout<<"\nPARA TIPO INT    DIGITE 1\n";
        cout<<"\nPARA TIPO DOUBLE DIGITE 2\n";
        cout<<"\nPARA TIPO FLOAT  DIGITE 3\n";
        cout<<"\nPARA TIPO CHAR   DIGITE 4\n";
        cout<<"\nPARA TIPO LONG   DIGITE 5\n";
        cout<<"\nDIGITE SUA ESCOLHA\n";
        cin>>esc;
        switch(esc){
            case 1:
                MenuEscolhas<int>(M);
                break;
            case 2:
                MenuEscolhas<double>(M);
                break;
            case 3:
                MenuEscolhas<float>(M);
                break;
            case 4:
                MenuEscolhas<char>(M);
                break;
            case 5:
                MenuEscolhas<long>(M);
                break;
        }

    }else{
        cout<<"\nTAMANHO INVALIDO!\n";
    }


    return 0;
}
