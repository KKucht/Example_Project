#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
private:
    void Siej(int newX, int newY);
protected:
    int Rozprzestrzeniaj(std::string& opis);
    virtual void Kolizja(int newX, int newY, std::string& opis) override;
public:
    Roslina(Swiat* swiat, int x, int y);
    Roslina(Swiat* swiat, int x, int y, Organizm* pre);
    Roslina(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
    Roslina(Swiat* swiat, int x, int y, int rundyMlodosci);
    Roslina(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
    Roslina(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
    virtual bool Obrona(int newX, int newY, std::string& opis) override;
    virtual void Akcja(std::string& opis) override;
};

