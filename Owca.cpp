#include "Owca.h"
#include <string>

Organizm* Owca::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Owca(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Owca::Nazwa(std::string& opis) {
    opis += "Owca";
}

Owca::Owca(Swiat* swiat, int x, int y) : Zwierze(swiat,x,y) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Owca::Owca(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

char Owca::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'O';
    }
    else {
        return 'o';
    }
}
