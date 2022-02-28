#include "Zwierze.h"
#include <iostream>


void Zwierze::Rodzic(int newX, int newY) {
    Organizm* nowy = NowyOrganizm(newX, newY);
    Organizm* tmp = this;
    while (tmp->GetNxt() != nullptr) {
        if (tmp->GetNxt()->GetInicjatywa() == -1) {
            Organizm* tmp_nxt = tmp->GetNxt()->GetNxt();
            delete tmp->GetNxt();
            tmp->SetNxt(tmp_nxt);
            if (tmp_nxt != nullptr) {
                tmp_nxt->SetPre(tmp);
            }
        }
        else if (tmp->GetNxt()->GetInicjatywa() < this->inicjatywa) {
            break;
        }
        else {
            tmp = tmp->GetNxt();
        }
    }
    Organizm* tmp_nxt = tmp->GetNxt();
    tmp->SetNxt(nowy);
    nowy->SetPre(tmp);
    nowy->SetNxt(tmp_nxt);
    if (tmp_nxt != nullptr) {
        tmp_nxt->SetPre(nowy);
    }
}

void Zwierze::Parowanie(int newX, int newY, std::string& opis) {
    bool* mozliwosci = Mozliwosci();
    int dX, dY;
    while (true) {
        dX = rand() % 3 - 1;
        dY = rand() % 3 - 1;
        if (dX != 0 || dY != 0) {
            if (mozliwosci[0]) {
                if (dX == -1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x+dX,y+dY))) {
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                        Rodzic(x + dX, y + dY);
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
                delete[] mozliwosci;
                return;
            }
        }
    }
    opis += " Urodzil sie nowy osobnik(" + std::to_string(x+dX) + "," + std::to_string(y+dY) + ").";
    delete[] mozliwosci;
}

void Zwierze::Kolizja(int newX, int newY, std::string& opis) {
    Organizm* tmp = this->swiat->GetOrganizmZPlanszy(newX,newY);
    opis += " spotkal ";
    tmp->Nazwa(opis);
    opis += "(" + std::to_string(newX) + "," + std::to_string(newY) + ")";
    char a = Rysowanie();
    char b = tmp->Rysowanie();
    if (a == b ) {
        if (dojrzalosc == 0) {
            Parowanie(newX, newY, opis);
        }
    }
    else if (a != b + ' ' && a + ' ' != b) {
        if (this->sila >= tmp->GetSila()) {
            if (this->swiat->GetOrganizmZPlanszy(newX,newY)->Obrona(this->x, this->y, opis)) {
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
                x = newX;
                y = newY;
                this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
            }
        }
        else {
            opis += " ";
            Nazwa(opis);
            opis += " umarl.";
            this->inicjatywa = -1;
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        }
    }
}

Zwierze::Zwierze(Swiat* swiat, int x, int y) : Organizm(swiat, x, y) {
    dojrzalosc = 5;
}

Zwierze::Zwierze(Swiat* swiat, int x, int y, Organizm* pre) : Organizm(swiat, x, y, pre) {
    dojrzalosc = 5;
}

Zwierze::Zwierze(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Organizm(swiat, x, y, pre, nxt) {
    dojrzalosc = 5;
}

Zwierze::Zwierze(Swiat* swiat, int x, int y, int rundyMlodosci) : Organizm(swiat, x, y) {
    dojrzalosc = rundyMlodosci;
}

Zwierze::Zwierze(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Organizm(swiat, x, y, pre) {
    dojrzalosc = rundyMlodosci;
}

Zwierze::Zwierze(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Organizm(swiat, x, y, pre, nxt) {
    dojrzalosc = rundyMlodosci;
}

bool Zwierze::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    if (this->sila > this->swiat->GetOrganizmZPlanszy(newX,newY)->GetSila()) {
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

void Zwierze::Akcja(std::string& opis) {
    Nazwa(opis);
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + ") z sila " + std::to_string(sila);
    int newX, newY;
    while (true) {
        int dX, dY;
        dX = rand() % 3 - 1;
        dY = rand() % 3 - 1;
        if (!(dX==0 && dY == 0)) {
            newX = this->x + dX;
            newY = this->y + dY;
            if (newX != -1 && newY != -1 && newX != this->swiat->GetN() && newY != this->swiat->GetM()) {
                break;
            }
        }
    }
    if (!(this->swiat->GetOrganizmZPlanszy(newX,newY))) {
        opis += " wszedl na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
        this->x = newX;
        this->y = newY;
        this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
    }
    else {
        Kolizja(newX, newY, opis);
    }
}


