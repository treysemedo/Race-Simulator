/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipa.h
 * Author: treys
 *
 * Created on 25 de Dezembro de 2019, 7:36
 */
#ifndef EQUIPA_H
#define EQUIPA_H
#include "Piloto.h"
#include <iostream>
using namespace std;

class Equipa {
    Carro *carro;
    int posicao;
    int lugar;
    int pontuacao;
public:
    Equipa(Carro *c);
    Equipa(const Equipa& orig)=delete;
    virtual ~Equipa();
    
    //sets
    void setPosicao(int pos);
    void setLugar(int lug);
    void setPontuacao(int p);
    
    //funçoes controlo
    void chegaMeta(int dimensaoPista);
    void simula(int dimensaoPista, int segundoC, int numUltimo);
    
    //gets
    int getPos()const;
    int getPontuacao()const;
    int getLugar()const;
    Carro* getCarro()const;
    Piloto* getPiloto()const;
    string getAsString()const;
    
    
    //operadores
    
    bool operator>(const Equipa& orig)const;

};

#endif /* EQUIPA_H */

