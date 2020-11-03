/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGV.cpp
 * Author: treys
 * 
 * Created on 25 de Dezembro de 2019, 6:30
 */

#include "DGV.h"


DGV::DGV(string name):nome(name) {
}

DGV::DGV( DGV & orig)
{
	vector <Carro*> carroAux=orig.getCarro();
	vector <Piloto*> pilotoAux=orig.getPiloto();
	carro.clear();
	piloto.clear();
	for (Carro *a : carroAux)
		carro.push_back(new Carro(*a));
	for (Piloto *a : pilotoAux)
		piloto.push_back(new Piloto(*a));
}


DGV::~DGV() {
    for(Piloto *a:piloto)
        delete a;
    
     for(Carro *a:carro)
        delete a; 
}


void DGV::addCarro(  string mrc , double enrg,  double maxE, int velM, string mod){
    carro.push_back(new Carro(mrc, enrg, maxE, velM, mod));
}

void DGV::addCarro(  string mrc , double enrg,  double maxE, int velM){
    carro.push_back(new Carro(mrc, enrg, maxE, velM));
}

void DGV::addPiloto(string nm, string tipo){
	//lista com nome pilotos para o construtor do piloto verficar se nome ja existe
    vector <string> pilotos;
    int i=0;
    for(auto it=piloto.begin() ;it<piloto.end();it++, i++){
        pilotos.push_back((*it)->getNome());
    }
	if(tipo=="rapido")
		piloto.push_back(new Piloto(nm, pilotos));
	else if (tipo == "crazydriver")
		piloto.push_back(new CrazyDriver(nm, pilotos));
	else if (tipo == "surpresa")
		piloto.push_back(new Piloto(nm, pilotos));

}


void DGV::acrescentaPiloto(Piloto* a){
    piloto.push_back(a);
}
 void DGV::acrescentaCarro(Carro* a){
     carro.push_back(a);   
 }

 vector<Carro*> DGV::getCarro()
 {
	 return carro;
 }

 vector<Piloto*> DGV::getPiloto()
 {
	 return piloto;
 }



void DGV::entraNoCarro(char idCar, string nomePil){
   
    for(auto itP=piloto.begin();itP<piloto.end();itP++){
        if(((*itP)->getNome())==nomePil){
            for(auto itC=carro.begin();itC<carro.end();itC++){
                if((*itC)->getId()==idCar){
                    (*itP)->entraCarro(*itC);

                }    
            }
        }
    }
    
}

void DGV::saiDoCarro(char id){
    for(auto it=carro.begin();it<carro.end(); it++){
        if((*it)->getId()==id ){
             (*it)->getPiloto()->saiCarro();
        }
    }
}


 
void DGV:: eliminaPiloto(string nm){
   
    for(auto it=piloto.begin();it<piloto.end();it++){
        if(nm==(*it)->getNome()){
            (*it)->saiCarro();
            delete (*it);
             piloto.erase(it);
        }     
    } 
}

void DGV::eliminaCarro(char id){
    for(auto it=carro.begin();it<carro.end();it++){
        if( (*it)->getId() == id){
            if((*it)->getOcupado())
                (*it)->getPiloto()->saiCarro();
            delete (*it);
            carro.erase(it);
			return;

        }
    }
}

string DGV::getPilotos()const{
    ostringstream os;
    for(Piloto *a: piloto){
        os<<a->getAsString()<<endl ;
	}
   
    return os.str();
}


string DGV::getCarros()const{
    ostringstream os;
    for(Carro *a: carro){
        os<<a->getAsString()<<endl ;
}
   
    return os.str();
}



vector<Carro*> DGV::getCarrosCampeonato(){
    vector<Carro*> aux;
    
    for(auto itC=carro.begin();itC<carro.end();){
        if((*itC)->getOcupado()==true){
            
            for(auto itP=piloto.begin();itP<piloto.end();){
               if(((*itP)->getNome())==(*itC)->getPiloto()->getNome()){ 
                    aux.push_back(*itC);
                    piloto.erase(itP);
                    
                    
                    itP=piloto.begin(); 
               }else
                   itP++;
            }
            carro.erase(itC);
            itC=carro.begin();
        }else
            itC++;
    }
    
    return aux;
}

string DGV::getNome()
{
	return nome;
}

void DGV::setNome(string name)
{
	nome = name;
}
