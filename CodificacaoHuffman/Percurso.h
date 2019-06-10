/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Percurso.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 14:11
 */

#ifndef PERCURSO_H
#define PERCURSO_H
#include <iostream>
#include <string>
#include "Node.h"
#include "Ascii.h"
#include "Stack.h"
#include "Arquivo.h"
using namespace std;
/*
 Classe Percurso.h
 */
class Percurso {
    /*
     Métodos e atributos publicos
     */
public:
    Percurso(); // construtor
    Percurso(const Percurso& orig);
    virtual ~Percurso();
    void visitor(Node *n); // método de teste
    void posordem(Node *n, Node *raiz); // método de pos-ordem que é um dos percurso da arvore binaria
    void criartabela(); // método que cria a tabela
    string gettabela(wchar_t info); // método que retorna a tabela
    
     /*
     Métodos e atributos publicos
     */
private:
    Stack * pilha; // pilha para adiciona os binarios
    Stack * ascii; // pilha auxiliar
    Stack * codigo; // pilha auxliar
    //string linha; 
    bool nofolha(Node *n); // método privado para verificar se o nó da sub-arvore é folha
    void tabela(wchar_t info); // método privado auxiliar
};

#endif /* PERCURSO_H */

