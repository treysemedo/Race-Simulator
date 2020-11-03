/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carro.h
 * Author: treys
 *
 * Created on 24 de Dezembro de 2019, 15:05
 */

#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <sstream>


class Piloto;
using namespace std;

class Carro {
    
    const string marca;
    const string modelo;
    
    static char contaId;
    const char id;
    
    double energia;
    const double maxEnergia;
    
    int velocidade;
    const int velocidadeMax;
    
    bool parado;
    bool emergencia;
    bool danificado;
    bool ocupado;

    Piloto *piloto;
public:
    Carro(string mrc , double enrg,  double maxE, int velM, string mod="ModeloBase");
    Carro(const Carro& orig);
    
    //funçoes comportamento carro
    void carregaBateria(double n);
    void acelera();
    void trava();
    void ligaEmergencia();
    void desligaEmergencia();
    void acidente();
    void simula();
    void chegaMeta(int distancia);

    //metodos set
    Carro* setPiloto(Piloto *p);
    void setEnergia(double e);
   
    
    //metodos get
    char getId()const;
    Piloto* getPiloto()const;
    bool getOcupado()const;
    bool getParado()const;
    bool getDanificado()const;
	bool getEmergencia()const;
    string getAsString()const;
    int getVelocidade()const;
    int getMaxVelocidade()const;
    double getEnergia()const;
    double getMaxEnergia()const;
    
};

#endif /* CARRO_H */

