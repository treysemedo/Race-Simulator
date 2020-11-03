/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Campeonato.h
 * Author: treys
 *
 * Created on 28 de Dezembro de 2019, 11:35
 */

#ifndef CAMPEONATO_H
#define CAMPEONATO_H
#include "DGV.h"
#include "Autodromo.h"
#include "Equipa.h"
class Campeonato {
    DGV *dgv;
    vector<Autodromo*>autodromo;
    unsigned int numeroCorrida;
    bool inicioCorrida;
    bool inicioCorridaCorrida;
	vector<string> vencedores;
	
public:
    Campeonato(DGV *d,vector<Autodromo*>aut, vector<Equipa* > e);
    Campeonato(const Campeonato& orig)=delete;
    virtual ~Campeonato();
    
	bool passaTempo(int n);
	void corrida();

    
    string listacarros() const;
    void carregabat (char id, double q);
    void carregatudo();
    void acidente (char id);
    void stop (string nome);
    void destroi(char id);
	

	vector <string> getInfoDisplay()const;
	vector <string> getDisplayPontuacao()const;
	vector <string> getVencedores()const;
};

#endif /* CAMPEONATO_H */

