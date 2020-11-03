/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carro.cpp
 * Author: treys
 * 
 * Created on 24 de Dezembro de 2019, 15:05
 */

#include "Carro.h"
#include "Piloto.h"

char Carro::contaId ='a';

Carro::Carro(string mrc , double enrg,  double maxE, int velM, string mod)
:marca(mrc), energia(enrg),modelo(mod), maxEnergia(maxE), velocidadeMax(velM), id(contaId){
    if((contaId)>'z')
        contaId='?';
    else 
        contaId++;
        
    parado=true;
    velocidade=0;
    emergencia=false;
    danificado=false;
    ocupado=false;
    piloto=nullptr; 
};

Carro::Carro(const Carro& orig)
:marca(orig.marca), energia(orig.energia),modelo(orig.modelo), maxEnergia(orig.maxEnergia), velocidadeMax(orig.velocidadeMax), id(orig.id)  {
   
    parado=true;
    velocidade=0;
    emergencia=false;
    danificado=false;
    ocupado=false;
    piloto=nullptr;
}

void Carro::carregaBateria(double n){ 
    if((energia+n<=maxEnergia)&& parado && !danificado){
        energia +=n;
    }else if((energia+n>maxEnergia)&& parado && !danificado)
        energia=maxEnergia;
}

void Carro::acelera(){   
    if ((velocidade<velocidadeMax)&&velocidade!=0&&!danificado&& ocupado&&energia>0)
        velocidade++;
    else if(velocidade==0 && !danificado && ocupado&&energia>0 ){
        velocidade++;
        parado=false;
    }   
}

void Carro::trava(){
    if (velocidade>1 && !danificado && ocupado)
        velocidade--;
    else if(velocidade==1 && !danificado&& ocupado){
        velocidade--;
        parado=true;
    }
}

void Carro::ligaEmergencia(){
    if(ocupado)
        emergencia=true;
       
}

void Carro::desligaEmergencia(){
    emergencia=false;
}

void Carro::acidente(){
    if(ocupado&&!danificado){
        piloto->acidentado();
        danificado=true;
        velocidade=0;
        parado=true;
        energia=0;
    }
}

Carro* Carro::setPiloto(Piloto *p){
    if(!ocupado&&parado&&!danificado&&p!=nullptr){
        piloto=p;
        ocupado=true;
        return this;
    }
    ocupado=false;
    piloto=nullptr;
    return nullptr;
}

void Carro::setEnergia(double e){
    if(parado && e>=0 && e<=maxEnergia)
        energia=e;
}

void Carro::simula(){
    if(ocupado&&!(parado)&&!(danificado)){
        if(0.1*velocidade<=energia)
        {
            energia-=0.1*velocidade;  
        }else{
            energia=0;
            velocidade--;
            
            if(velocidade==0)
            parado=true;
        }
    }
}

void Carro::chegaMeta(int distancia){
    energia-=distancia*0.1;
    velocidade=0;
    parado=true;
}

char Carro::getId()const{
    return id; 
}

Piloto* Carro::getPiloto()const{
    if(ocupado)
    return piloto;
    return nullptr;
}
bool Carro::getOcupado()const{
    if(ocupado)
        return  true;
    return false;
}

bool Carro::getParado()const{
    return parado;
}

bool Carro::getDanificado()const{
    return danificado;
}

bool Carro::getEmergencia() const
{
	return emergencia;
}

int Carro::getVelocidade()const{
    return velocidade;
}

int Carro::getMaxVelocidade()const{
    return velocidadeMax;
}

double Carro::getEnergia()const{
    return energia;
}
double Carro::getMaxEnergia()const{
    return maxEnergia;
  
}
string Carro:: getAsString()const{
    ostringstream os;
    
    if(ocupado){
        os<<"\t\tmarca "<<marca<<" modelo "<<modelo<<" id "<<id<<" energia "<<energia<<" velocidade "<<velocidade<<" piloto "<< piloto->getNome();
    }else{
                    os << "\t\tmarca " << marca << " modelo " << modelo << " id " << id << " energia " << energia << " velocidade " << velocidade ;
    }
    return os.str();
}

