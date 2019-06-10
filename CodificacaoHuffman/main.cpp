/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 07:28
 */

#include <iostream>
#include "Arquivo.h"
#include "Lista.h"
#include "ListaEncadeada.h"
#include "Percurso.h"
 
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
     Arquivo main.cpp. Em que faço a instanciação do objeto Arquivo que terá 
     seus métodos para abrir, ler, criar o arquivo binario e a tabela de huffman 
     */
    
    Arquivo *arq = new Arquivo("texto.txt"); // O construtor da classe Arquivo recebe o caminho do arquivo
    arq->open(); // abrir o arquivo 'texto.txt'
    arq->read(); // ler o arquivo 'texto.txt'
    arq->creatArquivoBinario("texto-bin.txt"); // cria os binarios nesse arquivo passando por paramêtro
    arq->creatArquivoTabela("tabela-bin.txt"); // cria a tabela de huffman passando por paramêtro
    
    return 0;
}

