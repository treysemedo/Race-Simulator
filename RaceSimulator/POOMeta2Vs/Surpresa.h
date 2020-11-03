#pragma once
#include "Piloto.h"
#include <cstdlib>
#include <ctime>
class Surpresa :
	public Piloto
{
public:
	Surpresa(string nm, vector<string> listaPilotos);
	Surpresa(Surpresa & orig);
	
	void simula(int lugar, int segundoC, int numUltimo);
};

