/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphAL.cpp
 * Author: antonioalmeida
 * 
 * Created on 13 de Junho de 2019, 12:13
 */
#include <iostream>
#include <cstring>
#include "GraphAL.h"
using namespace std;
/*Classe GraphAL.cpp */
// Construtor
GraphAL::GraphAL(int n) {//recebe por parametro o tamanho do vetor
    this->getNVertices = n;// o atributo getNVertices recebe o tamanho do vetor, pois é o total de vertices na estrutura do grafo
    this->graphAL = new ListaAdjacente[n];// instancia a lista de vetor, ou seja, cada posição do vetor é uma lista
}

GraphAL::GraphAL(const GraphAL& orig) {
}

GraphAL::~GraphAL() {
}
/*Método que retorna o números de vertices*/
int GraphAL::GetNVertices() {
    return this->getNVertices;
}
/*Método que faz a inserção no grafo*/
void GraphAL::InsertEdge(int verticeU, int verticeV, bool dir, int custo) {
    if(dir){// Se aresta for direcionada
        // Segue o fluxo abaixo
        if(getPosicao(verticeU) == -1){// Se a posicao do verticeU por igual a -1, é por que não existe no vetor esse verticeU
            this->graphAL[aux].add(verticeU, custo, dir, aux);// insere na posicao da variavel aux
            aux++;// incrementa o auxiliar 
            nEdeges++; // incrementa o total de arestas
        }
        if(getPosicao(verticeV) == -1){// Se a posicao do verticeV por igual a -1, é por que não existe no vetor esse verticeV
            this->graphAL[aux].add(verticeV, custo, dir, aux);// insere na posicao da variavel aux
            
        } // Após isso é uma aresta direcional
        this->graphAL[getPosicao(verticeU)].add(verticeV, custo, dir);// Insere o verticeV na posicao do verticeU
    }else{
        if(getPosicao(verticeU) == -1){// Se a posicao do verticeU por igual a -1, é por que não existe no vetor esse verticeU
            this->graphAL[aux].add(verticeU, custo, dir, aux);// insere na posicao da variavel aux
            aux++;// incrementa o auxiliar 
            nEdeges++;// incrementa o total de arestas
        }
        if(getPosicao(verticeV) == -1){// Se a posicao do verticeV por igual a -1, é por que não existe no vetor esse verticeV
            this->graphAL[aux].add(verticeV, custo, dir, aux);// insere na posicao da variavel aux
        } // Após isso é uma aresta não direcionada
        this->graphAL[getPosicao(verticeU)].add(verticeV, custo, dir);// Insere o verticeV na posicao do verticeU
        this->graphAL[getPosicao(verticeV)].add(verticeU, custo, dir);// Insere o verticeU na posicao do verticeV
    }
    nEdeges++;// incrementa o total de arestas
    aux++;// incrementa o auxiliar 
}
/*Método que verifica se existe aresta nos vertices*/
bool GraphAL::HasEdge(int verticeU, int verticeV) {
    // Variaveis auxiliares
    NodeAdjacente *u = nullptr;
    NodeAdjacente *v = nullptr;
 
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeU
        if((graphAL[i].firt()->getvertice() == verticeU)){// Se for igual 
            u = graphAL[i].firt();// recebe o vertice
            break; // e stop no loop
        }
    }
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeV
        if((graphAL[i].firt()->getvertice() == verticeV)){// Se for igual 
            v = graphAL[i].firt();// recebe o vertice
            break;// e stop no loop
        }
    }
    
    if(u == nullptr){// se a variavel auxiliar for null
        return false; // retorna false
    }
    if(v == nullptr){// se a variavel auxiliar for null
        return false;// retorna false
    }
    /* Se o nó v existe o verticeU retorna true ou o nó u existe o verticeU retorna true*/
    if((isexist(v, verticeU)) || (isexist(u, verticeV))){
        return true;
    }
    // Senão false
    return false;
}
 // Método que verifica se aresta é direcional
