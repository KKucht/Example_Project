#include "Roslina.h"


void Roslina::Siej(int newX, int newY) {
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
    nowy->SetNxt(tmp_nxt) ;
    if (tmp_nxt != nullptr) {
        tmp_nxt->SetPre(nowy);
    }
}

int Roslina::Rozprzestrzeniaj(std::string& opis) {
    bool* mozliwosci = Mozliwosci();
    int dX, dY;
    while (true) {
        dX = rand() % 3 - 1;
        dY = rand() % 3 - 1;
        if (dX != 0 || dY != 0) {
            if (mozliwosci[0]) {
                if (dX == -1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                        Siej(x + dX, y + dY);
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
                return 0;
            }
        }
    }
    opis += " Rosnie nowa roslina(" + std::to_string(x + dX) + "," + std::to_string(y + dY) + ").";
    delete[] mozliwosci;
    return 1;
}

void Roslina::Kolizja(int newX, int newY, std::string& opis) {
    opis += "co tu robisz?";
}

Roslina::Roslina(Swiat* swiat, int x, int y) : Organizm(swiat, x, y) {
    dojrzalosc = 2;
}

Roslina::Roslina(Swiat* swiat, int x, int y, Organizm* pre) : Organizm(swiat, x, y, pre) {
    dojrzalosc = 2;
}

Roslina::Roslina(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Organizm(swiat, x, y, pre, nxt) {
    dojrzalosc = 2;
}

Roslina::Roslina(Swiat* swiat, int x, int y, int rundyMlodosci) : Organizm(swiat, x, y) {
    dojrzalosc = rundyMlodosci;
}

Roslina::Roslina(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Organizm(swiat, x, y, pre) {
    dojrzalosc = rundyMlodosci;
}

Roslina::Roslina(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Organizm(swiat, x, y, pre, nxt) {
    dojrzalosc = rundyMlodosci;
}

bool Roslina::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    opis += " zostal zjedzony";
    this->inicjatywa = -1;
    this->swiat->SetOrganizmZPlanszy(this->x,this->y,nullptr);
    return true;
}

void Roslina::Akcja(std::string& opis) {
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
}