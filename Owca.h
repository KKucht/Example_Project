#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
public:
	Owca(Swiat* swiat, int x, int y);
	Owca(Swiat* swiat, int x, int y, Organizm* pre);
	Owca(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Owca(Swiat* swiat, int x, int y, int rundyMlodosci);
	Owca(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Owca(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
};

