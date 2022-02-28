#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Mlecz(Swiat* swiat, int x, int y);
	Mlecz(Swiat* swiat, int x, int y, Organizm* pre);
	Mlecz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Mlecz(Swiat* swiat, int x, int y, int rundyMlodosci);
	Mlecz(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Mlecz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual void Akcja(std::string& opis) override;
};

