#ifndef SWIAT_H
#define SWIAT_H
#include "Organizm.h"
#include <string>


class Organizm;
class Swiat
{
private:
	std::string opis;
	int button;
	int N, M;
	void DodajOrganizm(Organizm* nowy);
	void TworzPlansze();
protected:
	Organizm* organizmy;
	Organizm*** plansza;
public:
	void SaveSwiat();
	void LoadSwiat();
	Organizm* GetOrganizmy();
	void SetOrganizmy(Organizm* nowyPoczatek);
	Organizm* GetOrganizmZPlanszy(int newX, int newY);
	void SetOrganizmZPlanszy(int newX, int newY, Organizm* nowy);
	int GetN();
	int GetM();
	int GetButton();
	void SetButton( int newButton);
	Swiat();
	void wykonajTure();
	void rysujSwiat();
	~Swiat();
};
#endif