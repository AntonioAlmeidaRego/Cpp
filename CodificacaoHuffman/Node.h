/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Node.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 07:31
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;
/*
 Classe Node.h
 */
class Node {
    /*
     Métodos e atributos publicos
     */
public:
    Node(); // construtor
    Node(const Node& orig);
    virtual ~Node();
    int getfreq(); // retorna a frequencia
    Node * getleft(); // retorna o filho a esquerda
    Node * getright(); // retorna o filho a direita
    wchar_t getinfo(); // retorna o caractere
    void setfreq(int fre); // passa a nova frequencia
    void setleft(Node *left); // passa o novo filho a esquerda
    void setright(Node *right); // passa o novo filho a direita
    void setinfo(wchar_t info); // passa o novo caractere
    void setid(int id); // passa o novo id
    int getid(); // retorna o id
    Node * getraiz(); // retorna a raiz;
    void setraiz(Node *n); // passa a nova raiz
private:
    Node *left; // nó filho a esquerda 
    Node *right; // nó filho a direita
    Node *raiz; // nó raiz
    int freq; // frequencia
    wchar_t info; // caractere
    int id; // id
};

#endif /* NODE_H */

