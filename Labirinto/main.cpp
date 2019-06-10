/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: robso
 *
 * Created on 25 de Julho de 2018, 09:52
 */
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <time.h>
#include <fstream>
#include<stdio.h>

#include <stddef.h>

#include "Labirinto.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    int l2;
    int c2;
    int **m;
    Labirinto l;

    ifstream arquivo(argv[1],ios::in);    // RESPONSÁVEL POR ABRIR O LABRINTO
    arquivo.open("labirinto.txt");



    if (!arquivo)//CASO O O ARUIVO TENHA SIDO INFORMADO DE FORMA ERRADA
	{
        	cout << "IMPOSSÍVEL ABRIR! ARQUIVO INEXISTENTE OU INFORMADO DE FORMA ERRADA!" << endl;
       		 exit(1);
    	}

    		arquivo >> l2 >> c2; //LÊ AS DIMENSÕES PARA PODER MONTAR O LABIRINTO
    		arquivo.close();

   		 m = l.ALOCACAOM(l2, c2);
		    l.PREENCHERM(m, argv);  //PREENCHIMENTO

    if(!l.CARACTERES(m, l2, c2))
	{
       	 cout << "ALGUNS CARACTERES ENCONTRADOS NO ARQUIVO NÃO SÃO RECONHECIDOS POR ESSE PROGRAMA. OS PERMITIDOS SÃO: 0,1,E,S APENAS." << endl;
        	exit(1); //CASO OS CARACTERES INFORMADOS NÃO POSSAM SER LIDOS
	}

    if(!l.VERIFICAR_ENTRADA(m, l2, c2))
	{
  	      cout << "LABIRINTO SEM ENTRADA (E)" << endl;
        	exit(1);
        }

   		 l.COMECAR(m, l2, c2); //INICIA O LABIRINTO E O ALOCA
    		l.DESALOCAM(m, l2, c2);//DELETA O LABIRINTO

    return 0;
}

