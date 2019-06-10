/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Labirinto.h
 * Author: robso
 *
 * Created on 25 de Julho de 2018, 10:24
 */
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <locale.h>
#include <time.h>
#include<stdio.h>

#define azul printf("\e[34m")
#define vermelho printf("\e[31m")
#define preto printf("\e[30m")
#define branco printf("\e[47m")


#include "Pilha.h"
#include "Fila.h"
#include "Celula.h"
using namespace std;
const char EXIT_MARKER = 'S';
const char ENTRY_MARKER = 'E';
const char VISITED = '.';
const char VISITED2 = '*';
const char PASSAGE = '0';
const char WALL = '1';

#ifndef LABIRINTO_H
#define LABIRINTO_H

class Labirinto {
public:
    int **Anotar(int **L, Fila F);
    void Extrair(int **L, int l_saida, int c_saida, Pilha p);
    int POSSIBILIDADES(int **m, int l, int c, Pilha *PILHAP);
    void COMECAR(int **m, int l2, int c2);
    void PREENCHERM(int **m, char* argv[]);
    void EXIBEM(int **m, int l2, int c2);
    void DESALOCAM(int ** m, int l2, int c2);
    int **ALOCACAOM(int l2, int c2);
    bool CARACTERES(int **m, int l2, int c2);
    bool VERIFICAR_ENTRADA(int **m, int l2, int c2);
private:

};

bool Labirinto::VERIFICAR_ENTRADA(int **m, int l2, int c2){
    for(int l = 0; l < l2; l++)
        for(int c = 0; c < c2; c++)
            if(m[l][c] == ENTRY_MARKER)
                return true;


    return false;
}

bool Labirinto::CARACTERES(int **m, int l2, int c2){
    bool PERMITIDOS = true;

    for(int l = 0; l < l2; l++)
        for(int c = 0; c < c2; c++)
            if( !(m[l][c] == EXIT_MARKER || m[l][c] == ENTRY_MARKER || m[l][c] == WALL || m[l][c] == PASSAGE) )
                PERMITIDOS = false;


    return PERMITIDOS;
}


int Labirinto::POSSIBILIDADES(int **m, int l, int c, Pilha *PILHAP){
    int NUMEROP = 0;

    if(m[l+1][c] == PASSAGE || m[l+1][c] == EXIT_MARKER){  //MOVIMENTAÇÃO SUPERIOR
        PILHAP->empurrar(l+1, c);
        NUMEROP++;

    }if(m[l-1][c] == PASSAGE || m[l-1][c] == EXIT_MARKER){ //MOVIMENTAÇÃO INFERIOR
        PILHAP->empurrar(l-1, c);
        NUMEROP++;

    }if(m[l][c-1] == PASSAGE || m[l][c-1] == EXIT_MARKER){ //MOVIMENTAÇÃO LATERAL ESQUERDA
        PILHAP->empurrar(l, c-1);
        NUMEROP++;

    }if(m[l][c+1] == PASSAGE || m[l][c+1] == EXIT_MARKER){ //MOVIMENTAÇÃO LATERAL DIREITA
        PILHAP->empurrar(l, c+1);
        NUMEROP++;
    }

    return NUMEROP;
}



void Labirinto::COMECAR(int **m, int l2, int c2){



    Pilha PILHAP;
    int **aux;
    Fila  F;

    for(int l = 0; l < l2; l++){
        for(int c = 0; c < c2; c++){

            if(m[l][c] == EXIT_MARKER){

                        aux = Anotar(m, F);
                        Extrair(aux, l, c, PILHAP);
                        usleep(10000);


                azul;
                cout << "\n\t\t\tO MENOR CAMINHO " << endl;
                usleep(100000);

            }

        }
    }

}

int **Labirinto::Anotar(int **L, Fila F){
    int l_sai = 0;
    int c_sai = 0;
    int c, l;
    int k = 1;
    int l_ent, c_ent;
    l_ent = 1;
    c_ent = 0;
    L[l_ent][c_ent] = 1;
    F.inserirFinal(l_ent, c_ent);
    while(!F.isEmpty()){
        Celula *posicao = F.removerInicio();
        c = posicao->pegaC();
        l = posicao->pegaL();


                            if(L[l+1][c] == PASSAGE || L[l+1][c] == EXIT_MARKER){ //MOVIMENTAÇÃO INFERIOR
                                L[l+1][c] = L[l][c] + 1;
                                F.inserirFinal(l+1, c);
                            }
                            if(L[l][c+1] == PASSAGE || L[l][c+1] == EXIT_MARKER){ //MOVIMENTAÇÃO LATERAL DIREITA
                                L[l][c+1] = L[l][c] + 1;
                                F.inserirFinal(l, c+1);
                            }
                            if(L[l-1][c] == PASSAGE || L[l-1][c] == EXIT_MARKER){ //MOVIMENTAÇÃO SUPERIOR
                                L[l-1][c] = L[l][c] + 1;
                                F.inserirFinal(l-1, c);
                            }
                            if(L[l][c-1] == PASSAGE || L[l][c-1] == EXIT_MARKER){ //MOVIMENTAÇÃO LATERAL ESQUERDA
                                L[l][c-1] = L[l][c] + 1;
                                F.inserirFinal(l, c-1);
                            }

                    system("cls");
                    cout<<"\n--------------FUNCAO ANOTAR---------------\n";
                    EXIBEM(L, 14, 26);

                    usleep(10000);
    }


    system("pause");
    return L;
}

