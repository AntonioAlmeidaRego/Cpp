/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphAL.h
 * Author: antonioalmeida
 *
 * Created on 13 de Junho de 2019, 12:13
 */

#ifndef GRAPHAL_H
#define GRAPHAL_H

#include "ListaAdjacente.h"
using namespace std;
/* Classe GraphAL.h */
class GraphAL {
public:
    // Construtor recebe o tamanho do vetor da lista
    GraphAL(int n);
    GraphAL(const GraphAL& orig);
    virtual ~GraphAL();
    // Método que retorna o número de vertices
    int GetNVertices();
    // Método que faz a inserção no grafo
    void InsertEdge(int verticeU, int verticeV, bool dir, int custo);
    // Método que verifica se existe aresta nos vertices
    bool HasEdge(int verticeU, int verticeV);
    // Método que verifica se aresta é direcional
    bool IsDirected(int verticeU, int verticeV);
    // Método que verifica se aresta é valorada (maior que 0)
    bool IsEdgeValued(int verticeU, int verticeV);
    // Método que retorna o valor da aresta
    int GetEdgeValue(int verticeU, int verticeV);
    // Método que retorna o número de arestas
    int GetNEdges();
    // Método que remove aresta do grafo
    void RemoveEdge(int verticeU, int verticeV);
    // Método que retorna uma lista de vertices adjacentes ao vertice passado por parametro
    ListaAdjacente * GetAdjacencyVertex(int v);
    // Método que retorna uma lista de aresta que incidem ao vertice passado por parametro
    ListaAdjacente * GetIncidentEdges(int v);
    // Método que seta a label ao vertice passado por parametro
    void SetVertexLabel(int v);
    // Método que retorna a label ao vertice passado por parametro
    string GetVertexLabel(int v);
    // Método que exibe a estrutura dos vertices do grafo
    void PrintGraph();
private:
    // Atributos privados
    // Uma lista
    ListaAdjacente *graphAL;
    // Método privado que retorna a posicao do vertice
    int getPosicao(int vertice);
    // Método privado que verifica se existe o vertice
    bool isexist(NodeAdjacente *n, int vertice);
    // Método privado que retorna o nó 
    NodeAdjacente * isexistNo(NodeAdjacente *n, int vertice);
    // variavel auxiliar
    int aux = 0;
    // números de vertices no grafo
    int getNVertices = 0;
    // números de arestas no grafo
    int nEdeges = 1;
};

#endif /* GRAPHAL_H */

