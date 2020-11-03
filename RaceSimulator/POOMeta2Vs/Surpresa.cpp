#include "Surpresa.h"



Surpresa::Surpresa(string nm, vector<string> listaPilotos) :Piloto::Piloto(nm, listaPilotos)
{
}

Surpresa::Surpresa(Surpresa & orig) : Piloto::Piloto(orig)
{
}

void Surpresa::simula(int lugar, int segundoC, int numUltimo)
{
	if (!Piloto::getOrdemPara()) {
		srand((unsigned)time(0));
		int probAcelera = rand() % (100) + 1;
		
		if (probAcelera > 20 && probAcelera <= 100) {
			Piloto::pedalAcelerador();
		}else
			Piloto::pedalTravao();
		
	}else if (Piloto::getOrdemPara())
		Piloto::pedalTravao();
}