void Labirinto::Extrair(int **L, int l_saida, int c_saida, Pilha p){
    int i, j;
    int **m;


    if(L[l_saida][c_saida] == 0){
        cout<<"\nO LABIRINHTO SEM SAIDA\n";
    }

    p.empurrar(l_saida, c_saida);
    while(!p.VAZIA()){
        Celula *posicao = p.pop();
        i = posicao->pegaL();
        j = posicao->pegaC();

        if((L[i][j] -1) == L[i+1][j]){
            L[i][j] = 0;
            p.empurrar(i+1, j);
        }
        else if((L[i][j] -1) == L[i-1][j]){
            L[i][j] = 0;
            p.empurrar(i-1, j);
        }
        else if((L[i][j] -1) == L[i][j+1]){
            L[i][j] = 0;
            p.empurrar(i, j+1);
        }
        else if((L[i][j] -1) == L[i][j-1]){
            L[i][j] = 0;
            p.empurrar(i, j-1);
        }
        else if(L[i][j] == L[1][0]){
            break;
        }
        system("cls");
        cout<<"\n---------FUNCAO EXTRAIR-----------\n";
        EXIBEM(L, 14, 26);
        cout<<endl;
        usleep(10000);
    }


}




int **Labirinto::ALOCACAOM(int l2, int c2){
    int **m = new int*[l2];
    for(int l = 0; l < l2; l++)
        m[l] = new int[c2];

    return m;
}

void Labirinto::DESALOCAM(int ** m, int l2, int c2){
    for(int l = 0 ; l < l2; l++)
        delete []m[l];

    delete []m;
}

void Labirinto::EXIBEM(int **m, int l2, int c2){ //responsável por exibir o labirinto
 cout << "\n\n";
    for(int l = 0; l < l2; l++){
        cout << "  ";
        for(int c = 0; c < c2; c++)
	{
            if(m[l][c] == WALL)
	     {
               	 azul;               //define a cor da parede para azul, e imprime o caractere '|'
                 cout << "::";
             }

             else if(m[l][c] == PASSAGE)
	     {
                cout << "0"; //zonas de passagem (onde o rato pode passar) recebe o caractere '0'
             }

             else if(m[l][c] == VISITED)
             {
                vermelho;

                cout << "."; //onde o rato vizitar, recebe o caractere '.' e ficará vermelho

             }
	       else if(m[l][c] == VISITED2)
             {
                vermelho;
                cout << "*"; //onde o rato vizitar,troca o caractere  '.' por '*' e ficará branco.
             }
             else if(m[l][c] == ENTRY_MARKER)
	     {
                vermelho;

                cout << "E"; //o ratinho  entra no labirinto, marcado por "M".
             }


 	     else if(m[l][c] == EXIT_MARKER){

	        vermelho;		//o ratinho deve encontrar o "E". A saíd é marcada por 'e' (exit)
                cout << "S";
             }
             else {
                vermelho;
                cout<<m[l][c]<<" ";
             }
              cout << " ";
        }cout << "\n";
    }
}

void Labirinto::PREENCHERM(int **m, char* argv[]){
    int l2, c2;
    char caracter;

    ifstream arquivo(argv[1],ios::in);
    arquivo.open("labirinto.txt");
    char output[100];
    if (arquivo.is_open()) {

    while (!arquivo){
        cout << "O ARQUIVO NÃO PODE SER ENCONTRADO ! CERTIFIQUE-SE QUE VOCÊ DIGIROU O NOME DO ARQUIVO CORRETAMENTE!" << endl;
        exit(1);//MENSAGENS MOSTRADA QUANDO O ARQUIVO NÃO É ENCONTRADO
    }

    arquivo >> l2 >> c2; //O ARQUIVO PASSARÁ OS VALORES DE LINHS E COLUNAS PARA PREENCHER A MATRIZ


    for(int l = 0; l < l2; l++){
        for(int c = 0; c < c2; c++){
            arquivo >> caracter;
            caracter = toupper(caracter);
            m[l][c] = caracter;
        }
    }arquivo.close(); //ARQUIVO FECHADO
}
}

#endif /* LABIRINTO_H */

