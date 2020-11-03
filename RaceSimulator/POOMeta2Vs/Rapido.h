#pragma once
#include "Piloto.h"
#include <cstdlib>
#include <ctime>
class Rapido : public Piloto{
	int atuarAcelerador;
public:
	Rapido(string nm, vector<string> listaPilotos);
	Rapido(Rapido & orig);

	void simula(int lugar, int segundoC, int numUltimo);
	void chegaMeta();
};

