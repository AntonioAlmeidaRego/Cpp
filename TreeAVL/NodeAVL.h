/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeAVL.h
 * Author: antonio
 *
 * Created on 20 de Abril de 2019, 19:46
 */

#ifndef NODEAVL_H
#define NODEAVL_H

/* Classe NodeAVL.h*/
/* Classe responsavel por ser a estrutura básica da Arvore AVL com os seguintes atributos (filho esquerdo, filho direito, chave e balanceamento)*/
class NodeAVL {
public:
    NodeAVL();// construtor
    NodeAVL(int chave, int bal); // segundo construtor que recebe uma chave e balaceamento inicial
    NodeAVL(const NodeAVL& orig);
    int getchave(); // retorna a chave
    NodeAVL * getleft();  // retorna o filho esquerdo
    NodeAVL * getright(); // retorna o filho direito
    int getbal(); // retorna o balaceamento da sub-arvore
    void setchave(int chave); // seta a nova chave
    void setleft(NodeAVL * left); // seta o filho esquerdo
    void setright(NodeAVL * right); // seta o filho direito
    void setbal(int bal); // seta o balanceamento
    virtual ~NodeAVL();
    
    NodeAVL *left; // nó esquerdo
    NodeAVL *right; // nó direito
private:
    int chave; // chave
    int bal; // balaceamento
};

#endif /* NODEAVL_H */

