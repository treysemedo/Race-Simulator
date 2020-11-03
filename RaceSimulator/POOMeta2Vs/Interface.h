/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface.h
 * Author: treys
 *
 * Created on 24 de Dezembro de 2019, 14:59
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Simulador.h"
#include  "Consola.h"
class Interface {
    
   Simulador* simulador;
   
   int corFundoPrincipal;
   int corTexto;
   
   int corFundoComando;
   int corTextoComando;
   
   int tamanhoTitulo;
   int tamanhoTexto;
   
   int posxTitulo;
   int posyTitulo;
   
   int posxComando;
   int posyComando;
   
   bool modo1;
   
public:
    Interface();
    Interface(const Interface& orig)=delete;
    virtual ~Interface();
    
    
    void telaInicio();
	int visualizador();
	void processaComando();

    void imprimeComando(int posx, int posy);
	int imprimePista(string nome, int tam, int numMaxEquipa, int posx, int posy);
	void imprimeCarro(char id, int posx, int posy);
	void imprimePontuacao(int posx, int posy);
	void imprimeVencedores(string n1, string n2, string n3);

};

#endif /* INTERFACE_H */

