/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Autodromo.h
 * Author: treys
 *
 * Created on 25 de Dezembro de 2019, 7:36
 */

#ifndef AUTODROMO_H
#define AUTODROMO_H
#include "Equipa.h"
#include <vector>
#include <algorithm>
#include <iostream>


class Autodromo {
    string nome;
    const int dimensaoPista;
    const int numMaxPista;
    
    vector<Equipa*> garagem; 
    vector <Equipa*> pista;
    
    int copia;
	int segundoCorrida;
    //funcao utilidade privado
    void  classificacao();
    
    
public:
    Autodromo(string nm, int dim, int maxE,vector<string> listaAutodromo);
    Autodromo(Autodromo& orig);
    virtual ~Autodromo();
    
    // funçoes consulta
    string listaGaragem()const;
    string listaPista()const;
     bool finalCorrida();
    
    // funçoes controlo
    void moveGaragem(char e);
    bool simula(int segundos);
    void iniciaCorrida();
    void inunda();
    void carregabat (char id, double q);
    void carregatudo();
    void acidente (char id);
    void stop (string nome);
    Piloto* destroi(char id);
    
    // funçoes set
    void setEquipa(vector <Equipa*>e);
    
    // funçoes get
    int getNumEquipa()const;
    int getDimensao()const;
    Equipa* getEquipa(char idC);
    vector <Equipa*> getEquipas();
    string getNome()const;
    string getAsString()const;

	vector <string> getInfoDisplay()const;
	vector <string> getDisplayPontuacao();
};

#endif /* AUTODROMO_H */

