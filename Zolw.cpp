#include "Zolw.h"
#include <iostream>

Organizm* Zolw::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Zolw(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Zolw::Nazwa(std::string& opis) {
    opis += "Zolw";
}

Zolw::Zolw(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y) {
    this->sila = 2;
    this->inicjatywa = 1;
}

Zolw::Zolw(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    this->sila = 2;
    this->inicjatywa = 1;
}

Zolw::Zolw(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    this->sila = 2;
    this->inicjatywa = 1;
}

Zolw::Zolw(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 2;
    this->inicjatywa = 1;
}

Zolw::Zolw(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 2;
    this->inicjatywa = 1;
}

Zolw::Zolw(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 2;
    this->inicjatywa = 1;
}

char Zolw::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'Z';
    }
    else {
        return 'z';
    }
}

bool Zolw::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    if (this->sila > this->swiat->GetOrganizmZPlanszy(newX,newY)->GetSila() || this->swiat->GetOrganizmZPlanszy(newX, newY)->GetSila() < 5) {
        opis += " wybronil sie.";
        return false;
    }
    else {
        opis += " umarl.";
        this->inicjatywa = -1;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        return true;
    }
}

void Zolw::Akcja(std::string& opis) {
    Nazwa(opis);
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + ") z sila " + std::to_string(sila);
    if (rand()%4 == 0) {
        int newX, newY;
        while (true) {
            int dX, dY;
            dX = rand() % 3 - 1;
            dY = rand() % 3 - 1;
            if (!(dX == 0 && dY == 0)) {
                newX = this->x + dX;
                newY = this->y + dY;
                if (newX != -1 && newY != -1 && newX != this->swiat->GetN() && newY != this->swiat->GetM()) {
                    break;
                }
            }
        }
        if (!(this->swiat->GetOrganizmZPlanszy(newX,newY))) {
            opis += "wszedl na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
            this->x = newX;
            this->y = newY;
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
        }
        else {
            Kolizja(newX, newY, opis);
        }
    }
    else {
        opis += " pozostal na miejscu.";
    }
}
