/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.cpp
 * Author: treys
 * 
 * Created on 24 de Dezembro de 2019, 15:01
 */

#include <fstream>

#include "Simulador.h"

Simulador::Simulador() {
    modo1=true;
    dgv=new DGV();

}

Simulador::~Simulador() {
    
    for(Autodromo* a: autodromo)
        delete a;
    delete dgv;
    delete campeonato;
	for (DGV* a : copiaDgv)
		delete a;
}

void Simulador::carregaP(string nomeFicheiro){
    if(modo1){
        string linha="";
        string nome="";
		string tipo = "";
        
        ifstream ficheiro; 
        ficheiro.open(nomeFicheiro); 

        if(ficheiro.is_open()){
            while(getline(ficheiro,linha)){
                istringstream ss(linha);
                ss>>nome;
				ss >> tipo;
                dgv->addPiloto(nome,tipo);
            }
        }else{
            cout<<"Erro ao abrir arquivo"<<endl;
        }
    }
}

void Simulador::carregaC(string nomeFicheiro){
    if(modo1){
        string linha="";
        string marca="";
        string modelo="";
        double ener;
        double maxE;
        int velM;
        
        ifstream ficheiro; 
        ficheiro.open(nomeFicheiro); 

        if(ficheiro.is_open()){
            while(getline(ficheiro,linha)){
                istringstream ss(linha);
                ss>>ener;
                ss>>maxE;
                ss>>marca;
                ss>>modelo;
                ss>>velM;
                dgv->addCarro(marca,ener,maxE,velM,modelo);
            }
        }else{
            cout<<"Erro ao abrir arquivo"<<endl;
        }
    }
}

void Simulador::carregaA(string nomeFicheiro){
    if(modo1){
        vector <string> autodromos;
        for(auto it=autodromo.begin() ;it<autodromo.end();it++){
            autodromos.push_back((*it)->getNome());
        }
        
        string linha="";
        string nome="";
        int dimensao;
        int numMaxEquipa;
        
        ifstream ficheiro; 
        ficheiro.open(nomeFicheiro); 

        if(ficheiro.is_open()){
            while(getline(ficheiro,linha)){
                istringstream ss(linha);
                ss>>numMaxEquipa;
                ss>>dimensao;
                ss>>nome;
                autodromo.push_back(new Autodromo(nome,dimensao,numMaxEquipa,autodromos));
            }
        }else{
            cout<<"Erro ao abrir arquivo"<<endl;
        }
    }
}

void Simulador::savedgv(string nome)
{
	copiaDgv.push_back(new DGV(*dgv));
	copiaDgv.at(copiaDgv.size()-1)->setNome(nome);
}


void Simulador::loadDgv(string nome)
{
	for (DGV *a : copiaDgv) {
		if (a->getNome() == nome) {
			delete dgv;
			dgv = a;
			return;
		}
	}
}


void Simulador::deldgv(string nome)
{
	for (auto it = copiaDgv.begin(); it < copiaDgv.end();it++) {
		if ((*it)->getNome() == nome) {
			delete *it;
			copiaDgv.erase(it);
			return;
		}
	}
}

void Simulador::criaP(string nome, string tipo){
    if(modo1)
        dgv->addPiloto(nome, tipo);
}

void Simulador::criaC(string mrc , double enrg,  double maxE, int velM, string mod){
    if(modo1)
        dgv->addCarro(mrc,enrg,maxE,velM,mod);
}
void Simulador::criaC(string mrc , double enrg,  double maxE, int velM){
    if(modo1)
        dgv->addCarro(mrc,enrg,maxE,velM);
}

void Simulador::criaA(string nome, int dim, int maxE){
    if(modo1){
        vector <string> autodromos;
        int i=0;
        for(auto it=autodromo.begin() ;it<autodromo.end();it++, i++){
            autodromos.push_back((*it)->getNome());
        }

        autodromo.push_back(new Autodromo(nome,dim,maxE,autodromos));
    }
}


void Simulador::apagaP(string nome){
    if(modo1)
        dgv->eliminaPiloto(nome);     
}

void Simulador::apagaC(char id){
    if(modo1)
        dgv->eliminaCarro(id);     
}

void Simulador::apagaA(string nome){
    if(modo1){
        for(auto it=autodromo.begin();it<autodromo.end();it++){
            if((*it)->getNome()==nome){
                delete *it;
                autodromo.erase(it);
            }
        }
    }   
}

void Simulador::entraNoCarro(char id, string nome){
    if(modo1)
        dgv->entraNoCarro(id,nome);
}

void Simulador::saiDoCarro(char id){
    if(modo1)
        dgv->saiDoCarro(id);
}

string Simulador::lista()const{
    ostringstream os;
    if(modo1){
        os<<"\t\tAutodromos"<<endl;
        for(Autodromo* a: autodromo)
            os<< a->getAsString() << endl;
        os<<endl<<"\t\tCarros"<<endl;
        os<< dgv->getCarros();
        os<<endl<<"\t\tPilotos"<<endl;
        os<< dgv->getPilotos();
    }
    return os.str();
}

bool Simulador::camp(vector <string> autodromos){
    vector <Autodromo*> auxA;
    vector <Equipa*> auxE;
    vector <Carro*> auxC;
    for(string nome: autodromos){
        if(getAutodromo(nome)!=nullptr){
            auxA.push_back(getAutodromo(nome));
        }
    }
    auxC=dgv->getCarrosCampeonato();
    if(auxA.size()>=1 && auxC.size()>=2){
        for(Carro* carro: auxC){
        auxE.push_back(new Equipa(carro));
        }
        campeonato = new Campeonato(dgv, auxA, auxE);
        modo1=false;
	
        return true;
    }  
    return false;
}

string Simulador::listaCarros()const{
    ostringstream os;
    if(!modo1){

        os<< campeonato->listacarros(); 
    }
    return os.str(); 
}

void Simulador::carregabat (char id, double q){
    if(!modo1)
        campeonato->carregabat(id, q);
}

void Simulador::carregatudo(){
    if(!modo1)
        campeonato->carregatudo();
}

void Simulador::acidente (char id){
    if(!modo1)
        campeonato->acidente(id);
}

void Simulador::corrida(){
    if(!modo1)
        campeonato->corrida();
}

void Simulador::stop (string nome){
    if(!modo1)
        campeonato->stop(nome);
}

void Simulador::destroi(char id){
    if(!modo1)
        campeonato->destroi(id);
}

bool Simulador::passaTempo(int n){
    if(!modo1)
        return campeonato->passaTempo(n);
	return true;
}

Autodromo* Simulador::getAutodromo(string nome){
    Autodromo* aux=nullptr;
    for(auto it=autodromo.begin();it<autodromo.end();it++){
        if((*it)->getNome()==nome)
            aux=(*it);
    }
    return aux;
}

vector<string> Simulador::getInfoDisplay() const
{
	return campeonato->getInfoDisplay();
}

vector<string> Simulador::getDisplayPontuacao() const
{
	return campeonato->getDisplayPontuacao();
}

vector<string> Simulador::getVencedores() const
{
	return campeonato->getVencedores();
}