bool GraphAL::IsDirected(int verticeU, int verticeV) {
    // Variaveis auxiliares
    NodeAdjacente *u = nullptr;
    NodeAdjacente *v = nullptr;
    
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeU
        if((graphAL[i].firt()->getvertice() == verticeU)){// Se for igual 
            u = graphAL[i].firt();// recebe o vertice
            break;// e stop no loop
        }
    }
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeV
        if((graphAL[i].firt()->getvertice() == verticeV)){// Se for igual
            v = graphAL[i].firt();// recebe o vertice
            break;// e stop no loop
        }
    }
    if(u == nullptr){// se a variavel auxiliar for null
        return false;// retorna false
    }
    if(v == nullptr){// se a variavel auxiliar for null
        return false;// retorna false
    }
    /* Se o nó v existe o verticeU retorna true e o nó u existe o verticeU retorna true*/
    if((isexist(v, verticeU)) && (isexist(u, verticeV))){
        // Neste caso retorna false, por que é uma aresta não direcional
        return false;
    }/* Se o nó u existe o verticeV retorna true */
    if((isexist(u, verticeV))){
       return true; 
    }
    
    return false;// senao retorna false
}
// Método privado que verifica se existe o vertice
bool GraphAL::isexist(NodeAdjacente* n, int vertice) {
    NodeAdjacente *aux = n;// variavel auxiliar recebe o nó por parametro
    while(aux != n->getant()){// Enquanto a variavel aux for diferente do nó anterior
        if(aux->getvertice() == vertice){// Se o vertice do nó aux for igual ao vertice do parametro 
            return true;// retorna true
        }// Senão continua o fluxo do percurso da lista
        aux = aux->getprox();
    }
    return false;// Caso não encontrou o vertice retorna false
}
// Método privado que retorna o nó 
NodeAdjacente * GraphAL::isexistNo(NodeAdjacente* n, int vertice) {
    NodeAdjacente *aux = n;// variavel auxiliar recebe o nó por parametro
    while(aux != n->getant()){// Enquanto a variavel aux for diferente do nó anterior
        if(aux->getvertice() == vertice){// Se o vertice do nó aux for igual ao vertice do parametro 
            return aux;// retorna o nó
        }// Senão continua o fluxo do percurso da lista
        aux = aux->getprox();
    }
    return nullptr;// Caso não encontrou o vertice retorna null
}
// Método que verifica se aresta é valorada (maior que 0)
bool GraphAL::IsEdgeValued(int verticeU, int verticeV) {
    if(HasEdge(verticeU, verticeV)){// Se existe aresta nos vertices, segue o fluxo abaixo
        // Variaveis auxiliares
        NodeAdjacente *u = nullptr;
        NodeAdjacente *v = nullptr;
        for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeU
            if((graphAL[i].firt()->getvertice() == verticeU)){// Se for igual 
                u = graphAL[i].firt();// recebe nó
                break;// e stop no loop
            }
        }
        for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeV
            if((graphAL[i].firt()->getvertice() == verticeV)){// Se for igual
                v = graphAL[i].firt();// recebe nó
                break;// e stop no loop
            }
        }
        if(isexistNo(v, verticeU) != nullptr){// Se o nó v tiver o verticeU retorna um nó
            /* Se o nó v tiver o verticeU retorna um nó, e esse nó for maior que 0 retorna true E o nó v for maior que 0 retorna true*/
            if(isexistNo(v, verticeU)->getcusto() > 0 && v->getcusto() > 0){
                return true;// retorno true
            }
        }
        if(isexistNo(u, verticeV) != nullptr){ // Se o nó u tiver o verticeV retorna um nó
            /* Se o nó u tiver o verticeV retorna um nó, e esse nó for maior que 0 retorna true E o nó u for maior que 0 retorna true*/
            if(isexistNo(u, verticeV)->getcusto() > 0 && u->getcusto() > 0){
                return true;// retorno true
            }
        }
    }
    return false;// senão retorna false
}
// Método que retorna o valor da aresta
int GraphAL::GetEdgeValue(int verticeU, int verticeV) {
    if(HasEdge(verticeU, verticeV)){// Se existe aresta nos vertices, segue o fluxo abaixo
        // Variaveis auxiliares
        NodeAdjacente *u = nullptr;
        NodeAdjacente *v = nullptr;
        for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeU
            if((graphAL[i].firt()->getvertice() == verticeU)){// Se for igual 
                u = graphAL[i].firt();// recebe nó
                break;// e stop no loop
            }
        }
        for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo verticeV
            if((graphAL[i].firt()->getvertice() == verticeV)){// Se for igual
                v = graphAL[i].firt();// recebe nó
                break;// e stop no loop
            }
        }
        if(isexistNo(v, verticeU) != nullptr){// Se o nó v tiver o verticeU retorna um nó
            /* Se o nó v tiver o verticeU retorna um nó, e esse nó for maior que 0 retorna true E o nó v for maior que 0 retorna true*/
            if(isexistNo(v, verticeU)->getcusto() > 0 && v->getcusto() > 0){
                return v->getcusto(); // retorna o valor da aresta
            }
        }
        if(isexistNo(u, verticeV) != nullptr){// Se o nó u tiver o verticeV retorna um nó
            /* Se o nó u tiver o verticeV retorna um nó, e esse nó for maior que 0 retorna true E o nó u for maior que 0 retorna true*/
            if(isexistNo(u, verticeV)->getcusto() > 0 && u->getcusto() > 0){
                return u->getcusto(); // retorna o valor da aresta
            }
        }
    }
    return 0;// senão retorna 0
}
// Método que retorna o número de arestas
int GraphAL::GetNEdges() {
    return this->nEdeges;
}
 // Método privado que retorna a posicao do vertice
