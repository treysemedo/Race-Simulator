/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Interface.cpp
  * Author: treys
  *
  * Created on 24 de Dezembro de 2019, 14:59
  */

#include "Interface.h"

Interface::Interface() {
	corFundoPrincipal = Consola::BRANCO;
	corFundoComando = Consola::PRETO;

	corTexto = Consola::Consola::PRETO;
	corTextoComando = Consola::BRANCO_CLARO;


	tamanhoTitulo = 14;
	tamanhoTexto = 10;

	posxTitulo = 40;
	posyTitulo = 10;

	posxComando = 40;
	posyComando = 25;

	modo1 = true;
	simulador = new Simulador();


}

Interface::~Interface() {
}

void Interface::telaInicio() {

	//confiuraçao tela inicial
	Consola::setBackgroundColor(corFundoPrincipal);
	Consola::setTextColor(corTexto);
	Consola::clrscr();

	if (modo1) {
		Consola::gotoxy(posxTitulo, posyTitulo);
		cout << "RACE SIMULATOR";
	}


}

int Interface::visualizador()
{	
	char id;
	int posy=0, posx=10, tam, numMaxEquipa, a;
	string nomeA;
	vector <string> infoDisplay;
	Consola::setBackgroundColor(corFundoPrincipal);
	Consola::setTextColor(corTexto);
	Consola::clrscr();
	

	infoDisplay=simulador->getInfoDisplay();
	stringstream iss(infoDisplay.at(0));
	iss >> nomeA;
	stringstream iss1(infoDisplay.at(1));
	iss1 >> tam;
	stringstream iss2(infoDisplay.at(2));
	iss2 >> numMaxEquipa;
	
	
	for (unsigned int i = 2; i < infoDisplay.size(); i++) {
		stringstream iss2(infoDisplay.at(i));

		iss2 >> id;
		iss2 >> posx;
		imprimeCarro(id, posx, posy);
		posy += 5;
	}
	a = imprimePista(infoDisplay.at(0), tam, numMaxEquipa, 10, 8);
	


	imprimePontuacao(tam+12, 9);
	return a;
}

void Interface::imprimeCarro(char id, int posx, int posy) {
		Consola::setBackgroundColor(id - 96);
		Consola::gotoxy(posx + 3, posy + 5);
		cout << "  ";
		Consola::gotoxy(posx + 6, posy + 5);
		cout << "  ";
		Consola::gotoxy(posx + 4, posy + 6);
		cout <<" " <<id<<" ";
		Consola::gotoxy(posx + 7, posy + 6);
		cout << "   ";
		Consola::gotoxy(posx + 3, posy + 7);
		cout << "  ";
		Consola::gotoxy(posx + 6, posy + 7);
		cout << "  ";

		Consola::setBackgroundColor(corFundoPrincipal);
		Consola::setTextColor(corTexto);
}

void Interface::imprimePontuacao(int posx,int posy)
{
	vector<string> infoPontuacao;
	infoPontuacao =simulador->getDisplayPontuacao();
	
	Consola::gotoxy(posx, posy++);
	Consola::setBackgroundColor(Consola::COR_DE_ROSA);
	cout << " ";
	Consola::setBackgroundColor(corFundoPrincipal);
	cout << "PONTUACAO GERAL";
	for (string a : infoPontuacao) {
		Consola::gotoxy(posx, posy++);
		Consola::setBackgroundColor(Consola::COR_DE_ROSA);
		cout << " ";
		Consola::setBackgroundColor(corFundoPrincipal);
		
		cout << a << endl;
	}
	Consola::setBackgroundColor(corFundoPrincipal);

}

void Interface::imprimeVencedores(string n1, string n2, string n3)
{
	Consola::clrscr();
	Consola::gotoxy(posxTitulo, posyTitulo);
	cout << "PARABENS VENCEDORES" << endl;
	Consola::gotoxy(posxTitulo, posyTitulo+2);
	cout << n1;
	Consola::gotoxy(posxTitulo, posyTitulo + 3);
	cout << n2;
	Consola::gotoxy(posxTitulo, posyTitulo + 4);
	cout << n3;
	getchar();
}

int Interface::imprimePista(string nome, int tam, int numMaxEquipa, int posx, int posy)
{
	Consola::gotoxy(40, 5);

	Consola::setBackgroundColor(corFundoComando);
	Consola::setTextColor(corTextoComando);

	cout << "AUTODROMO " << nome;

	Consola::setBackgroundColor(corFundoPrincipal);
	Consola::setTextColor(corTexto);

	Consola::setTextColor(Consola::PRETO);

	int posyInicial = posy;
	for (int i = 0; i <= numMaxEquipa; i++) {
		Consola::gotoxy(posx, posy);
		for (int i = 0; i < tam - 1; i++)
			cout << "_";
		posy = posy + 5;
	}
	cout << endl;

	for (int i = 1; i < (numMaxEquipa * 5) + 1; i++) {
		Consola::gotoxy(9 + tam, posyInicial + i);
		Consola::setBackgroundColor(Consola::BRANCO_CLARO);
		cout << " ";
	}
	Consola::setBackgroundColor(corFundoPrincipal);
	Consola::setTextColor(corTexto);
	return posy;
	
}

void Interface::imprimeComando(int posx, int posy) {


	Consola::setBackgroundColor(corFundoComando);
	Consola::setTextColor(corTextoComando);
	Consola::gotoxy(posx, posy);
	cout << "COMANDO:";
	Consola::setBackgroundColor(corFundoPrincipal);
	Consola::gotoxy(posx + 10, posy);
	cout << "                                         ";
	Consola::setTextColor(corTexto);
	Consola::gotoxy(posx + 10, posy);

}

