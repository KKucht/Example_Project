#ifndef ORGANIZM_H
#define ORGANIZM_H
#include "Swiat.h"
#include <string>

class Swiat;


class Organizm
{
protected:
	Swiat* swiat;
	int x, y;
	int inicjatywa;
	int dojrzalosc;
	int sila;
	virtual void Kolizja(int newX, int newY, std::string& opis) = 0;
	virtual Organizm* NowyOrganizm(int newX, int newY) = 0;
	bool* Mozliwosci();
	Organizm* pre;
	Organizm* nxt;
	bool moc;
	int odliczanie;
public:
	int GetDojrzalosc();
	bool GetMoc();
	int GetOdliczanie();
	void SetMoc(bool nowaMoc);
	void SetOdliczanie(int noweOdliczanie);
	int GetX();
	int GetY();
	virtual void Nazwa(std::string& opis) = 0;
	Organizm(Swiat* swiat, int x, int y);
	Organizm(Swiat* swiat, int x, int y, Organizm* pre);
	Organizm(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
	Organizm* GetPre();
	Organizm* GetNxt();
	void SetX(int newX);
	void SetY(int newY);
	void SetPre(Organizm* nowyPre);
	void SetNxt(Organizm* nowyNxt);
	int GetInicjatywa();
	void SetInicjatywa(int nowaInicjatywa);
	int GetSila();
	void SetSila(int nowaSila);
	void Rosnij();
	virtual void Akcja(std::string& opis) = 0;
	virtual bool Obrona(int newX, int newY, std::string& opis) = 0;
	virtual char Rysowanie() = 0;
	~Organizm();
};

#endif // !ORGANIZM_H