int GraphAL::getPosicao(int vertice) {
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo vertice
        if(graphAL[i].firt()->getvertice() == vertice){// Se for igual
            return i;// retorna a posicao
        }
    }
    return -1;// senão retorna -1 caso não encontrado
}
// Método que remove aresta do grafo
void GraphAL::RemoveEdge(int verticeU, int verticeV) {
    for(int i = 0;i<this->getNVertices;i++){// Faz uma busca pelo vertice
        if((graphAL[i].searchVertice(verticeU) != nullptr)){// Se existe o verticeU na lista
            nEdeges--;// decrementa o numero de aresta
            NodeAdjacente * u = graphAL[i].searchVertice(verticeU); // recebe o nó da busca
            graphAL[i].remove(u, verticeU);  // remove o vertice da lista
        }else if((graphAL[i].searchVertice(verticeV) != nullptr)){ // Senão se existe verticeV na lista 
            nEdeges--;// decrementa o numero de aresta
            NodeAdjacente * v = graphAL[i].searchVertice(verticeV);// recebe o nó da busca
            graphAL[i].remove(v, verticeV); // remove o vertice da lista
        }
    }
}

// Método que retorna uma lista de vertices adjacentes ao vertice passado por parametro
ListaAdjacente* GraphAL::GetAdjacencyVertex(int v) {
    ListaAdjacente *graf = new ListaAdjacente[this->getNVertices];// cria um lista de vetor
    NodeAdjacente *vertice = nullptr; // uma variavel auxiliar
    
    for(int i = 0; i < this->getNVertices;i++){// Faz uma busca pelo vertice
        if(graphAL[i].firt()->getvertice() == v){// Se for igual
            vertice = graphAL[i].firt();// recebe nó
            break;// e stop no loop
        }
    }
    
    if(vertice != nullptr){// Se a variavel auxiliar for diferente de null
        NodeAdjacente *aux = vertice;// aux recebe vertice
        while((aux != vertice->getant()) && (aux->getvertice() != 0)){// enquanto o aux for diferente do vertice anterior
            // Insere na posicao 0 todos os vertices adjacentes
            graf[0].add(aux->getvertice(), aux->getcusto(), aux->getdir(), aux->getid());
            aux = aux->getprox();// faz o percurso na lista
        }
    }
    
    return graf;// retorna a lista
}
// Método que retorna uma lista de aresta que incidem ao vertice passado por parametro
ListaAdjacente* GraphAL::GetIncidentEdges(int v) {
    ListaAdjacente *graf = new ListaAdjacente[this->getNVertices];// cria um lista de vetor
    
    for(int i = 0; i < this->getNVertices;i++){// Faz uma busca pelo vertice
        if((graphAL[i].searchVertice(v) != nullptr)){// Se existe
            NodeAdjacente *vertice = graphAL[i].firt(); // recebe o primeiro nó da lista
            NodeAdjacente *aux = vertice; // aux recebe o nó vertice
            if(vertice->getvertice() != v){// Se o nó vertice é diferente do vertice passado por parametro
                while(aux != vertice->getant()){// enquanto o aux for diferente do vertice anterior
                    // Se o nó aux é diferente do vertice passado por parametro E seu vertice é diferente de 0
                    if(aux->getvertice() != v && aux->getvertice() != 0){
                        // Insere na posicao 0 todos os vertices incidentes
                        graf[0].add(aux->getvertice(), aux->getcusto(), aux->getdir(), aux->getid());
                    }
                    aux = aux->getprox();// faz o percurso na lista
                }
            }
        }
    }
    return graf;// retorna a lista
}
// Método que seta a label ao vertice passado por parametro
void GraphAL::SetVertexLabel(int v) {
    NodeAdjacente *vertice = nullptr;// uma variavel auxiliar
    for(int i = 0; i < this->getNVertices;i++){// Faz uma busca pelo vertice
        if(graphAL[i].firt()->getvertice() == v){// Se for igual
            vertice = graphAL[i].firt();// recebe nó
            break;// e stop no loop
        }
    }
    string label;
    cout << "\n\n\n\tInforme a label: ";
    cin >> label;
    vertice->setlabel(label);// seta a label no vertice
}
// Método que retorna a label ao vertice passado por parametro
string GraphAL::GetVertexLabel(int v) {
    NodeAdjacente *vertice = nullptr;// uma variavel auxiliar
    for(int i = 0; i < this->getNVertices;i++){// Faz uma busca pelo vertice
        if(graphAL[i].firt()->getvertice() == v){// Se for igual
            vertice = graphAL[i].firt();// recebe nó
            break;// e stop no loop
        }
    }
    return vertice->getlabel();// retorna a label do vertice
}
// Método que exibe a estrutura dos vertices do grafo
void GraphAL::PrintGraph() {
    for(int i = 0;i<this->getNVertices;i++){// Faz o percurso no vetor
        if(graphAL[i].getone(i) != nullptr){// Se o nó existe printa na tela
           cout <<graphAL[i].getone(i)->getlabel()<<"-> "; 
           graphAL[i].print();
           cout << endl;
        }
    }
}


