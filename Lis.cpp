#include "Lis.h"
#include <iostream>
#include <string>

Organizm* Lis::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Lis(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Lis::Nazwa(std::string& opis) {
    opis += "Lis";
}

Lis::Lis(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y) {
    this->sila = 3;
    this->inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    this->sila = 3;
    this->inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    this->sila = 3;
    this->inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 3;
    this->inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 3;
    this->inicjatywa = 7;
}

Lis::Lis(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 3;
    this->inicjatywa = 7;
}

char Lis::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'L';
    }
    else {
        return 'l';
    }
}

void Lis::Akcja(std::string& opis) {
    Nazwa(opis);
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + ") z sila " + std::to_string(sila);
    int newX = 0, newY = 0;
    int dX, dY;
    bool* mozliwosci = Mozliwosci();
    while (true) {
        dX = rand() % 3 - 1;
        dY = rand() % 3 - 1;
        if (dX != 0 || dY != 0) {
            if (mozliwosci[0]) {
                if (dX == -1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->sila >= this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[0] = false;
                    }
                }
            }
            if (mozliwosci[1]) {
                if (dX == 0 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->sila >= this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[1] = false;
                    }
                }
            }
            if (mozliwosci[2]) {
                if (dX == 1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->sila >= this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[2] = false;
                    }
                }
            }
            if (mozliwosci[7]) {
                if (dX == -1 && dY == 0) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[7] = false;
                    }
                }
            }
            if (mozliwosci[3]) {
                if (dX == 1 && dY == 0) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[3] = false;
                    }
                }
            }
            if (mozliwosci[6]) {
                if (dX == -1 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[6] = false;
                    }
                }
            }
            if (mozliwosci[5]) {
                if (dX == 0 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)) || this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[5] = false;
                    }
                }
            }
            if (mozliwosci[4]) {
                if (dX == 1 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x+dX,y+dY)) || this->sila >= this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->GetSila() ||
                        this->swiat->GetOrganizmZPlanszy(x + dX, y + dY)->Rysowanie() == 'L') {
                        break;
                    }
                    else {
                        mozliwosci[4] = false;
                    }
                }
            }
            bool koniec = true;
            for (int i = 0; i < 8; i++) {
                if (mozliwosci[i]) {
                    koniec = false;
                    break;
                }
            }
            if (koniec) {
                opis += " pozostal w miejscu.";
                delete[] mozliwosci;
                return;
            }
        }
    }
    delete[] mozliwosci;
    newX = x + dX;
    newY = y + dY;
    if (!(this->swiat->GetOrganizmZPlanszy(newX, newY))) {
        opis += "wszedl na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        this->x = newX;
        this->y = newY;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
    }
    else if (this->sila >= this->swiat->GetOrganizmZPlanszy(newX,newY)->GetSila()){
        Kolizja(newX, newY, opis);
    }
}
