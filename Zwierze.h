#pragma once
#include "Organizm.h"


class Zwierze : public Organizm
{
private:
    void Rodzic(int newX, int newY);
protected:
    void Parowanie(int newX, int newY, std::string& opis);
    virtual void Kolizja(int newX, int newY, std::string& opis) override;
public:
    Zwierze(Swiat* swiat, int x, int y);
    Zwierze(Swiat* swiat, int x, int y, Organizm* pre);
    Zwierze(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt);
    Zwierze(Swiat* swiat, int x, int y, int rundyMlodosci);
    Zwierze(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci);
    Zwierze(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci);
    virtual bool Obrona(int newX, int newY, std::string& opis) override;
    virtual void Akcja(std::string& opis) override;
};

