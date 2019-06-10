/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TreeAVL.h
 * Author: antonio
 *
 * Created on 20 de Abril de 2019, 19:52
 */

#ifndef TREEAVL_H
#define TREEAVL_H

#include "NodeAVL.h"

/*Classe TreeAVL.h*/
/*Classe responsavel por inserir, remover e buscar os nós na arvore AVL*/
class TreeAVL {
public:
    TreeAVL();//construtor
    TreeAVL(const TreeAVL& orig);
    void inserirAVL(int chave, NodeAVL *&n, bool &h);//método que faz a inserção na AVL
    void deleteAVL(int chave, NodeAVL *&n); // método que faz a remoção na AVL
    void busca(NodeAVL *raiz, int chave); // método que faz a busca na AVL
    NodeAVL * getraiz(); // retorna a raiz atual da arvore AVL
    virtual ~TreeAVL();
private:
    void balanceL(NodeAVL *&pA, bool &h); // método que faz o balanceamento a esquerda
    void DelMin(NodeAVL *&q, NodeAVL *&r, bool &h); // método que faz a busca pela chave mais próxima do nó a ser removido
    void balanceR(NodeAVL *&pA, bool &h); // método que faz o balanceamento a direita
    void searchinsert(int chave, NodeAVL *&n, bool &h, NodeAVL *raiz); // método que faz a busca e insere na AVL
    NodeAVL *buscafather(NodeAVL *raiz, int chave); // método auxiliar para retorna o pai da chave
    void setraiz(NodeAVL *raiz); // seta a raiz
    void Delete(int x, NodeAVL *&p, bool &h, NodeAVL *raiz); // método que faz a remoção da AVL
    bool isfolha(NodeAVL *n); // verifica se o nó é folha
    NodeAVL *raiz; // raiz
};

#endif /* TREEAVL_H */

