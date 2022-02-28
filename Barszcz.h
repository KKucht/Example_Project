#pragma once
#include "Roslina.h"
class Barszcz : public Roslina
{
private:
	void Zabijaj(int dX, int dY, std::string& opis);
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
	virtual void Kolizja(int newX, int newY, std::string& opis) override;
public:
	Barszcz(Swiat* swiat, int x, int y);
	Barszcz(Swiat* swiat, int x, int y, Organizm* pre);
	Barszcz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Barszcz(Swiat* swiat, int x, int y, int rundyMlodosci);
	Barszcz(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Barszcz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
	virtual void Akcja(std::string& opis) override;
};

