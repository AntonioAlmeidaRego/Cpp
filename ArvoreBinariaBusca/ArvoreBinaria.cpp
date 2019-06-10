/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArvoreBinario.cpp
 * Author: antonio
 * 
 * Created on 21 de Março de 2019, 06:55
 */
#include <iostream>
#include "ArvoreBinaria.h"
#include "Percurso.h"
using namespace std;
/*
 Classe da Arvore Binaria
 */

/*
 Construtor da Classe, em que é criada a raiz da Arvore que recebe dois parametros a chave e a informação
 */
ArvoreBinaria::ArvoreBinaria(int chave, char info) {
    this->tamanho = 0; // inicializo o atributo tamanho da arvore
    this->raiz = new No(); // instancio a criação da raiz
    this->raiz->setchave(chave); // atribuí a chave a raiz
    this->raiz->setinfo(info); // atribuí a informação a raiz
    this->raiz->setleft(NULL); // atribuí a raiz no momento sem filho a esquerda
    this->raiz->setright(NULL); // atribuí a raiz no momento sem filho a direita
    this->auxPai = raiz; // crio um atributo auxiliar que recebe a raiz
    this->teste = true; // crio um atributo auxiliar 
    tamanho++; // incremento o tamanho da raiz
    this->lista = new ListaEncadeada(); // instancio uma lista encadeada para auxiliar no método "completeTreeBB"
    this->lista2 = new ListaEncadeada();
}

ArvoreBinaria::ArvoreBinaria(const ArvoreBinaria& orig) {
}

ArvoreBinaria::~ArvoreBinaria() {
}
/*
 Método que retorna o tamanho atual da arvore.
 */
int ArvoreBinaria::size() {
    return this->tamanho;
}
/*
 Método que verifica se o filho esquerda está vazia, caso contrario returna false
 */
bool ArvoreBinaria::isemptyleft() {
    if(this->raiz->getleft() == NULL){
        return true;
    }
    return false;
}
/*
 Método que verifica se o filho direito está vazio, caso contrario returna false
 */
bool ArvoreBinaria::isemptyright() {
    if(this->raiz->getright() == NULL){
        return true;
    }
    return false;
}
/*
 Método que busca pelo pai da chave passada pelo parametro
 */
No* ArvoreBinaria::buscafather(No* raiz, int chave) {
    if(chave == raiz->getchave()){ // verifica se a chave é a raiz
        return this->auxPai; // returna o pai, se a chave for a raiz, ele retorna a propria raiz
    }else if(chave < getraiz()->getchave()){ // Senao se a chave é menor que a raiz
        if(raiz == NULL){ // verifica se a chave é nula se for retorna o pai dessa chave passada por parametro
            return this->auxPai;
        }else if(chave > raiz->getchave()){ // Senao a chave for maior que a raiz da chave
            this->auxPai = raiz; // o pai recebe a raiz
            raiz = raiz->getright();// raiz 'anda para direita' recursivamente
            return buscafather(raiz, chave);
        }else if(chave < raiz->getchave()){ // Senao se a chave é menor que a chave da raiz ele 'anda para esquerda'
            this->auxPai = raiz;
            raiz = raiz->getleft();
            return buscafather(raiz, chave);
        }
    }else if(chave > getraiz()->getchave()){// Senao a chave for maior que a raiz da chave
        if(raiz == NULL){// verifica se a chave é nula se for retorna o pai dessa chave passada por parametro
            return this->auxPai;
        }else if(chave > raiz->getchave()){// Senao a chave for maior que a raiz da chave
            this->auxPai = raiz;
            raiz = raiz->getright();
            return buscafather(raiz, chave);
        }else if(chave < raiz->getchave()){// Senao se a chave é menor que a chave da raiz ele 'anda para esquerda'
            this->auxPai = raiz;
            raiz = raiz->getleft();
            return buscafather(raiz, chave);
        }
    }
    return NULL;
}
/*
 Método que retorna o sucessor do parametro
 */
int ArvoreBinaria::sucessor(int v) {
    return v + 1;
}

/*
 Método que faz a busca da chave e retorna o seu sucessor
 */
No* ArvoreBinaria::buscaMin(No* r, int chave) {
    if(sucessor(chave) == r->getchave() && r->getchave() > sucessor(chave)){ // Verifica se a chave é igual e maior que raiz da chave passada por parametro
        return r; // retorna a raiz
    }else{
        // A logica é parecida com a pre-ordem, o algoritmo de percurso na arvore binaria
        if(r->getleft() != NULL){
            r = r->getleft();
            buscaMin(r, chave);
        }
        if(r->getright() != NULL){
            r = r->getright();
            buscaMin(r, chave);
        }
    }
    return r;
}

