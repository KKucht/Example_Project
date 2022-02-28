#include "Antylopa.h"
#include <iostream>
#include <string>

void Antylopa::Ucieczka(std::string& opis) {
    if (rand() % 2 == 0) {
        int dX, dY;
        bool* mozliwosci = Mozliwosci();
        while (true) {
            dX = rand() % 3 - 1;
            dY = rand() % 3 - 1;
            if (dX != 0 || dY != 0) {
                if (mozliwosci[0]) {
                    if (dX == -1 && dY == 1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[0] = false;
                        }
                    }
                }
                if (mozliwosci[1]) {
                    if (dX == 0 && dY == 1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[1] = false;
                        }
                    }
                }
                if (mozliwosci[2]) {
                    if (dX == 1 && dY == 1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[2] = false;
                        }
                    }
                }
                if (mozliwosci[7]) {
                    if (dX == -1 && dY == 0) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[7] = false;
                        }
                    }
                }
                if (mozliwosci[3]) {
                    if (dX == 1 && dY == 0) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[3] = false;
                        }
                    }
                }
                if (mozliwosci[6]) {
                    if (dX == -1 && dY == -1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[6] = false;
                        }
                    }
                }
                if (mozliwosci[5]) {
                    if (dX == 0 && dY == -1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                            break;
                        }
                        else {
                            mozliwosci[5] = false;
                        }
                    }
                }
                if (mozliwosci[4]) {
                    if (dX == 1 && dY == -1) {
                        if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
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
                    opis += " umarla.";
                    delete[] mozliwosci;
                    this->inicjatywa = -1;
                    this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
                    return;
                }
            }
        }
        delete[] mozliwosci;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        this->x = this->x + dX;
        this->y = this->y + dY;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
        opis += " uciekl na (" + std::to_string(x) + "," + std::to_string(y) + ").";
    }
    else {
        opis += " umarla.";
        this->inicjatywa = -1;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
    }
}

Organizm* Antylopa::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Antylopa(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nowy);
    return nowy;
}

void Antylopa::Nazwa(std::string& opis) {
    opis += "Antylopa";
}

void Antylopa::Kolizja(int newX, int newY, std::string& opis) {
    Organizm* tmp = this->swiat->GetOrganizmZPlanszy(newX , newY);
    opis += " spotkal ";
    tmp->Nazwa(opis);
    opis += "(" + std::to_string(newX) + "," + std::to_string(newY) + ")";
    char a = Rysowanie();
    char b = tmp->Rysowanie();
    if (a == b) {
        if (dojrzalosc == 0) {
            Parowanie(newX, newY, opis);
        }
    }
    else if (a != b + ' ' && a + ' ' != b) {
        if (this->sila >= tmp->GetSila()) {
            if (this->swiat->GetOrganizmZPlanszy( newX, newY)->Obrona(this->x, this->y, opis)) {
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
                x = newX;
                y = newY;
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
            }
        }
        else {
            opis += " ";
            Nazwa(opis);
            Ucieczka(opis);
        }
    }
}

Antylopa::Antylopa(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Antylopa::Antylopa(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Antylopa::Antylopa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Antylopa::Antylopa(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Antylopa::Antylopa(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

Antylopa::Antylopa(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 4;
    this->inicjatywa = 4;
}

char Antylopa::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'A';
    }
    else {
        return 'a';
    }
}

bool Antylopa::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    if (this->sila > this->swiat->GetOrganizmZPlanszy(newX,newY)->GetSila()) {
        opis += " wybronil sie.";
        return false;
    }
    else {
        Ucieczka(opis);
        return true;
    }
}

void Antylopa::Akcja(std::string& opis) {
    Nazwa(opis);
    opis += "(" + std::to_string(x) + "," + std::to_string(y) + ") z sila " + std::to_string(sila);
    int newX, newY;
    int dX, dY;
    while (true) {
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
    if (!(this->swiat->GetOrganizmZPlanszy( newX, newY))) {
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        this->x = newX;
        this->y = newY;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
        opis += " ruszyl sie na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
        newX += dX;
        newY += dY;
        if (newX != -1 && newY != -1 && newX != this->swiat->GetN() && newY != this->swiat->GetM()) {
            if (!(this->swiat->GetOrganizmZPlanszy(newX, newY))) {
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
                this->x = newX;
                this->y = newY;
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
                opis += " Ponownie ruszyl sie na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
            }
            else {
                Kolizja(newX, newY, opis);
            }
        }
    }
    else {
        Kolizja(newX, newY, opis);
    }
}