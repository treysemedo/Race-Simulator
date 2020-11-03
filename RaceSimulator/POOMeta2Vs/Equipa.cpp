/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipa.cpp
 * Author: treys
 * 
 * Created on 25 de Dezembro de 2019, 7:36
 */

#include "Equipa.h"

Equipa::Equipa(Carro *c):carro(c) {
    posicao=0;
    lugar=0;
    pontuacao=0;
}

Equipa::~Equipa() {
}

void Equipa::setPosicao(int pos){
    posicao = pos;
}

void Equipa::setLugar(int lug){
    lugar = lug;
}

void Equipa::setPontuacao(int p){
    pontuacao = p;
}

void Equipa::chegaMeta(int dimensaoPista){
    carro->chegaMeta(dimensaoPista-posicao);
	carro->getPiloto()->chegaMeta();
    posicao=dimensaoPista; 
}    

void Equipa::simula(int dimensaoPista, int segundoC, int numUltimo){
    carro->getPiloto()->simula(lugar, segundoC, numUltimo);
    carro->simula();
    if((posicao+carro->getVelocidade())>dimensaoPista)
        chegaMeta(dimensaoPista);
    else
        posicao+=carro->getVelocidade();
     
}

int Equipa::getPos()const{
    return posicao;
}

int Equipa::getPontuacao()const{
    return pontuacao;
}

int Equipa::getLugar()const{
    return lugar;
    
    
}
Carro* Equipa::getCarro()const{
    return carro;
}
Piloto* Equipa::getPiloto()const{
    return carro->getPiloto();
}
string Equipa::getAsString()const{
    ostringstream os;
    os<<carro->getAsString()<<" Posicao "<<posicao<<" Lugar "<<lugar<<" Pontuacao: "<< pontuacao;
    return os.str();
    
}

bool Equipa::operator>(const Equipa& orig)const{
    if(posicao>orig.posicao)
        return true;
    if(posicao==orig.posicao && lugar<orig.lugar)
        return true;
    return false;
}



