/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piloto.cpp
 * Author: treys
 * 
 * Created on 24 de Dezembro de 2019, 15:28
 */

#include "Piloto.h"


Piloto::Piloto(string nm, vector<string> listaPilotos) {
    int i = 1;
    string aux = nm;

    for (auto it = listaPilotos.begin(); it < listaPilotos.end(); it++) {
        if (aux == (*it)) {
            aux = nm;
            stringstream ss;
            ss << i;
            string str = ss.str();
            aux.append(str);
            it = listaPilotos.begin();
            i++;
        }
    }

    nome = aux;
    carro = nullptr;
    vivo = true;
    livre = true;
    copia = 1;
    ordemPara=false;
}

Piloto::Piloto(Piloto& orig) {
    nome=orig.nome;

    carro = nullptr;
    vivo = true;
    livre = true;
    copia = 1;
    ordemPara=false;
}

void Piloto::entraCarro(Carro *c) {
    if (c == nullptr) {
        return;
    }
    if (vivo && livre) {
        if ((carro = c->setPiloto(this)) != nullptr)
            livre = false;
    }
}

void Piloto::saiCarro() {
    if (vivo && !livre) {
        carro->setPiloto(nullptr);
        carro = nullptr;
        livre = true;
    }
}

void Piloto::pedalAcelerador() {
    if (!livre && vivo) {
        carro->acelera();
    }
}

void Piloto::pedalTravao() {
    if (!livre && vivo) {
        carro->trava();
    }
}

void Piloto::ligaEmergencia() {
    if (!livre && vivo)
        carro->ligaEmergencia();
}

void Piloto::desligaEmergencia() {
    if (!livre && vivo)
        carro->desligaEmergencia();
}

void Piloto::simula(int lugar, int segundoC, int numUltimo)
{
	if (carro->getVelocidade() < carro->getMaxVelocidade() && !ordemPara)
		pedalAcelerador();
	else if (ordemPara)
		pedalTravao();
}

void Piloto:: para(){
    ordemPara=true;
}

void Piloto::resetOrdemPara()
{
	ordemPara = false;
}

void Piloto::chegaMeta()
{

}


void Piloto::acidentado() {
    vivo = false;
}

bool Piloto::getLivre()const {
    return livre;
}

string Piloto::getAsString()const {
    ostringstream os;
    if (carro != nullptr)
        os << "\t\tNome: " << nome << " Vivo: " << vivo << " Carro: " << carro->getId();
    else
        os << "\t\tNome: " << nome << " Vivo " << vivo;

    return os.str();
}

string Piloto::getNome()const {
    return nome;
};
 bool Piloto::getOrdemPara()const{
     return ordemPara;
 }

 Carro * Piloto::getCarro()
 {
	 return carro;
 }
