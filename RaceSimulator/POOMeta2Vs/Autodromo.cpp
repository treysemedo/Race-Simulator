/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autodromo.cpp
 * Author: treys
 * 
 * Created on 25 de Dezembro de 2019, 7:36
 */

#include "Autodromo.h"

Autodromo::Autodromo(string nm, int dim, int maxE,vector<string> listaAutodromo):nome(nm),dimensaoPista(dim),numMaxPista(maxE) {
    int i = 1;
    string aux = nm;

    for (auto it = listaAutodromo.begin(); it < listaAutodromo.end(); it++) {
        if (aux == (*it)) {
            aux = nm;
            stringstream ss;
            ss << i;
            string str = ss.str();
            aux.append(str);
            it = listaAutodromo.begin();
            i++;
        }
    }

    nome = aux;
    copia = 1;
	segundoCorrida = 0;
 
}

Autodromo::Autodromo(Autodromo& orig):dimensaoPista(orig.dimensaoPista),numMaxPista(orig.numMaxPista) {
    stringstream ss;
    ss << orig.copia++;
    string str = ss.str();
    nome.append(orig.nome + "Copia" + str);

    copia=1;
	segundoCorrida = 0;
}

Autodromo::~Autodromo() {
    for(Equipa *a: garagem)
        delete a;
    for(Equipa *a: pista)
        delete a;
}

string Autodromo::listaGaragem()const{
    ostringstream os;
    for(Equipa * a: garagem){
        os<<a->getAsString()<<endl;
    }
    return os.str();
}

string Autodromo::listaPista()const{
    ostringstream os;
    for(Equipa * a: pista)
        os<<a->getAsString()<<endl;
    return os.str();
}

void Autodromo:: moveGaragem(char e){
    Equipa *aux=getEquipa(e);
    

    if(aux!=nullptr){
        for(auto it=pista.begin();it<pista.end();it++){
            if(aux->getCarro()->getId()==(*it)->getCarro()->getId()){
                garagem.push_back(*it);
                pista.erase(it);
				 return;
            }
        }
        
    
    }
    
}

bool Autodromo::finalCorrida(){
    bool parados=true;
    bool danificados=true;
    int terminaram=0;
    

     for(Equipa* a:pista){
       
        if(a->getCarro()->getDanificado()==false)
            danificados=false;
       
        if(a->getCarro()->getParado()==false || segundoCorrida<=1 && a->getCarro()->getParado())
            parados=false;
        
        if(a->getPos()>=dimensaoPista){
            a->chegaMeta(dimensaoPista);
            terminaram++;
        }
    }
    
    if(terminaram<3 && !danificados && !parados)
        return false;
    else{
        for(Equipa *a:pista){
            if(a->getLugar()==1 && a->getPos()>=dimensaoPista)
                a->setPontuacao(a->getPontuacao()+10);
            else if(a->getLugar()==2 && a->getPos() >= dimensaoPista)
                a->setPontuacao(a->getPontuacao()+5);
            else if(a->getLugar()==3 && a->getPos() >= dimensaoPista)
                a->setPontuacao(a->getPontuacao()+2);
            garagem.push_back(a);
        }
        
        pista.clear();
        
        for(Equipa *a:garagem){
            a->setLugar(0);
            a->setPosicao(0);
        }
        
    }
    return true;
}

bool auxSort(const Equipa* a,const Equipa* b){
    return *a>*b;
}

void Autodromo:: classificacao(){
    vector <Equipa*> vetorAux=pista;
    unsigned int i;
    
    sort(vetorAux.begin(),vetorAux.end(),auxSort);
   
    for(i=0;i<vetorAux.size();i++){
        vetorAux[i]->setLugar(i+1);
    }
}

bool Autodromo:: simula(int segundos){
    
    
    for(int i=0;i<segundos;i++){
        if(!finalCorrida()){
           
            for(Equipa* a:pista){
  
                if(a->getPos()<dimensaoPista ){
                    if(a->getPos()+a->getCarro()->getVelocidade()>dimensaoPista){
                        a->chegaMeta(dimensaoPista);
                    }else{
                        a->simula(dimensaoPista, segundoCorrida+1, pista.size());
                    }
                }
            }
			segundoCorrida++;
			for (Equipa* a : pista) {
				if ((a->getPos() < dimensaoPista && a->getPiloto()->getOrdemPara() && a->getCarro()->getParado()) || a->getCarro()->getEmergencia() || a->getCarro()->getDanificado()) {
					moveGaragem(a->getCarro()->getId());
				}
			}
			classificacao();
		}else {
			classificacao();
			return false;
		}
    }
    return true;
}
    



