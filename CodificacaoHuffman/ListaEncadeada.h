/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ListaEncadeada.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 11:10
 */

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "No.h"
#include "Node.h"
/*
 Classe ListaEncadeada.h
 */
class ListaEncadeada {
    /*
    métodos e atributos publicos 
     */
public:
    ListaEncadeada(); // construtor
    ListaEncadeada(const ListaEncadeada& orig);
    virtual ~ListaEncadeada();
    Node * remove(); // método que remove da lista
    Node * get(wchar_t info); // retorna o nó da lista que seja igual ao do paramêtro
    void add(wchar_t info, int freq); // Método que adiciona na lista ordenado
    void add(Node *r); // Método auxiliar para adiciona o objeto nó
    bool empty(); // verifica se a lista está vazia
    int lenght(); // retorna o tamanho da lista
    void print(); // método de teste
    Node * front(); // retorna o primeiro da lista
    
    /*
     métodos e atributos privados
     */
private:
    No * nocabeca; // no cabeca
    No *ant; // no anterior
    No *pont; // no proximo
    int size; // tamanho da lista
    No * busca_anterior(Node *n); // Método privado para retorna o nó anterior
    No * busca_proximo(Node *n); // Método privado para retorna o nó proximo
    bool existeNo(wchar_t info); // verifica se o caractere já existe na lista
};

#endif /* LISTAENCADEADA_H */