ArvoreBinaria* ArvoreBinaria::treeBB(ArvoreBinaria* a) {
    return completeTreeBB(a->raiz, a->size(), a);
}


/*
 Método que recebe uma arvore e retorna uma arvore completa
 */
ArvoreBinaria* ArvoreBinaria::completeTreeBB(No *raiz, int tamanho, ArvoreBinaria *a) {
    if(raiz == a->getraiz() && teste == true){// Verifica se a raiz é a raiz da arvore
        teste = false; // atributo auxiliar que possibilita que essa condição seja acessada em unica vez. 
        lista->inserir(a->getraiz()->getchave()); // adiciono na lista encadeada auxiliar a raiz da arvore passada por parametro
        completeTreeBB(a->raiz, tamanho, a); // e retorno recursivo para continuar o percurso na arvore
    }
    if(a->size() <= 1){ // Verifico se o tamanho da arvore é menor que 1, caso for retorna a arvore 
        return a;
    }else{ // Caso contrario continua o percurso
        if(lista->size() < tamanho){ // Verifico se o tamanho da lista é menor que o tamanho da arvore
            if(raiz != a->getraiz()){ // verifico se a raiz não é a raiz da arvore
                lista->inserir(raiz->getchave());
            } 
            if(raiz->getleft() != NULL){ // verifico se a raiz tem filho a esquerdo 
                completeTreeBB(raiz->getleft(), tamanho, a);
            }
            if(raiz->getright() != NULL){ // verifico se a raiz tem filho a direita
                completeTreeBB(raiz->getright(), tamanho, a);
            }
        }else{
            int i = 0; // variavel de incremento e controle do vetor auxiliar
            int *v = new int [lista->size()]; // criação de vetor dinamico
            while(!lista->isempty()){// enquanto a lista não é vazia é adicionado no vetor as chaves da arvores 
                int aux = lista->remove()->getchave(); // remove da lista encadeada para a variavel auxiliar a chave
                v[i] = aux; // E adiciono a posicao 'i' no vetor a chave da variavel 'aux'
                i++; // e incremento 
            }
            int aux2; // 'aux 2' outra variavel auxiliar
            // Um algoritmo de ordenação
            for(int i = 0;i<tamanho;i++){
                for(int j = i+1;j<tamanho;j++){
                    if(v[i] > v[j]){
                        aux2 = v[i];
                        v[i] = v[j];
                        v[j] = aux2;
                    }
                }
            }
            // Método que recebe um vetor e retorna uma arvore completa
            a = convertListTreeBBComplete(v, tamanho);
        }
    }
     
    return a;
}

 
/*
 Método que recebe um vetor e um tamanho e retorna uma arvore completa 
 */
ArvoreBinaria * ArvoreBinaria::convertListTreeBBComplete(int *vetor, int tamanho) {
    Lista *l = new Lista(vetor, tamanho); // instancio uma lista que recebe por parametro um vetor e também um tamanho
    
    int inicio = 0; // variavel auxiliar, recebe o inicio do vetor 
    int media1 = 0; // variavel auxiliar, a media das chaves sem a raiz da arvore até o inicio 
    int fim = tamanho-1; // variavel auxiliar, fim do vetor
    ArvoreBinaria *a;
    if(tamanho % 2 == 0){
        a = new ArvoreBinaria(vetor[(tamanho/2)], 'A'); // instancio um objeto arvore 
    }else{
        a = new ArvoreBinaria(vetor[tamanho/2], 'A'); // instancio um objeto arvore 
    }
    int meio = l->getposicaoleft(vetor[tamanho-1/2]); // recebe o meio do vetor antes da raiz da arvore
    int right = l->getposicaoright(vetor[tamanho-1/2]); // recebe o meio do vetor depois da raiz da arvore
    int *v2 = l->getlista(); // um vetor auxiliar
    int aux = 0;
    while(inicio < meio){ // enquanto o inicio é menor ao meio
        if(meio > 1){ 
            if(meio % 2 == 0){
                aux = meio/2;
                a->inserirABB(a->raiz, v2[aux], 'A');
                if(v2[aux+1] != 0 && v2[aux-1] != 0){
                    a->inserirABB(a->raiz, v2[aux-1], 'A');
                    a->inserirABB(a->raiz, v2[aux+1], 'A');
                }
            }else{
                aux = meio/2;
                a->inserirABB(a->raiz, v2[aux], 'A');
                if(v2[aux+1] != 0 && v2[aux-1] != 0){
                    a->inserirABB(a->raiz, v2[aux-1], 'A');
                    a->inserirABB(a->raiz, v2[aux+1], 'A');
                }
            }
        }else{
            a->inserirABB(a->raiz, v2[0], 'A');
        } 
        meio /= 2;
    }
    
    int *v = l->getlista();// vetor aux
    int meio2 = right; // variavel auxiliar 'meio2' recebe a chave direita apos a raiz da arvore 
    while(inicio < meio2){ // enquanto o 'meio2' for menor ou igual a fim fica no loop 
        if(meio2 > 1){ // Verifico se o 'meio2' é menor que o fim 
            if(meio2 % 2 == 0){
                aux = meio2/2;
                a->inserirABB(a->raiz, v[fim-aux], 'A');
                if(v[fim-aux-1] != 0 && v[fim-aux+1] != 0){
                    a->inserirABB(a->raiz, v[fim-aux-1], 'A');
                    a->inserirABB(a->raiz, v[fim-aux+1], 'A');
                } 
            }else{
                int aux2 = meio2/2;
                a->inserirABB(a->raiz, v[fim-aux2], 'A');
                if(v[fim-aux2+1] != 0 && v[fim-aux-1] != 0){
                    a->inserirABB(a->raiz, v[fim-aux2-1], 'A');
                    a->inserirABB(a->raiz, v[fim-aux2+1], 'A');
                }
            }                
        } else{
            a->inserirABB(a->raiz, v[fim], 'A');
        }
        meio2 /= 2;
    }
     
    return a; // retorna a arvore
}