void Interface::processaComando() {
	string comando;

	simulador->carregaA("autodromos.txt");
	simulador->carregaC("carros.txt");
	simulador->carregaP("pilotos.txt");

	simulador->entraNoCarro('a', "Bruno");
	simulador->entraNoCarro('b', "Kuku");
	simulador->entraNoCarro('c', "Junior");
	simulador->criaC("Mercedes", 20, 20, 4);


	string auxC = "", letraT = "", nomeP = "", nomeA = "", marca = "", modelo = "", nomeF, tipoP;
	double enrg = 0, maxE = 0;
	int velM = 0, dim=0, maxEquipa=0, tempo=0, posy = posyComando ;
	char idC = '0';
	vector<string> log;

	bool sair = false;


	while (!sair) {
		auxC = ""; letraT = "";  nomeP = ""; nomeA = ""; marca = ""; modelo = ""; nomeF = "", tipoP= "";
		enrg = 0; maxE = 0;
		velM = 0; dim = 0; maxEquipa = 0; tempo = 0;
	    idC = '0';
		vector<string> nomeAutodromos;
		
		if (modo1) {
			telaInicio();
			imprimeComando(posxComando,posyComando);
		}else {
			posy = visualizador();
			imprimeComando(posxComando, posy);
		}
		
		cin.clear();


		getline(cin, comando);
		log.push_back(comando);
		stringstream iss(comando);
		iss >> auxC;


		if (auxC == "cria") {
			iss >> letraT;
			if (letraT == "c") {
				iss >> marca;
				iss >> enrg;
				iss >> maxE;
				iss >> velM;
				iss >> modelo;
				if (velM != 0) {
					simulador->criaC(marca, enrg, maxE, velM, modelo);

				}

			}
			else if (letraT == "p") {
				iss >> tipoP;
				iss >> nomeP;
				if (nomeP != "") {
					simulador->criaP(nomeP, tipoP);

				}

			}
			else if (letraT == "a") {
				iss >> nomeA;
				iss >> dim;
				iss >> maxEquipa;
				if (maxEquipa != 0) {
					simulador->criaA(nomeA, dim, maxEquipa);

				}
			}

		}else if (auxC == "apaga") {
			iss >> letraT;
			if (letraT == "c") {
				iss >> idC;
				simulador->apagaC(idC);

			}
			else if (letraT == "p") {
				iss >> nomeP;
				simulador->apagaP(nomeP);

			}
		}
		else if (auxC == "entranocarro") {
			iss >> idC;
			iss >> nomeP;
			simulador->entraNoCarro(idC, nomeP);

		}
		else if (auxC == "saidocarro") {
			iss >> idC;
			simulador->saiDoCarro(idC);

		}
		else if (auxC == "lista") {
			Consola::clrscr();
			
			Consola::gotoxy(0, 5);
	
			if (simulador->lista() != "") {
				cout << simulador->lista();
				getchar();
			}
		}
		else if (auxC == "carregaP") {
			iss >> nomeF;
			if (nomeF != "")
				simulador->carregaP(nomeF);
		}
		else if (auxC == "carregaC") {
			iss >> nomeF;
			if (nomeF != "")
				simulador->carregaC(nomeF);
		}
		else if (auxC == "carregaA") {
			iss >> nomeF;
			if (nomeF != "")
				simulador->carregaA(nomeF);
		}
		else if (auxC == "campeonato") {
			while (iss>>nomeA) {
				nomeAutodromos.push_back(nomeA);
				nomeA = "";
			}
			if(nomeAutodromos.size()!=0)
				if (simulador->camp(nomeAutodromos))
					modo1 = false;
		}
		else if (auxC == "listacarros") {
			Consola::clrscr();

			Consola::gotoxy(0, 5);

			if (simulador->listaCarros() != "") {
				cout << simulador->listaCarros();
				getchar();
			}
		}else if (auxC == "carregabat") {
			iss << idC;
			iss << enrg;
			if (enrg != 0)
				simulador->carregabat(idC, enrg);
		}else if (auxC == "carregatudo") {
			simulador->carregatudo();
		}else if (auxC == "corrida") {
			simulador->corrida();

		}
		else if (auxC == "acidente") {
			iss >> idC;
			simulador->acidente(idC);
		}
		else if (auxC == "stop") {
			iss >> nomeP;
			simulador->stop(nomeP);
		}
		else if (auxC == "destroi") {
			iss >> idC;
			simulador->destroi(idC);
		}
		else if (auxC == "passatempo") {
		vector <string> auxS;
			iss >> tempo;
			if (!simulador->passaTempo(tempo)) {
				auxS = simulador->getVencedores();
				if (auxS.size() >= 3)
					imprimeVencedores(auxS.at(0), auxS.at(1), auxS.at(2));
				else if(auxS.size() == 2)
					imprimeVencedores(auxS.at(0), auxS.at(1), "NA");
				else if(auxS.size() == 1)
					imprimeVencedores(auxS.at(0), "NA", "NA");
				else
					imprimeVencedores("NA", "NA", "NA");
				modo1 = true;
			}
		}
		else if (auxC == "log") {
			Consola::clrscr();

			Consola::gotoxy(0, 5);
			cout << "\t\t\t\t\t\tLOG" << endl;
			for (string a : log)
				cout << "\t\t" << a << endl;
			getchar();
		}






		else if (auxC == "sair")
			sair = true;


	}
}