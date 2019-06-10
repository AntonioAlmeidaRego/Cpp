/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonio
 *
 * Created on 20 de Abril de 2019, 19:46
 */

#include <iostream>
#include "Percurso.h"
#include "TreeAVL.h"
using namespace std;

/*
 * 
 */



int main(int argc, char** argv) {
    Percurso per;
    bool h = false;
    NodeAVL *no = new NodeAVL;
    no->setchave(4);
    TreeAVL *avl = new TreeAVL;
//    avl->inserirAVL(5, no, h);
//    avl->inserirAVL(7, no, h);
//    avl->inserirAVL(2, no, h);
//    avl->inserirAVL(1, no, h);
//    avl->inserirAVL(3, no, h);
//    avl->inserirAVL(6, no, h);
//    avl->inserirAVL(9, no, h);
//    avl->inserirAVL(8, no, h);
//    avl->inserirAVL(10, no, h);
//    avl->inserirAVL(11, no, h);
//    avl->inserirAVL(12, no, h);
//    avl->inserirAVL(13, no, h);
//    avl->inserirAVL(14, no, h);
//    avl->inserirAVL(15, no, h);
//    avl->inserirAVL(16, no, h);
//    avl->inserirAVL(17, no, h);
//    avl->inserirAVL(18, no, h);
//    avl->inserirAVL(19, no, h);
//    avl->inserirAVL(20, no, h);
//    avl->inserirAVL(21, no, h);
    
    avl->inserirAVL(5, no, h);
    avl->inserirAVL(7, no, h);
    avl->deleteAVL(5, no);
    avl->inserirAVL(3, no, h);
    avl->inserirAVL(2, no, h);
    avl->inserirAVL(1, no, h);
    avl->inserirAVL(6, no, h);
    avl->deleteAVL(7, no); 
    avl->inserirAVL(8, no, h);
    avl->inserirAVL(9, no, h);
    avl->inserirAVL(11, no, h);
    avl->deleteAVL(8, no);
    avl->inserirAVL(12, no, h);
    avl->inserirAVL(14, no, h);
    avl->inserirAVL(17, no, h);
    avl->deleteAVL(12, no);
    per.preordem(no);
    return 0;
}

