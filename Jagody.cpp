#include "Jagody.h"
#include <string>

Organizm* Jagody::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Jagody(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Jagody::Nazwa(std::string& opis) {
    opis += "Wilcze Jagody";
}

Jagody::Jagody(Swiat* swiat, int x, int y) : Roslina(swiat, x, y) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Jagody::Jagody(Swiat* swiat, int x, int y, Organizm* pre) : Roslina(swiat, x, y, pre) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Jagody::Jagody(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Roslina(swiat, x, y, pre, nxt) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Jagody::Jagody(Swiat* swiat, int x, int y, int rundyMlodosci) : Roslina(swiat, x, y, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Jagody::Jagody(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Roslina(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Jagody::Jagody(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Roslina(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

char Jagody::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'J';
    }
    else {
        return 'j';
    }
}

bool Jagody::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    this->inicjatywa = -1;
    this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
    opis += " zostal zjedzony, zwierze sie zatrulo";
    if (this->swiat->GetOrganizmZPlanszy(newX, newY)->GetSila() > 99) {
        opis += ", ale przezylo.";
        return true;
    }
    else {
        opis += " i zdechlo.";
        this->swiat->GetOrganizmZPlanszy(newX,newY)->SetInicjatywa(-1);
        this->swiat->SetOrganizmZPlanszy(newX, newY, nullptr);
        return false;
    }
}