void ArvoreBinaria::Teste(int chave) {
    lista2->inserir(chave);
}

bool ArvoreBinaria::existe(int chave) {
    Node *aux = lista2->noCabeca()->getprox();
    while(aux != NULL){
        if(aux->getchave() == chave){
            return true;
        }
        aux = aux->getprox();
    }
    
    return false;
}

/*
 Método removeADD 
 */
void ArvoreBinaria::removeABB(No* raiz, int chave) {
    if(isemptyleft() && isemptyright()){// Verifica se a arvore é vazia
        cout << "\nArvore empty\n";
    }else if(existe(chave) == false){
        cout << "\n Chave nao encontrada!\n";
    }else if(chave < raiz->getchave()){ // verifica se a chave é monor que a raiz
        raiz = raiz->getleft(); // 'anda' para esquerda
        removeABB(raiz, chave);
    }else if(chave > raiz->getchave()){ // verifica se a chave é maior que a raiz
        raiz = raiz->getright(); // 'anda' para direita
        removeABB(raiz, chave);
    }else {
            if(raiz->getleft() != NULL && raiz->getright() != NULL){ // verifica se a raiz tem filho a esquerda e a direita
                No *aux = buscaMin(raiz->getright(), chave); // Retorna nó sucessor a chave passada por parametro 
                raiz->setchave(aux->getchave()); // a raiz seta a chave do nó sucessor
                No *pai = raiz; // nó auxiliar que recebe a raiz
                pai = pai->getright(); // o nó 'anda' para direita
                if(pai->getleft() != NULL){ // verifica se tem filho a esquerda
                    raiz->setright(pai); // se tem adiciona na raiz o filho direita do nó 'pai' 
                    if(raiz->getchave() == pai->getleft()->getchave()){ // verifica se a raiz com a chave trocada é igual a do filho a esquerda do nó 'pai' 
                        No *teste = pai; // nó auxiliar teste recebe o  nó 'pai'
                        teste = teste->getleft(); // nó teste 'anda' para esquerda
                        pai->setleft(teste->getleft()); // e nó pai 'anda' adiciona o nó teste a esquerda
                    }else{// Caso contrario
                        No *teste = pai->getright(); // recebe o nó pai a direita  
                        teste = teste->getright(); // e nó teste 'anda' para direita
                        pai->setright(teste->getright()); // e nó pai adiciona a sua direita
                    }
                }else { // Caso contrario a raiz adiciona o filho a direita do nó auxiliar 'pai'
                    raiz->setright(pai->getright());
                }
                 tamanho--;// decrementa o tamanho da raiz
            }else {// Caso contrario quando a raiz só tem um filho esquerda ou direita
                tamanho--; // decrementa o tamanho da raiz
                No *teste = raiz; // nó recebe a raiz
                if(raiz->getleft() != NULL){ // verifico se a raiz tem filho a esquerda
                    teste = teste->getleft(); // 'ando' para esquerda
                    raiz->setchave(teste->getchave()); // adiciona a chave do nó esquerdo
                    raiz->setleft(teste->getleft()); // e adiciona o filho na esquerdo o nó esquerdo do nó 'teste' 
                }else if(raiz->getright() != NULL){ // senao se a raiz tem o filho direito
                    teste = teste->getright(); // nó 'anda' para direita
                    raiz->setchave(teste->getchave()); // adiciona a chave do nó teste
                    raiz->setright(teste->getright()); // e adiciona o filho na direita o nó direito do nó 'teste'
                }else{ // caso a chave seja folha
                    No *pai = buscafather(this->raiz, chave); // faço a busco pelo pai da folha
                    if(pai->getright()->getchave() == raiz->getchave()){ // verifico se o filho a direita da chave do pai é igual a chave da raiz
                        pai->setright(raiz->getright()); // o pai adiciona o filho da direita da raiz a direita
                    }else if(pai->getleft()->getchave() == raiz->getchave()){// caso contrario, verifico se o filho a esquerda da chave do pai é igual a chave da raiz
                        pai->setleft(raiz->getleft()); // o pai adiciona o filho da esquerda da raiz a esquerda
                    }
                }
            }
    } 
    
      
}
 
