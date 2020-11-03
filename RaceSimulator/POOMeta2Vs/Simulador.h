/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.h
 * Author: treys
 *
 * Created on 24 de Dezembro de 2019, 15:01
 */

#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "Campeonato.h"
class Simulador {
    vector<Autodromo*>autodromo;
    DGV *dgv;
	vector<DGV *>copiaDgv;
    Campeonato *campeonato;
    bool modo1;
public:
    Simulador();
    Simulador(const Simulador& orig)=delete;
    virtual ~Simulador();
    
    
    //modo1
    void carregaP(string nomeFicheiro);
    void carregaC(string nomeFicheiro);
    void carregaA(string nomeFicheiro);
	void savedgv(string nome);
	void loadDgv(string nome);
	void deldgv(string nome);
    void criaP(string nome, string tipo);
    void criaC(string mrc , double enrg,  double maxE, int velM, string mod);
    void criaC(string mrc , double enrg,  double maxE, int velM);
    void criaA(string nome, int dim, int maxE);
    void apagaP(string nome);
    void apagaC(char id);
    void apagaA(string nome); 
    
    void entraNoCarro(char id, string nome);
    void saiDoCarro(char id);
    
    string lista()const;
    
    
    //modo2
    bool camp(vector <string> autodromos);
    string listaCarros()const;
    void carregabat (char id, double q);
    void carregatudo();
    void acidente (char id);
	void corrida();
    void stop (string nome);
    void destroi(char id);
    bool passaTempo(int n);
    
    //funcoes get
    Autodromo* getAutodromo(string nome);

	vector <string> getInfoDisplay()const;
	vector <string> getDisplayPontuacao()const;
	vector <string> getVencedores()const;
};

#endif /* SIMULADOR_H */

