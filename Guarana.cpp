#include "Guarana.h"
#include <string>

Organizm* Guarana::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Guarana(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Guarana::Nazwa(std::string& opis) {
    opis += "Guarana";
}

Guarana::Guarana(Swiat* swiat, int x, int y) : Roslina(swiat, x, y) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y, Organizm* pre) : Roslina(swiat, x, y, pre) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Roslina(swiat, x, y, pre, nxt) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y, int rundyMlodosci) : Roslina(swiat, x, y, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Roslina(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Guarana::Guarana(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Roslina(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

char Guarana::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'G';
    }
    else {
        return 'g';
    }
}

bool Guarana::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    opis += " zostala zjedzona, zwieksza sile zwierzecia.";
    Organizm* tmp = this->swiat->GetOrganizmZPlanszy(newX, newY);
    tmp->SetSila(tmp->GetSila()+3);
    this->inicjatywa = -1;
    this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
    return true;
}
