#include "Wilk.h"
#include <string>

Organizm* Wilk::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Wilk(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX,newY,nowy);
    return nowy;
}

void Wilk::Nazwa(std::string& opis) {
    opis += "Wilk";
}

Wilk::Wilk(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y) {
    this->sila = 9;
    this->inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    this->sila = 9;
    this->inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    this->sila = 9;
    this->inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 9;
    this->inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 9;
    this->inicjatywa = 5;
}

Wilk::Wilk(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 9;
    this->inicjatywa = 5;
}

char Wilk::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'W';
    }
    else {
        return 'w';
    }
}
