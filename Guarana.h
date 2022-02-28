#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Guarana(Swiat* swiat, int x, int y);
	Guarana(Swiat* swiat, int x, int y, Organizm* pre);
	Guarana(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Guarana(Swiat* swiat, int x, int y, int rundyMlodosci);
	Guarana(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Guarana(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
};

