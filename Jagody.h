#pragma once
#include "Roslina.h"
class Jagody : public Roslina
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Jagody(Swiat* swiat, int x, int y);
	Jagody(Swiat* swiat, int x, int y, Organizm* pre);
	Jagody(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Jagody(Swiat* swiat, int x, int y, int rundyMlodosci);
	Jagody(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Jagody(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
};

