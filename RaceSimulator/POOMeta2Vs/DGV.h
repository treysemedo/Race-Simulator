/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGV.h
 * Author: treys
 *
 * Created on 25 de Dezembro de 2019, 6:30
 */

#ifndef DGV_H
#define DGV_H
#include "Piloto.h"
#include "CrazyDriver.h"
#include <iostream>

using namespace std;
class DGV {
	string nome;
    vector <Carro*> carro;
    vector <Piloto*> piloto;
    
public:
    DGV(string name="original");
    DGV( DGV& orig);
    virtual ~DGV();
    
    //funções controlo DGV
    void addCarro(  string mrc , double enrg,  double maxE, int velM, string mod);
    void addCarro(  string mrc , double enrg,  double maxE, int velM);
    void addPiloto(string nm, string tipo);
    void entraNoCarro(char id, string nm );
    void saiDoCarro(char id);
    void eliminaCarro(char id);
    void eliminaPiloto(string nm);
    void acrescentaPiloto(Piloto* a);
    void acrescentaCarro(Carro* a);
    // funçoes get
	vector <Carro*> getCarro();
	vector <Piloto*> getPiloto();
    string getPilotos()const;
    string getCarros()const;   
    vector<Carro*> getCarrosCampeonato();
	string getNome();

	void setNome(string name);
 
};

#endif /* DGV_H */

