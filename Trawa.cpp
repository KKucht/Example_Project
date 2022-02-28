#include "Trawa.h"
#include <string>

Organizm* Trawa::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Trawa(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Trawa::Nazwa(std::string& opis) {
    opis += "Trawa";
}

Trawa::Trawa(Swiat* swiat, int x, int y) : Roslina(swiat, x, y) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y, Organizm* pre) : Roslina(swiat, x, y, pre) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Roslina(swiat, x, y, pre, nxt) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y, int rundyMlodosci) : Roslina(swiat, x, y, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Roslina(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Trawa::Trawa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Roslina(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

char Trawa::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'T';
    }
    else {
        return 't';
    }
}
