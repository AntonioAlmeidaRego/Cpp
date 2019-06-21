/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonioalmeida
 *
 * Created on 13 de Junho de 2019, 12:12
 */

#include <iostream>
#include "GraphAL.h"
using namespace std;

/*
 * 
 */

void definaTamanhoVetor(){
    cout << "\n\n\t\tInforme o tamanho do vetor da estrutura do grafo." << endl << endl;
}

int main(int argc, char** argv) {
      GraphAL *grafo = nullptr;
    int opcao;
    int n;
    definaTamanhoVetor();
    cin >> n;
    grafo = new GraphAL(n);
    do{
        cout << "\t1. GetNVertices: Retorna o número de vértices do grafo." << endl;
        cout << "\t2. InsertEdge: Insere a aresta (u, v) na estrutura do grafo." << endl;
        cout << "\t3. HasEdge: Verifica se existe aresta (u, v)." << endl;
        cout << "\t4. IsDirected: Verifica se a aresta (u, v) é uma aresta direcionada." << endl;
        cout << "\t5. IsEdgeValued: Verifica se a aresta (u, v) é valorada." << endl;
        cout << "\t6  GetEdgeValue: Retorna o valor da aresta (u, v)." << endl;
        cout << "\t7  GetNEdges: Retorna o número de arestas do grafo." << endl;
        cout << "\t8  RemoveEdge: remove a aresta (u, v) da estrutura do grafo." << endl;
        cout << "\t9  GetAdjacencyVertex: Retorna todos os vértices adjacentes ao vértice v." << endl;
        cout << "\t10 GetIncidentEdges: Retorna todas as arestas que incidem no vértice v." << endl;
        cout << "\t11 SetVertexLabel: Define um rótulo para o vértice v." << endl;
        cout << "\t12 GetVertexLabel: Retorna o rótulo para o vértice v." << endl;
        cout << "\t13 PrintGraph: Imprime a estrutura do grafo." << endl;
        cout << "\0. Saí" << endl;
        cout << "\nOpcao: \n";
        cin >> opcao;
        system("cls || clear"); // limpa a tela
    switch(opcao)
    {
            case 1:
                cout << "\n\nTotal de Vertices: " << grafo->GetNVertices() << " \n\n";
                break;

            case 2:
                int u, v, custo;
                char r, r2;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v;
                cout << "\n\n\n\tAresta é valorada ? ( S / N ): ";
                cin >> r;
                if(r == 's' || r == 'S'){
                    cout << "\n\n\n\tInforme o custo da aresta: ";
                    cin >> custo;
                } else{
                    custo = 0;
                }
                cout << "\n\n\n\tAresta é direcionada ? ( S / N ): ";
                cin >> r2;
                if(r2 == 's' || r == 'S'){
                    grafo->InsertEdge(u, v, true, custo);
                }else {
                    grafo->InsertEdge(u, v, false, custo);   
                }
                
            break;

            case 3:
                int u1, v1;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u1;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v1;
                if(grafo->HasEdge(u1, v1))
                    cout << "\n\n\n\tExiste uma aresta! " << endl << endl;
                else
                    cout << "\n\n\n\tNão existe uma aresta! " << endl << endl;
            break;
            
            case 4:
                int u2, v2;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u2;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v2;
                if(grafo->IsDirected(u2, v2))
                    cout << "\nAresta é direcionada!" << endl;
                else
                    cout << "\nAresta não é direcionada!" << endl;
            break;

            case 5:
                int u3, v3;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u3;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v3;
                if(grafo->IsEdgeValued(u3, v3))
                    cout << "\nAresta é valorada! " << endl;
                else
                    cout << "\nAresta não é valorada! " << endl;
            break;
            case 6:
                int u4, v4;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u4;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v4;
                cout << "\nO valor da aresta: " << grafo->GetEdgeValue(u4, v4) << endl;
            break;
            case 7:
                cout << "\nO numero de arestas: " << grafo->GetNEdges() << endl;
            break;
            case 8:
                int u5, v5;
                cout << "\n\n\n\tInforme o vertice U: ";
                cin >> u5;
                cout << "\n\n\n\tInforme o vertice V: ";
                cin >> v5;
                grafo->RemoveEdge(u5, v5);
            break;
            case 9:
                int v6;
                cout << "\n\n\n\tInforme o vertice: ";
                cin >> v6;
                grafo->GetAdjacencyVertex(v6)[0].print();
                cout << endl;
            break;

            case 10:
                int v7;
                cout << "\n\n\n\tInforme o vertice: ";
                cin >> v7;
                grafo->GetIncidentEdges(v7)[0].print();
                cout << endl;
            break;
            case 11:
                int v8;
                cout << "\n\n\n\tInforme o vertice: ";
                cin >> v8;
                grafo->SetVertexLabel(v8);
            break;
            case 12:
                int v9;
                cout << "\n\n\n\tInfor o vertice: ";
                cin >> v9;
                cout << "\n\n\tLabel do vertice " << v9 <<" "<< grafo->GetVertexLabel(v9) << endl;
            break;

            case 13:
               grafo->PrintGraph();
               cout << endl;
            break;
            default:
                if(opcao != 0){
                     cout << "\n\n\tOpicao inválida!" << endl;
                }
                break;
        }
    } while(opcao);
   
    return 0;
}
 
