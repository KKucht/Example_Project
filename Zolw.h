#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Zolw(Swiat* swiat, int x, int y);
	Zolw(Swiat* swiat, int x, int y, Organizm* pre);
	Zolw(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Zolw(Swiat* swiat, int x, int y, int rundyMlodosci);
	Zolw(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Zolw(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
	virtual void Akcja(std::string& opis) override;
};

