/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Campeonato.cpp
 * Author: treys
 * 
 * Created on 28 de Dezembro de 2019, 11:35
 */

#include "Campeonato.h"

Campeonato::Campeonato(DGV *d,vector<Autodromo*>aut ,vector<Equipa* > e):dgv(d),autodromo(aut){
    numeroCorrida=0;
    autodromo.at(numeroCorrida)->setEquipa(e);
    inicioCorrida=false;
}

Campeonato::~Campeonato() {
}

bool Campeonato::passaTempo(int n){
	if (inicioCorrida) {
		vector<Equipa*> auxE;
		
		if (!autodromo.at(numeroCorrida)->simula(n) && numeroCorrida == autodromo.size() - 1) {
			vencedores=autodromo.at(numeroCorrida)->getDisplayPontuacao();
			auxE = autodromo.at(numeroCorrida)->getEquipas();
			for (Equipa *a : auxE) {
				dgv->acrescentaPiloto(a->getPiloto());
				dgv->acrescentaCarro(a->getCarro());
			}
			return false;
		}
	}
	return true;
}

void Campeonato::corrida(){
    
    if(numeroCorrida==0 && !inicioCorrida){
        autodromo.at(numeroCorrida)->iniciaCorrida();
        inicioCorrida=true;
    }else if(numeroCorrida==0 && inicioCorrida && autodromo.at(numeroCorrida)->finalCorrida() && numeroCorrida+1<autodromo.size()){
        vector <Equipa*> aux=autodromo.at(numeroCorrida)->getEquipas();
        numeroCorrida++;
        autodromo.at(numeroCorrida)->setEquipa(aux);
        autodromo.at(numeroCorrida)->iniciaCorrida();
    }else if(numeroCorrida>0 && numeroCorrida!=autodromo.size()-1 && autodromo.at(numeroCorrida)->finalCorrida() && numeroCorrida+1 < autodromo.size()){
        vector <Equipa*> aux=autodromo.at(numeroCorrida)->getEquipas();
        numeroCorrida++;
        autodromo.at(numeroCorrida)->setEquipa(aux);
        autodromo.at(numeroCorrida)->iniciaCorrida();
    }   
}

string Campeonato::listacarros() const{
    ostringstream os;
    os<<"\t\t\t\t\t\t\tAUTODROMO "<<autodromo.at(numeroCorrida)->getNome()<<endl<<endl;
    os<<"\t\tPista"<<endl;
    os<<autodromo.at(numeroCorrida)->listaPista();
    os<<endl<<"\t\tGaragem"<<endl;
    os<<autodromo.at(numeroCorrida)->listaGaragem();

     return os.str();
}

void Campeonato::carregabat (char id, double q){
    autodromo.at(numeroCorrida)->carregabat(id, q);
}
void Campeonato::carregatudo(){
    autodromo.at(numeroCorrida)->carregatudo();
}
void Campeonato::acidente (char id){
    autodromo.at(numeroCorrida)->acidente(id);
}
void Campeonato::stop (string nome){
    autodromo.at(numeroCorrida)->stop(nome);
    
}
void Campeonato::destroi(char id){
    Piloto *aux=autodromo.at(numeroCorrida)->destroi(id);
    
    if(aux!=nullptr)
    dgv->acrescentaPiloto(aux);
    
}

vector <string> Campeonato::getInfoDisplay()const {


	return autodromo.at(numeroCorrida)->getInfoDisplay();
}

vector<string> Campeonato::getDisplayPontuacao() const
{
	return autodromo.at(numeroCorrida)->getDisplayPontuacao();
}

vector<string> Campeonato::getVencedores() const
{
	return vencedores;
}
