/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Arquivo.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 07:28
 */

#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "ListaEncadeada.h"
#include "Node.h"
#include "Lista.h"
#include "Queue.h"
using namespace std;
/*
 Classe Arquivo.h
 */
class Arquivo {
    /*
    métodos e atributos publicos 
     */
public:
    Arquivo(string nomearquivo); // construtor
    Arquivo(const Arquivo& orig);
    void open(); // método de abrir o arquivo
    void read(); // método de ler o arquivo
    Node * createTree(); // criar a arvore de nós
    string createtable(int posicao); // criar a tabela de huffman, acessando a posicao da tabela
    int totalElements(); // total de elementos (caracteres) no arquivo
    void creatArquivoBinario(string caminho); // cria o arquivo binario pelo caminho do arquivo passado por paramêtro
    void creatArquivoTabela(string caminho); // cria a tabela pelo caminho do arquivo passado por paramêtro
    Queue * getlista(); // retorna a lista de caracteres
    virtual ~Arquivo();
    /*
     métodos e atributos privados
     */
private:
    Queue * lista; // fila para "armazenar os caracteres do arquivo"
    Queue * auxlista; // fila auxilar 
    string linha; // linha que recebe do arquivo de texto cada linha do mesmo
    //string colunachar;
    string nomearquivo;
    int size;
    ifstream arquivo; // atributo que manipula a leitora do arquivo.txt
    ifstream tabela_acii; // atributo que manipula a leitora do arquivo.txt
    ofstream saida_arquivo; // atributo que manipula a saida do arquivo.txt
    ofstream saida_tabela; // atributo que manipula a saida do arquivo.txt
    int i; // atributo auxiliar
    //int j;
    ListaEncadeada * listaend; // lista encadeado de nós da arvore
    string createcolunachar(); // método privado que cria a coluna de caracteres
    string createtablebin(int posicao); // método privado que cria a tabela de huffman
    string createcolunabin(wchar_t info); // método privado que cria a coluna de binario
    string createbin(wchar_t info); // método privado que retorna os binarios do caractere passado por paramêtro
    double percentualCompactacao(int lenghtarquivo, int lenghtarquivocompactado); // método privado

};

#endif /* ARQUIVO_H */

