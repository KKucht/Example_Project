#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Trawa(Swiat* swiat, int x, int y);
	Trawa(Swiat* swiat, int x, int y, Organizm* pre);
	Trawa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Trawa(Swiat* swiat, int x, int y, int rundyMlodosci);
	Trawa(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Trawa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
};

