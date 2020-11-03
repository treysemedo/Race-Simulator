#pragma once
#include "Piloto.h"
#include <cstdlib>
#include <ctime>
class CrazyDriver :public Piloto
{
	int segundoCorrida;
	int	comecaCorrida;
	int lugarAnterior;
public:
	CrazyDriver(string nm, vector<string> listaPilotos);
	CrazyDriver(CrazyDriver& orig);

	void simula(int lugar, int segundoC, int numUltimo);
	void chegaMeta();
};

