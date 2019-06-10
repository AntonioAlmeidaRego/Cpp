/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: antonio
 *
 * Created on 24 de Março de 2019, 20:38
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    void setProx(Node *p);
    void setChave(int chave);
    Node* getprox();
    int getchave();
    Node(const Node& orig);
    virtual ~Node();
private:
    Node *prox;
    int chave;
};

#endif /* NODE_H */

