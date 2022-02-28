#include "Mlecz.h"
#include <string>

Organizm* Mlecz::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Mlecz(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Mlecz::Nazwa(std::string& opis) {
    opis += "Mlecz";
}

Mlecz::Mlecz(Swiat* swiat, int x, int y) : Roslina(swiat, x, y) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Mlecz::Mlecz(Swiat* swiat, int x, int y, Organizm* pre) : Roslina(swiat, x, y, pre) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Mlecz::Mlecz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Roslina(swiat, x, y, pre, nxt) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Mlecz::Mlecz(Swiat* swiat, int x, int y, int rundyMlodosci) : Roslina(swiat, x, y, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Mlecz::Mlecz(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Roslina(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Mlecz::Mlecz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Roslina(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

char Mlecz::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'M';
    }
    else {
        return 'm';
    }
}

void Mlecz::Akcja(std::string& opis) {
    Nazwa(opis);
    int iloscNowychRoslin = 0;
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + "): ";
    for (int i = 0; i < 3; i++) {
        if (rand() % 7 == 0 && dojrzalosc == 0) {
            iloscNowychRoslin += Rozprzestrzeniaj(opis);
        }
    }
    Nazwa(opis);
    if (iloscNowychRoslin > 0) {
        opis += " rozsial " + std::to_string(iloscNowychRoslin) + " roslin.";
    }
    else {
        opis += " nie rozprzestrzenia sie.";
    }
}
