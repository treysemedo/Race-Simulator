#include "Rapido.h"



Rapido::Rapido(string nm, vector<string> listaPilotos) :Piloto::Piloto(nm, listaPilotos)
{
	atuarAcelerador = 0;
}

Rapido::Rapido(Rapido & orig) : Piloto::Piloto(orig)
{
	atuarAcelerador = 0;
}

void Rapido::simula(int lugar, int segundoC, int numUltimo)
{
	if (!Piloto::getOrdemPara()) {
		if ((segundoC % 10) == 0) {
			srand((unsigned)time(0));
			int probLigaEmergencia = rand() % (100) + 1;
			if(probLigaEmergencia>=1 && probLigaEmergencia <=10)
				Piloto::ligaEmergencia();
		}
		if ((Piloto::getCarro()->getEnergia()) > (Piloto::getCarro()->getMaxEnergia() / 2))
			Piloto::pedalAcelerador();
		else if (atuarAcelerador == 3) {
			Piloto::pedalAcelerador();
			atuarAcelerador = 0;
		}else
			atuarAcelerador++;
	}else if (Piloto::getOrdemPara())
		Piloto::pedalTravao();
}

void Rapido::chegaMeta()
{
	atuarAcelerador = 0;
	Piloto::resetOrdemPara();
}