void Autodromo::setEquipa(vector <Equipa*>e){
    garagem=e;
}

void Autodromo::iniciaCorrida(){
    int conta =0;
    auto it=garagem.begin();
    
    do{
        if(!(*it)->getCarro()->getDanificado() ){
            pista.push_back((*it));
            garagem.erase(it);
            it=garagem.begin();
            conta++;
            
       }else 
            it++;
    }while(it<garagem.end()&& conta<numMaxPista);
    
}

void Autodromo::inunda(){
    for(Equipa *a: pista){
        a->getCarro()->acidente();
    }
    for(Equipa *a: garagem){
        a->getCarro()->acidente();
    }
}

void Autodromo:: carregatudo(){
    for(Equipa *a: pista){
        a->getCarro()->setEnergia(a->getCarro()->getMaxEnergia());
    }
    for(Equipa *a: garagem){
        a->getCarro()->setEnergia(a->getCarro()->getMaxEnergia());
    }
}
void Autodromo::carregabat (char id, double q){
    if(getEquipa(id)!= nullptr)
       getEquipa(id)->getCarro()->carregaBateria(q);
}
 void Autodromo::acidente (char id){
     if( getEquipa(id)!= nullptr)
         getEquipa(id)->getCarro()->acidente();
     
     
 }
 void Autodromo::stop (string nome){
     for(Equipa* a:pista){
		 if (a->getPiloto()->getNome() == nome) {
			 a->getPiloto()->para();
			 return;
		 }
	 }
     
 }
 
 Piloto* Autodromo::destroi(char id){
     Piloto* aux=nullptr;
       for(auto it=pista.begin();it<pista.end();it++){
        if(id == (*it)->getCarro()->getId()){
            aux=(*it)->getPiloto();
            (*it)->getPiloto()->saiCarro();
            delete(*it);
            pista.erase(it);
			return aux;
        }
    }
     return aux;
 }

int Autodromo::getNumEquipa()const {
    return pista.size();
}

int Autodromo::getDimensao()const{
    return dimensaoPista;
}

Equipa* Autodromo::getEquipa(char idC){
    for(auto it=pista.begin();it<pista.end();it++){
        if(idC == (*it)->getCarro()->getId()){
            return (*it);
        }
    }
    return nullptr;
}


vector <Equipa*>Autodromo::getEquipas(){
    vector <Equipa*> aux= garagem;
    garagem.clear();
    return aux;
}

string Autodromo::getNome()const{
    return nome;
}

string Autodromo::getAsString()const{
    ostringstream os;
    os<< "\t\tNome: " <<nome << " Dimensao: " << dimensaoPista << " Maximo Equipa: " << numMaxPista;
    return os.str();
}

vector<string> Autodromo::getInfoDisplay() const
{
	vector<string> aux;
	ostringstream auxStr;

	aux.push_back(nome);

	auxStr << dimensaoPista;
	aux.push_back(auxStr.str());

	auxStr.str("");
	auxStr.clear();
	auxStr << numMaxPista;
	aux.push_back(auxStr.str());

	for (Equipa* a : pista) {
		auxStr.str("");
		auxStr.clear();
		auxStr << a->getCarro()->getId() << " ";
		auxStr << a->getPos();
		aux.push_back(auxStr.str());
	}
	
	return aux;
}

bool maiorPontuacao(const Equipa* a, const Equipa* b) {

	return a->getPontuacao() > b->getPontuacao();
}

vector<string> Autodromo::getDisplayPontuacao() 
{
	vector <Equipa*> Aux;
	vector <string> Aux1;
	ostringstream os;
	int maior = 0, i = 0;

	for (Equipa * a : pista) {
		if (!a->getCarro()->getDanificado())
			Aux.push_back(a);
	}
		
	for (Equipa *a : garagem) {
		if (!a->getCarro()->getDanificado())
			Aux.push_back(a);
	}
	

	sort(Aux.begin(), Aux.end(), maiorPontuacao);

	for (Equipa * a : Aux) {
		os.str("") ;
		os.clear();
		os << a->getCarro()->getId() << " " << a->getPontuacao();
		Aux1.push_back(os.str());
	}

	return Aux1;
}




