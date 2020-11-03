/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: treys
 *
 * Created on 24 de Dezembro de 2019, 14:55
 */

#include <cstdlib>
#include <iostream>
#include "Interface.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Interface ui;
    ui.telaInicio();
	ui.processaComando();
	
   return 0;
}

