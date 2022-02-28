#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Lis(Swiat* swiat, int x, int y);
	Lis(Swiat* swiat, int x, int y, Organizm* pre);
	Lis(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Lis(Swiat* swiat, int x, int y, int rundyMlodosci);
	Lis(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Lis(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual void Akcja(std::string& opis) override;
};