/*
 Método da buscaABB
 */

int ArvoreBinaria::buscaABB(No* raiz, int chave) {
    int f;
    
    if(isemptyleft() && chave < raiz->getchave()){ // verifica se a raiz da arvore a esquerda está vazia e se a chave é menor que a raiz da arvore
        return 0; // retorno é 0
    }if(isemptyright() && chave > raiz->getchave()){// verifica se a raiz da arvore a direita está vazia e se a chave é maior que a raiz da arvore
        return 1; // retorno é 1
    }else if(chave == raiz->getchave()){ // verifica se a raiz é igual a chave
        return -1; // retorno é -1
    }else if(chave < getraiz()->getchave()){// verifica se a raiz da arvore é maior que a chave
        if(raiz == NULL){ // se a raiz é vazia
            return 3; // retorna 3
        }else if(chave > raiz->getchave()){ // verifica se a chave é maior que a raiz
            raiz = raiz->getright(); // 'anda' para direita 
            f = buscaABB(raiz, chave); // e chama a funcao recursivamente
        }else if(chave < raiz->getchave()){ // verifica se a chave é menor que raiz
            raiz = raiz->getleft(); // 'anda' para esquerda
            f = buscaABB(raiz, chave); // e chama a funcao recursivamente
        }
    }else if(chave > getraiz()->getchave()){// verifica se a raiz da arvore é menor que a chave
        if(raiz == NULL){// se a raiz é vazia
            return 2;// retorna 2
        }else if(chave > raiz->getchave()){// verifica se a chave é maior que a raiz
            raiz = raiz->getright();// 'anda' para direita 
            f = buscaABB(raiz, chave);// e chama a funcao recursivamente
        }else if(chave < raiz->getchave()){// verifica se a chave é menor que raiz
            raiz = raiz->getleft();// 'anda' para esquerda
            f = buscaABB(raiz, chave);// e chama a funcao recursivamente
        }
    }
    
    return f;
}
/*
 Método que retorna a raiz da arvore
 */
No* ArvoreBinaria::getraiz() {
    return this->raiz;
}

/*
 Método de inserçãoABB 
 */
bool ArvoreBinaria::inserirABB(No* raiz, int chave, char info) {
    int f;
    No *novo = new No();// A criação de um nó
    f = buscaABB(raiz, chave); // faz a busca pela chave e retorna um valor inteiro
    novo->setchave(chave); // seta a chave no nó novo
    novo->setinfo(info);// seta a informação no nó novo
    // verifica se a raiz da arvore a esquerda está vazia
    Teste(chave);
    if(f == 0){
        raiz->setleft(novo); // adiciona o filho a esquerda
        tamanho++; // incrementa o tamanho
    }else if(f == 1){ // verifica se a raiz da arvore a direita está vazia
        raiz->setright(novo); // adiciona o filho a direita
        tamanho++; // incrementa o tamanho
    }else if(f == 3){ // verifica se o retorna é para adiciona o filho a esquerda
        No *aux = buscafather(raiz, chave); // nó 'aux' retorna o pai da chave
        if(aux->getchave() < chave){ // verifico se o pai é menor que a chave
            aux->setright(novo); // o pai adiciona o filho a sua direita
        }else if(aux->getchave() > chave){// verifico se o pai é maior que a chave
            aux->setleft(novo);// o pai adiciona o filho a sua esquerda
        }
        tamanho++;// incrementa o tamanho
    }else if(f == 2){// verifica se o retorna é para adiciona o filho a direita
        No *aux = buscafather(raiz, chave); // nó 'aux' retorna o pai da chave 
        if(aux->getchave() < chave){ // verifico se o pai é menor que a chave
            aux->setright(novo); // o pai adiciona o filho a sua direita
        }else if(aux->getchave() > chave){ // verifico se o pai é maior que a chave
            aux->setleft(novo); // o pai adiciona o filho a sua esquerda
        }
        tamanho++; // incrementa o tamanho
    }else if(f == -1){ // caso a chave já esteja adicionada retorna false
        return false;
    }
    return true; // se todo deu certo retorna true
}
 




