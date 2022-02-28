#include "Swiat.h"
#include "Zwierze.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Czlowiek.h"
#include <string>
#include <iostream>
#include <fstream>



void Swiat::DodajOrganizm(Organizm* nowy) {
	if (!(organizmy)) {
		organizmy = nowy;
	}
	else if(organizmy->GetInicjatywa() < nowy->GetInicjatywa()){
		organizmy->SetPre(nowy);
		nowy->SetNxt(organizmy);
		organizmy = nowy;
	}
	else {
		Organizm* tmp = organizmy;
		while (tmp->GetNxt()) {
			if (tmp->GetNxt()->GetInicjatywa() < nowy->GetInicjatywa()) {
				break;
			}
			tmp = tmp->GetNxt();
		}
		if (!(tmp->GetNxt())) {
			tmp->SetNxt(nowy);
			nowy->SetPre(tmp);
		}
		else{
			tmp->GetNxt()->SetPre(nowy);
			nowy->SetNxt(tmp->GetNxt());
			tmp->SetNxt(nowy);
			nowy->SetPre(tmp);
		}
	}
	int newX, newY;
	while (true) {
		newX = rand() % N;
		newY = rand() % M;
		if (!(plansza[newX][newY])) {
			plansza[newX][newY] = nowy;
			nowy->SetX(newX);
			nowy->SetY(newY);
			break;
		}
	}
}

void Swiat::TworzPlansze() {
	int liczbaMozliwychStworzen = N * M / 5;
	int liczbaObecnychStworzen = 1;
	Organizm* tmp = new Czlowiek(this, 0, 0, 0);
	DodajOrganizm(tmp);
	int losowanie = 0;
	while (liczbaMozliwychStworzen > liczbaObecnychStworzen) {
		losowanie = rand() % 100;
		
		//if (losowanie >= 0 && losowanie <= 14) { //15%
		//	tmp = new Owca(this, 0, 0, 0);
		//}
		//else if (losowanie >= 15 && losowanie <= 19) { //5%
		//	tmp = new Wilk(this, 0, 0, 0);
		//}
		//else if (losowanie >= 20 && losowanie <= 28) { //9%
		//	tmp = new Lis(this, 0, 0, 0);
		//}
		//else if (losowanie >= 29 && losowanie <= 40) { //12%
		//	tmp = new Zolw(this, 0, 0, 0);
		//}
		//else if (losowanie >= 41 && losowanie <= 53) { //13%
		//	tmp = new Antylopa(this, 0, 0, 0);
		//}
		//else if (losowanie >= 54 && losowanie <= 71) { //18%
		//	tmp = new Trawa(this, 0, 0, 0);
		//}
		//else if (losowanie >= 72 && losowanie <= 78) { //7%
		//	tmp = new Mlecz(this, 0, 0, 0);
		//}
		//else if (losowanie >= 79 && losowanie <= 88) { //10%
		//	tmp = new Guarana(this, 0, 0, 0);
		//}
		//else if (losowanie >= 89 && losowanie <= 94) { //6%
		//	tmp = new Jagody(this, 0, 0, 0);
		//}
		//else if (losowanie >= 95 && losowanie <= 99) { //5%
		//	tmp = new Barszcz(this, 0, 0, 0);
		//}

		if (losowanie >= 0 && losowanie <= 16) { //17%
			tmp = new Owca(this, 0, 0, 0);
		}
		else if (losowanie >= 17 && losowanie <= 26) { //10%
			tmp = new Wilk(this, 0, 0, 0);
		}
		else if (losowanie >= 27 && losowanie <= 41) { //15%
			tmp = new Lis(this, 0, 0, 0);
		}
		else if (losowanie >= 42 && losowanie <= 56) { //15%
			tmp = new Zolw(this, 0, 0, 0);
		}
		else if (losowanie >= 57 && losowanie <= 71) { //15%
			tmp = new Antylopa(this, 0, 0, 0);
		}
		else if (losowanie >= 72 && losowanie <= 89) { //18%
			tmp = new Trawa(this, 0, 0, 0);
		}
		else if (losowanie >= 90 && losowanie <= 91) { //2%
			tmp = new Mlecz(this, 0, 0, 0);
		}
		else if (losowanie >= 92 && losowanie <= 96) { //5%
			tmp = new Guarana(this, 0, 0, 0);
		}
		else if (losowanie >= 97 && losowanie <= 97) { //1%
			tmp = new Jagody(this, 0, 0, 0);
		}
		else if (losowanie >= 98 && losowanie <= 99) { //2%
			tmp = new Barszcz(this, 0, 0, 0);
		}

		DodajOrganizm(tmp);
		liczbaObecnychStworzen++;
	}
}

