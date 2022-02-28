#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
private:
	void Ucieczka(std::string& opis);
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
	virtual void Kolizja(int newX, int newY, std::string& opis) override;
public:
	Antylopa(Swiat* swiat, int x, int y);
	Antylopa(Swiat* swiat, int x, int y, Organizm* pre);
	Antylopa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Antylopa(Swiat* swiat, int x, int y, int rundyMlodosci);
	Antylopa(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Antylopa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
	virtual void Akcja(std::string& opis) override;
};

