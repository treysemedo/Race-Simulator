/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piloto.h
 * Author: treys
 *
 * Created on 24 de Dezembro de 2019, 15:28
 */

#ifndef PILOTO_H
#define PILOTO_H
#include "Carro.h"
#include <string>
#include <sstream>
#include <vector>


using namespace std;

class Piloto {
    string nome;
    Carro *carro;
    bool vivo;
    bool livre;
    bool ordemPara;
    int copia;
public:
    Piloto(string nm, vector<string> listaPilotos);
    Piloto(Piloto& orig);
    virtual ~Piloto(){}
    
    //funções piloto
    void entraCarro(Carro *c);
    void saiCarro();
    void pedalAcelerador();
    void pedalTravao();
    void acidentado();
    void ligaEmergencia();
    void desligaEmergencia();  
    virtual void simula(int lugar, int segundoC, int numUltimo);
    void para();
	void resetOrdemPara();
	virtual void chegaMeta();
    
    //funçoes get
    string getAsString () const;
    string getNome()const;
    bool getLivre()const;
    bool getOrdemPara()const;
	Carro* getCarro();
    
};

#endif /* PILOTO_H */

