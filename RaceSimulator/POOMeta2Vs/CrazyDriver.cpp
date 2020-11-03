#include "CrazyDriver.h"



CrazyDriver::CrazyDriver(string nm, vector<string> listaPilotos):Piloto::Piloto( nm, listaPilotos)
{
	segundoCorrida = 0;
	comecaCorrida = 0;
	lugarAnterior = 0;
}

CrazyDriver::CrazyDriver(CrazyDriver & orig):Piloto::Piloto(orig)
{
	segundoCorrida = 0;
	comecaCorrida = 0;
	lugarAnterior = 0;
}

void CrazyDriver::simula(int lugar, int segundoC, int numUltimo)
{
	segundoCorrida = segundoC;
	if (segundoCorrida == 1) {
		srand((unsigned)time(0));
		comecaCorrida = rand() % (5) + 1;
	}else if (!Piloto::getOrdemPara() && segundoCorrida>=comecaCorrida) {
		srand((unsigned)time(0));
		int probDanificado = rand() % (100) + 1;

		if (probDanificado > 0 && probDanificado <= 5) 
			Piloto::getCarro()->acidente();
		else if (Piloto::getCarro()->getEnergia() == 0)
			Piloto::ligaEmergencia();
		else if (lugar > 1 && lugar < numUltimo) {
			if (lugar < lugarAnterior) {
				Piloto::pedalAcelerador();
				Piloto::pedalAcelerador();
			}else
				Piloto::pedalAcelerador();
		}else if(lugar==numUltimo)
			Piloto::pedalTravao();
		
	}else if (Piloto::getOrdemPara())
			Piloto::pedalTravao();
}

void CrazyDriver::chegaMeta()
{
	segundoCorrida = 0;
	comecaCorrida = 0;
	lugarAnterior = 0;
	Piloto::resetOrdemPara();
}