void Swiat::SaveSwiat() {
	std::ofstream file;
	file.open("save.txt");
	file << "SAVE_SMALL_WORLD_SIMULATION\n";
	file << N << " " << M << std::endl;
	Organizm* tmp = organizmy;
	file << tmp->Rysowanie() << " " << tmp->GetSila() << " " << tmp->GetX() << " " << tmp->GetY() << " " << tmp->GetDojrzalosc() << "\n" ;
	while (tmp->GetNxt() != nullptr) {
		tmp = tmp->GetNxt();
		if (tmp->Rysowanie() == 'C') {
			file << tmp->Rysowanie() << " " << tmp->GetSila() << " " << tmp->GetX() << " " << tmp->GetY() <<
				" " << tmp->GetDojrzalosc() << " " << tmp->GetMoc() << " " << tmp->GetOdliczanie() << "\n";
		}
		else {
			file << tmp->Rysowanie() << " " << tmp->GetSila() << " " << tmp->GetX() << " " << tmp->GetY() << " " << tmp->GetDojrzalosc() << "\n";
		}
	}
	file.close();
}

void Swiat::LoadSwiat() {
	std::ifstream file;
	file.open("save.txt");
	if (file) {
		std::string tekst = "";
		file >> tekst;
		if (tekst == "SAVE_SMALL_WORLD_SIMULATION") {
			int newN, newM;
			file >> newN >> newM;
			char znak;
			int sila, x, y, dojrzalosc, moc=0, odliczanie=0;
			Organizm* tmp_pre = nullptr;
			Organizm* tmp_nxt = nullptr;
			Organizm* nowyPoczatek = nullptr;
			Organizm*** nowaPlansza = nullptr;

			nowaPlansza = new Organizm * *[newN];
			for (int i = 0; i < newN; i++) {
				nowaPlansza[i] = new Organizm * [newM];
			}
			for (int i = 0; i < newN; i++) {
				for (int j = 0; j < newM; j++) {
					nowaPlansza[i][j] = nullptr;
				}
			}

			while (file >> znak) {
				file >> sila >> x >> y >> dojrzalosc;
				if (znak == 'C' || znak == 'c') {
					file >> moc >> odliczanie;
				}
				if (znak == 'W' || znak == 'w') {
					tmp_nxt = new Wilk(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak =='O' || znak == 'o') {
					tmp_nxt = new Owca(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'L' || znak == 'l') {
					tmp_nxt = new Lis(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'Z' || znak == 'z') {
					tmp_nxt = new Zolw(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'A' || znak == 'a') {
					tmp_nxt = new Antylopa(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'T' || znak == 't') {
					tmp_nxt = new Trawa(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'M' || znak == 'm') {
					tmp_nxt = new Mlecz(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'G' || znak == 'g') {
					tmp_nxt = new Guarana(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'J' || znak == 'j') {
					tmp_nxt = new Jagody(this, x, y, tmp_pre, dojrzalosc);
					if (tmp_pre) {
						tmp_pre->SetNxt(tmp_nxt);
					}
					else {
						nowyPoczatek = tmp_nxt;
					}
					nowaPlansza[x][y] = tmp_nxt;
					tmp_pre = tmp_nxt;
					tmp_nxt = nullptr;
				}
				else if (znak == 'b' || znak == 'B') {
				tmp_nxt = new Barszcz(this, x, y, tmp_pre, dojrzalosc);
				if (tmp_pre) {
					tmp_pre->SetNxt(tmp_nxt);
				}
				else {
					nowyPoczatek = tmp_nxt;
				}
				nowaPlansza[x][y] = tmp_nxt;
				tmp_pre = tmp_nxt;
				tmp_nxt = nullptr;
				}
				else if (znak == 'C' || znak == 'c') {
				tmp_nxt = new Czlowiek(this, x, y, tmp_pre, dojrzalosc);
				tmp_nxt->SetMoc(moc);
				tmp_nxt->SetOdliczanie(odliczanie);
				if (tmp_pre) {
					tmp_pre->SetNxt(tmp_nxt);
				}
				else {
					nowyPoczatek = tmp_nxt;
				}
				nowaPlansza[x][y] = tmp_nxt;
				tmp_pre = tmp_nxt;
				tmp_nxt = nullptr;
				}
			}
			while (organizmy) {
				delete organizmy;
			}
			organizmy = nowyPoczatek;
			for (int i = 0; i < N; i++) {
				delete[] plansza[i];
			}
			delete[] plansza;
			plansza = nowaPlansza;
			opis = "load\n";
			N = newN;
			M = newM;
			rysujSwiat();
		}
		else {
			std::cout << "\nLOAD ERROR\n";
		}
	}
	else {
		std::cout << "\nOPEN ERROR\n";
	}
	
}

Organizm* Swiat::GetOrganizmy() {
	return organizmy;
}

void Swiat::SetOrganizmy(Organizm* nowyPoczatek) {
	organizmy = nowyPoczatek;
}

Organizm* Swiat::GetOrganizmZPlanszy(int newX, int newY) {
	if (newX > -1 && newX < N && newY>-1 && newY < M) {
		return plansza[newX][newY];
	}
	else {
		return nullptr;
	}
}

void Swiat::SetOrganizmZPlanszy(int newX, int newY, Organizm* nowy) {
	if (newX > -1 && newX < N && newY>-1 && newY < M) {
		plansza[newX][newY] = nowy;
	}
}

int Swiat::GetN() {
	return N;
}

int Swiat::GetM() {
	return M;
}

int Swiat::GetButton() {
	return button;
}
void Swiat::SetButton(int newButton) {
	button = newButton;
}

Swiat::Swiat() {
	N = 0, M = 0;
	opis = "start\n";
	organizmy = nullptr;
	std::cout << "Wpisz N: ";
	while (true) {
		std::cin >> N;
		if (N > 4 && N < 101) {
			break;
		}
		else {
			std::cout << "Musi byæ wiêksze od 5 do 100 Wpisz N: ";
		}
	}
	std::cout << "Wpisz M: ";
	while (true) {
		std::cin >> M;
		if (M > 4 && M < 101) {
			break;
		}
		else {
			std::cout << "Musi byæ wiêksze od 5 do 100 Wpisz M: ";
		}
	}
	plansza = new Organizm**[N];
	for (int i = 0; i < N; i++) {
		plansza[i] = new Organizm* [M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			plansza[i][j] = nullptr;
		}
	}

	TworzPlansze();

	/*organizmy = new Czlowiek(this, 0, 0, 0);
	plansza[0][0] = organizmy;
	organizmy->SetNxt(new Wilk(this, 10, 10, organizmy, 0));
	plansza[10][10] = organizmy->GetNxt();
	organizmy->GetNxt()->SetNxt(new Wilk(this, 0, 10, organizmy->GetNxt(), 0));
	plansza[0][10] = organizmy->GetNxt()->GetNxt();
	organizmy->GetNxt()->GetNxt()->SetNxt(new Wilk(this, 10, 0, organizmy->GetNxt()->GetNxt(), 0));
	plansza[10][0] = organizmy->GetNxt()->GetNxt()->GetNxt();
	organizmy->GetNxt()->GetNxt()->GetNxt()->SetNxt(new Wilk(this, 5, 5, organizmy->GetNxt()->GetNxt()->GetNxt(), 0));
	plansza[5][5] = organizmy->GetNxt()->GetNxt()->GetNxt()->GetNxt();*/
}

void Swiat::wykonajTure() {
	if (this->organizmy) {
		Organizm* tmp = organizmy;
		while (tmp != nullptr) {
			if (tmp->GetInicjatywa() == -1) {
				Organizm* tmp_nxt = tmp->GetNxt();
				delete tmp;
				tmp = tmp_nxt;
			}
			else {
				tmp->Akcja(opis);
				opis += "\n";
				tmp = tmp->GetNxt();
			}
		}
	}
}

void Swiat::rysujSwiat() {
	system("CLS");
	std::cout << "Krzysztof Kuchta 184568" << std::endl;
	std::cout << opis;
	opis.clear();
	opis = "";
	std::cout << '*';
	for (int i = 0; i < N ; i++) {
		std::cout << '-';
	}
	std::cout << '*' << std::endl;
	for (int i = 0 ; i < M; i++) {
		std::cout << '|';
		for (int j = 0; j < N; j++) {
			if (plansza[j][i] != nullptr) {
				std::cout << plansza[j][i]->Rysowanie();
				plansza[j][i]->Rosnij();
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << '|' << std::endl;
	}
	std::cout << '*';
	for (int i = 0; i < N; i++) {
		std::cout << '-';
	}
	std::cout << '*' << std::endl;
}

Swiat::~Swiat() {
	while (organizmy) {
		delete organizmy;
	}
}