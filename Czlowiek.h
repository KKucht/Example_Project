#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze
{
protected:
	virtual Organizm* NowyOrganizm(int newX, int newY) override;
	virtual void Nazwa(std::string& opis) override;
	void TarczaAlzura(int newX, int newY, std::string& opis);
public:
	Czlowiek(Swiat* swiat, int x, int y);
	Czlowiek(Swiat* swiat, int x, int y, Organizm* pre);
	Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Czlowiek(Swiat* swiat, int x, int y, int rundyMlodosci);
	Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
	Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
	virtual char Rysowanie() override;
	virtual bool Obrona(int newX, int newY, std::string& opis) override;
	virtual void Akcja(std::string& opis) override;
};