#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Wilk(Swiat* swiat, int x, int y);
	Wilk(Swiat* swiat, int x, int y, Organizm* pre);
	Wilk(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Wilk(Swiat* swiat, int x, int y, int rundyMlodosci);
	Wilk(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Wilk(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
};

