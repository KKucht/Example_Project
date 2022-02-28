#include "Barszcz.h"
#include <string>

void Barszcz::Zabijaj(int dX, int dY, std::string& opis) {
    if (x + dX != -1 && x + dX != this->swiat->GetN() && y + dY != -1 && y + dY != this->swiat->GetM()) {
        Organizm* tmp = this->swiat->GetOrganizmZPlanszy(x + dX,y + dY);
        if (tmp) {
            char a = tmp->Rysowanie();
            if (a != 'B' && a != 'b' && a != 'J' && a != 'j' && a != 'G' && a != 'g' &&
                a != 'M' && a != 'm' && a != 'T' && a != 't') {
                if (tmp->GetSila() < 10) {
                    this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Nazwa(opis);
                    opis += "(" + std::to_string(x + dX) + "," + std::to_string(y + dY) + ") zatrul sie i zdechl.";
                    tmp->SetInicjatywa(-1);
                    this->swiat->SetOrganizmZPlanszy(x + dX,y + dY, nullptr);
                }
            }
        }
    }
}

Organizm* Barszcz::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Barszcz(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Barszcz::Nazwa(std::string& opis) {
    opis += "Barszcz Sosnowski";
}

void Barszcz::Kolizja(int newX, int newY, std::string& opis) {
    Zabijaj(-1, 1, opis);
    Zabijaj(0, 1, opis);
    Zabijaj(1, 1, opis);
    Zabijaj(-1, 0, opis);
    Zabijaj(1, 0, opis);
    Zabijaj(-1, -1, opis);
    Zabijaj(0, -1, opis);
    Zabijaj(1, -1, opis);
}

Barszcz::Barszcz(Swiat* swiat, int x, int y) : Roslina(swiat, x, y) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Barszcz::Barszcz(Swiat* swiat, int x, int y, Organizm* pre) : Roslina(swiat, x, y, pre) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Barszcz::Barszcz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Roslina(swiat, x, y, pre, nxt) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Barszcz::Barszcz(Swiat* swiat, int x, int y, int rundyMlodosci) : Roslina(swiat, x, y, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Barszcz::Barszcz(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Roslina(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

Barszcz::Barszcz(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Roslina(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 0;
    this->inicjatywa = 0;
}

char Barszcz::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'B';
    }
    else {
        return 'b';
    }
}

bool Barszcz::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    this->inicjatywa = -1;
    this->swiat->SetOrganizmZPlanszy( this->x, this->y, nullptr);
    opis += " zostal zjedzony, zwierze sie zatrulo";
    if (this->swiat->GetOrganizmZPlanszy(newX,newY)->GetSila() > 10) {
        opis += ", ale przezylo.";
        return true;
    }
    else {
        opis += " i zdechlo.";
        this->swiat->GetOrganizmZPlanszy(newX, newY)->SetInicjatywa(-1);
        this->swiat->SetOrganizmZPlanszy(newX, newY, nullptr);
        return false;
    }
}

void Barszcz::Akcja(std::string& opis) {
    Nazwa(opis);
    int iloscNowychRoslin = 0;
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + "): ";
    if (rand() % 7 == 0 && dojrzalosc == 0) {
        iloscNowychRoslin += Rozprzestrzeniaj(opis);
    }
    Nazwa(opis);
    if (iloscNowychRoslin > 0) {
        opis += " rozsial " + std::to_string(iloscNowychRoslin) + " roslin.";
    }
    else {
        opis += " nie rozprzestrzenia sie.";
    }
    Kolizja(0, 0, opis);
}
